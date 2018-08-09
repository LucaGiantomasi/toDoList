//
// Created by lucag on 08/08/2018.
//

#ifndef TODOLIST_ELEMENT_H
#define TODOLIST_ELEMENT_H

#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;
class Element {
public:
    Element(){}

    explicit Element(const string &name);

    const string &getName() const;

    void setName(const string &name);

    bool isChecked() const;

    void setChecked(bool checked);

    void toggle();

    const string &getDateTime() const;

    void setDateTime(const string &dateTime);

    const string toString() const;

    bool operator==(const Element &rhs) const;

    bool operator!=(const Element &rhs) const;

private:
    string name;
    bool checked;
    string dateTime; //Data e ora di quando è stato completato l'elemento
};


#endif //TODOLIST_ELEMENT_H
