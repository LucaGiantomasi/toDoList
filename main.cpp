#include <iostream>
#include "Element.h"
#include "ListElement.h"
#include <algorithm>

using namespace std;
int main() {
    Element e1("Test1");
    Element e2("Test2");
    ListElement l1;
    l1.addElement(e1);
    l1.addElement(e2);
    l1.find("Test2").setChecked(true);
    l1.removeElement(l1.find("Test1"));
    for(const auto el : l1.getElements())
        cout << el.toString() << endl;
    return 0;
}