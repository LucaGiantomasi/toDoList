//
// Created by lucag on 31/08/2018.
//

#include <gtest/gtest.h>
#include "../Element.h"
#include "../ListElement.h"

class ListElementSuite : public ::testing::Test {

protected:
    virtual void SetUp(){
        Element element("Test1");
        element.toggle();
        list.addList("UnitTest");
        list.addElement(element);
        list.addElement(Element("Test2"));
    }

    ListElement list;
};

TEST_F(ListElementSuite, IOTest){
    auto el = list.find("Test1");
    ASSERT_NE(el, list.getElements().end());

    list.writeToFile();
    list.removeList();
    list.loadFromFile("UnitTest");
    el = list.find("Test1");
    ASSERT_NE(el, list.getElements().end());
    EXPECT_TRUE(el->isChecked());
    EXPECT_NE(el->getDateTime(), "");

    el = list.find("Test2");
    ASSERT_NE(el, list.getElements().end());
    EXPECT_EQ(el->getDateTime(), "");

    list.removeElement(*el);
    list.addElement(Element("Test3"));
    list.writeToFile();
    list.removeList();
    list.loadFromFile("UnitTest");
    el = list.find("Test2");
    ASSERT_EQ(el, list.getElements().end());
    el = list.find("Test3");
    ASSERT_NE(el, list.getElements().end());
    EXPECT_FALSE(el->isChecked());
}

TEST_F(ListElementSuite, TestAltraLista){
    list.addList("SecondList");
    EXPECT_EQ(list.getCurrentListName(), "SecondList") << "CurrentList è stato aggiornato";
    EXPECT_NO_THROW(list.getElements()) << "La lista è stata creata";

    list.addElement(Element("SecondListElement"));
    EXPECT_FALSE(list.getElements().empty()) << "La lista non è vuota, quindi l'elemento è stato aggiunto";

    list.changeList("UnitTest");
    EXPECT_NE(list.find("Test1"), list.getElements().end()) << "Cambiando lista gli elementi rimangono intatti";

    list.changeList("SecondList");
    list.writeToFile();

    list.removeList();
    EXPECT_THROW(list.getElements(), std::out_of_range) << "La lista è stata rimossa";

    list.loadFromFile("SecondList");
    EXPECT_NE(list.find("SecondListElement"), list.getElements().end());
}

TEST_F(ListElementSuite, TestOperazioniNonEseguibili){
    list.changeList("ListaInesistente");
    EXPECT_NE(list.getCurrentListName(), "ListaInesistente") << "Cambiare su una lista inesistente non produce nessun risultato";

    EXPECT_EQ(list.find("Elemento Non Esistente"), list.getElements().end()) << "La ricerca di un elemento inesitente non dà risultati";

    list.removeList();
    EXPECT_THROW(list.getElements(), std::out_of_range) << "Quando non c'è nessuna lista non si può accedere alla lista degli elementi";

    auto el = list.find("Lista Non Esistente");
    EXPECT_EQ(el, list.getElements().end()) << "La ricerca in una lista corrente inesistente non dà risultati";

    list.writeToFile();
    ifstream outputFile("../assets/.txt");
    EXPECT_FALSE(outputFile) << "Non si può salvare un file se la lista corrente non esiste";
}