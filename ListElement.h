//
// Created by lucag on 08/08/2018.
//

#ifndef TODOLIST_LISTELEMENT_H
#define TODOLIST_LISTELEMENT_H

#include <list>
#include "Element.h"

using namespace std;
class ListElement {
public:

    void addElement(const Element& el);

    void removeElement(const Element& el);

    const list<Element> &getElements() const;

    list<Element>::iterator find(string name);

private:
    list<Element> elements;
};


#endif //TODOLIST_LISTELEMENT_H
