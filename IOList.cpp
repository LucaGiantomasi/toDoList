//
// Created by lucag on 09/08/2018.
//

#include <cstring>
#include <vector>
#include "IOList.h"

ListElement IOList::loadFromFile(string fileName) {
    ifstream inputFile("../assets/" + fileName + ".txt");
    string str;
    Element e;
    ListElement list;
    int i = 0;
    vector<char*> pch;
    if(inputFile.is_open()){
        while(getline(inputFile, str)){
            pch.clear();
            pch.push_back(strtok (const_cast<char*>(str.c_str()),","));
            while (pch[i] != nullptr)
            {
                i++;
                pch.push_back(strtok (nullptr, ","));
            }
            e = Element(pch[0]);
            if(pch.size() > 1){
                e.setChecked(true);
                e.setDateTime(pch[2]);
            }
            list.addElement(e);
        }
    }
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
