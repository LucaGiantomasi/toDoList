#include <iostream>
#include "Element.h"
#include "ListElement.h"

using namespace std;
int main() {
    ListElement l;
    Element e;
    string nome, newName;
    int scelta = -1;
    do{
        cout << "0. Esci\n"
                "1. Leggi la lista\n"
                "2. Aggiungi un elemento alla lista\n"
                "3. Elimina un elemento della lista\n"
                "4. Completa/Decompleta un elemento\n"
                "5. Modifica il nome di un elemento" << endl;
        cin >> scelta;
        cin.ignore();
        switch (scelta){
            //Leggi la lista
            case 1:
                for(const auto& el : l.getElements())
                    cout << el.toString() << endl;
                break;
            //Aggiungi un elemento
            case 2:
                cout << "Scrivi il nome dell'elemento da aggiungere" << endl;
                getline(cin, nome);
                e = Element(nome);
                l.addElement(e);
                cout << "Elemento aggiunto" << endl;
                break;
            //Elimina un elemento
            case 3:
                cout << "Scrivi il nome dell'elemento da eliminare" << endl;
                getline(cin, nome);
                l.removeElement(l.find(nome));
                break;
            //Completa un elemento
            case 4:
                cout << "Scrivi il nome dell'elemento da completare/decompletare" << endl;
                getline(cin, nome);
                l.find(nome).toggle();
                break;
             //Modifica un elemento
            case 5:
                cout << "Scrivi il nome dell'elemento da modificare" << endl;
                getline(cin, nome);
                cout << "Scrivi il nuovo nome dell'elemento" << endl;
                getline(cin, newName);
                l.find(nome).setName(newName);
                break;
            default:
                break;
        }
    }while(scelta != 0);
    return 0;
}