//
// Created by lucag on 28/08/2018.
//

#include <gtest/gtest.h>
#include "../Element.h"

TEST(ElementTest, ConstuctorTest){
    Element e("Testing");
    EXPECT_EQ(e.getName(), "Testing");
    EXPECT_EQ(e.isChecked(), false);
    EXPECT_EQ(e.getDateTime(), "");
}

TEST(ElementTest, NameTest){
    Element e;
    e.setName("TestingName");
    EXPECT_EQ(e.getName(), "TestingName");
}

TEST(ElementTest, CheckedTest){
    Element e;
    e.setChecked(true);
    EXPECT_EQ(e.isChecked(), true);
}

TEST(ElementTest, DateTimeTest){
    Element e;
    e.setDateTime("15/09/2015");
    EXPECT_EQ(e.getDateTime(), "15/09/2015");
}

TEST(ElementTest, ToggleTest){
    Element e("Testing");
    e.toggle();
    EXPECT_EQ(e.isChecked(), true);
}

TEST(ElementTest, OperatorEqualTest){
    Element e1("Giorgio");
    Element e2("Giorgio");
    EXPECT_EQ(e1 == e2, true);
    e2.toggle();
    EXPECT_EQ(e1 == e2, true);
    e2.setName("Paolo");
    EXPECT_EQ(e1 == e2, false);
}