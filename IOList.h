//
// Created by lucag on 09/08/2018.
//

#ifndef TODOLIST_IOLIST_H
#define TODOLIST_IOLIST_H

#include <iostream>
#include <fstream>
#include "ListElement.h"

using namespace std;
class IOList {
public:
    static ListElement loadFromFile(string fileName);

    static void writeToFile(ListElement list, string fileName);
};


#endif //TODOLIST_IOLIST_H
