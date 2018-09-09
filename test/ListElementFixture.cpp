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

TEST_F(ListElementSuite, OtherListTest){
    list.addList("SecondList");
    EXPECT_EQ(list.getCurrentListName(), "SecondList");
    list.addElement(Element("SecondListElement"));
    EXPECT_FALSE(list.getElements().empty());
    list.changeList("UnitTest");
    EXPECT_NE(list.find("Test1"), list.getElements().end());
    list.changeList("NonexistentList");
    EXPECT_NE(list.getCurrentListName(), "NonexistentList");
    list.changeList("SecondList");
    list.writeToFile();
    list.removeList();
    EXPECT_THROW(list.getElements(), std::out_of_range);
    list.loadFromFile("SecondList");
    EXPECT_NE(list.find("SecondListElement"), list.getElements().end());
}

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