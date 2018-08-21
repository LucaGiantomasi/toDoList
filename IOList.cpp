//
// Created by lucag on 09/08/2018.
//

#include "IOList.h"

ListElement IOList::loadFromFile(string fileName) {
    ifstream inputFile("../assets/" + fileName + ".txt");
    ListElement list;
    if(inputFile.is_open()){
        string str;
        Element e;
        vector<char*> pch;
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
            list.addElement(e);
        }
    }
    else
        cerr << "Impossibile aprire il file" << endl;
    return list;
}

void IOList::writeToFile(ListElement list, string fileName) {
    ofstream outputFile("../assets/" + fileName + ".txt");
    if(outputFile.is_open()){
        for(const auto& el : list.getElements()){
            outputFile << el.toString() << endl;
        }
    }
    else
        cerr << "Impossibile aprire il file" << endl;
}
