//
// Created by lucag on 08/08/2018.
//

#include "ListElement.h"

ListElement::ListElement() : completed(false) {}

bool ListElement::isCompleted() const {
    return completed;
}

void ListElement::setCompleted(bool completed) {
    ListElement::completed = completed;
}

void ListElement::addElement(const Element &el) {
    elements.push_back(el);
}

void ListElement::removeElement(const Element &el) {
    elements.remove(el);
}

const list<Element> &ListElement::getElements() const {
    return elements;
}

Element& ListElement::find(string name) const {
    for (const auto &el : elements) {
        if(el.getName() == name)
           return const_cast<Element&>(el);
    }
}
