//
// Created by lucag on 08/08/2018.
//

#include "Element.h"

Element::Element(const string &name) : name(name), checked(false), dateTime("") {}

const string &Element::getName() const {
    return name;
}

void Element::setName(const string &name) {
    Element::name = name;
}

bool Element::isChecked() const {
    return checked;
}

void Element::toggle() {
    setChecked(!checked);
    if(checked){
        auto t = time(nullptr);
        auto tm = *localtime(&t);
        ostringstream oss;
        oss << std::put_time(&tm, "%d/%m/%Y %H:%M");
        string str = oss.str();
        setDateTime(str);
    }
    else
        setDateTime("");
}

const string &Element::getDateTime() const {
    return dateTime;
}

void Element::setDateTime(const string &dateTime) {
    Element::dateTime = dateTime;
}

const string Element::toString() const {
    return name + "," + (checked?"TRUE,":"") + dateTime;
}

bool Element::operator==(const Element &rhs) const {
    return name == rhs.name;
}

bool Element::operator!=(const Element &rhs) const {
    return !(rhs == *this);
}

void Element::setChecked(bool checked) {
    Element::checked = checked;
}
