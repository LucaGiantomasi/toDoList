//
// Created by lucag on 08/08/2018.
//

#include "ListElement.h"

void ListElement::addList(const string& listName) {
    lists[listName] = list<Element>();
    currentList = listName;
}

void ListElement::removeList() {
    lists.erase(currentList);
    currentList = "";
}

const string& ListElement::getCurrentListName() const {
    return currentList;
}

void ListElement::changeList(const string &currentList) {
    if (lists.find(currentList) != lists.end())
        ListElement::currentList = currentList;
}

void ListElement::addElement(const Element &el) {
    lists.at(currentList).push_back(el);
}

void ListElement::removeElement(const Element &el) {
    lists.at(currentList).remove(el);
}

const list<Element>& ListElement::getElements() const {
    return lists.at(currentList);
}

list<Element>::iterator ListElement::find(string name) {
    return std::find(lists[currentList].begin(), lists[currentList].end(), Element(name));
}

void ListElement::loadFromFile(string fileName) {
    ifstream inputFile("../assets/" + fileName + ".txt");
    if(inputFile.good()){
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
    if(lists.at(currentList).empty())
        return;
    ofstream outputFile("../assets/" + currentList + ".txt");
    if(outputFile.is_open()){
        for(const auto& el : lists[currentList]){
            outputFile << el.toString() << endl;
        }
    }
    else
        cerr << "Impossibile aprire il file" << endl;
}
