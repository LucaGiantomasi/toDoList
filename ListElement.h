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
    ListElement();

    bool isCompleted() const;

    void setCompleted(bool completed);

    void addElement(const Element& el);

    void removeElement(const Element& el);

    const list<Element> &getElements() const;

    Element& find(string name) const;

private:
    list<Element> elements;
    bool completed; //true se tutti i suoi elementi sono checked
};


#endif //TODOLIST_LISTELEMENT_H
