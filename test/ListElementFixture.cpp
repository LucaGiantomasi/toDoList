//
// Created by lucag on 31/08/2018.
//

#include <gtest/gtest.h>
#include "../Element.h"
#include "../ListElement.h"

class ListElementSuite : public ::testing::Test {

protected:
    virtual void setUp(){
        Element el("Test1");
        list.addElement(el);
    }

    ListElement list;
};

TEST_F(ListElementSuite, AddElementTest){
    Element el("Test2");
    el.setChecked(true);
    list.addElement(el);
    bool present = false;
    for(auto it = list.getElements().begin(); it != list.getElements().end(); it++){
        if(*it == el)
            present = true;
    }
    EXPECT_TRUE(present);
}