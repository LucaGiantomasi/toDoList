//
// Created by lucag on 08/08/2018.
//

#include "ListElement.h"

void ListElement::addElement(const Element &el) {
    elements.push_back(el);
}

void ListElement::removeElement(const Element &el) {
    elements.remove(el);
}

const list<Element> &ListElement::getElements() const {
    return elements;
}

list<Element>::iterator ListElement::find(string name) {
    auto it = elements.begin();
    for(it; it != elements.end(); it++){
        if(it->getName() == name)
            break;
    }
    return it;
}
