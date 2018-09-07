//
// Created by lucag on 08/08/2018.
//

#ifndef TODOLIST_LISTELEMENT_H
#define TODOLIST_LISTELEMENT_H

#include <map>
#include <list>
#include <cstring>
#include <vector>
#include <fstream>
#include "Element.h"

using namespace std;
class ListElement {
public:

    void addElement(const Element& el);

    void removeElement(const Element& el);

    const list<Element> &getElements() const;

    list<Element>::iterator find(string name);

    const string &getCurrentList() const;

    void setCurrentList(const string &currentList);

    void loadFromFile(string fileName);

    void writeToFile();

    void addList(string listName);

    void removeList();

private:
    map<string, list<Element>> elements;
    string currentList;
};


#endif //TODOLIST_LISTELEMENT_H
