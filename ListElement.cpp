//
// Created by lucag on 08/08/2018.
//

#include "ListElement.h"

void ListElement::addElement(const Element &el) {
    elements.at(currentList).push_back(el);
}

void ListElement::removeElement(const Element &el) {
    elements.at(currentList).remove(el);
}

const list<Element> &ListElement::getElements() const {
    return elements.at(currentList);
}

list<Element>::iterator ListElement::find(string name) {
    auto it = elements[currentList].begin();
    for(it; it != elements[currentList].end(); it++){
        if(it->getName() == name)
            break;
    }
    return it;
}

const string &ListElement::getCurrentList() const {
    return currentList;
}

void ListElement::setCurrentList(const string &currentList) {
    if (elements.find(currentList) != elements.end())
        ListElement::currentList = currentList;
}

void ListElement::loadFromFile(string fileName) {
    ifstream inputFile("../assets/" + fileName + ".txt");
    if(inputFile.is_open()){
        string str;
        Element e;
        vector<char*> pch;
        addList(fileName);
        while(getline(inputFile, str)){
            pch.clear();
            pch.push_back(strtok (const_cast<char*>(str.c_str()),"|"));
            while (auto test = strtok (nullptr, "|"))
            {
                pch.push_back(test);
            }
            e = Element(pch[0]);
            if(pch.size() > 1){
                e.setChecked(true);
                e.setDateTime(pch[2]);
            }
            addElement(e);
        }
    }
    else
        cerr << "Impossibile aprire il file" << endl;
}

void ListElement::writeToFile() {
    ofstream outputFile("../assets/" + currentList + ".txt");
    if(outputFile.is_open()){
        for(const auto& el : elements[currentList]){
            outputFile << el.toString() << endl;
        }
    }
    else
        cerr << "Impossibile aprire il file" << endl;
}

void ListElement::addList(string listName) {
    elements[listName] = list<Element>();
    currentList = listName;
}

void ListElement::removeList() {
    elements.erase(currentList);
    currentList = "";
}
