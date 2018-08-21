#include <iostream>
#include "Element.h"
#include "ListElement.h"
#include "IOList.h"

using namespace std;
int main() {
    ListElement l;
    Element e;
    string nome, newName;
    list<Element>::iterator el;
    int scelta = -1;
    do{
        cout << "0. Esci\n"
                "1. Leggi la lista\n"
                "2. Aggiungi un elemento alla lista\n"
                "3. Elimina un elemento della lista\n"
                "4. Completa/Decompleta un elemento\n"
                "5. Modifica il nome di un elemento\n"
                "6. Salva la lista su un file\n"
                "7. Carica la lista da un file" << endl;
        cin >> scelta;
        cin.ignore();
        switch (scelta){
            //Leggi la lista
            case 1:
                for(const auto& elem : l.getElements())
                    cout << elem.toString() << endl;
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
                el = l.find(nome);
                if(el != l.getElements().end()){
                    l.removeElement(*el);
                    cout << "Elemento eliminato" << endl;
                }
                else
                    cout << "Elemento non trovato" << endl;
                break;
            //Completa un elemento
            case 4:
                cout << "Scrivi il nome dell'elemento da completare/decompletare" << endl;
                getline(cin, nome);
                el = l.find(nome);
                if(el != l.getElements().end())
                    el->toggle();
                else
                    cout << "Elemento non trovato" << endl;
                break;
            //Modifica un elemento
            case 5:
                cout << "Scrivi il nome dell'elemento da modificare" << endl;
                getline(cin, nome);
                el = l.find(nome);
                if(el != l.getElements().end()){
                    cout << "Scrivi il nuovo nome dell'elemento" << endl;
                    getline(cin, newName);
                    el->setName(newName);
                }
                else
                    cout << "Elemento non trovato" << endl;
                break;
            //Scrivi su file
            case 6:
                cout << "Inserire nome del file su cui scrivere" << endl;
                cin >> nome;
                IOList::writeToFile(l, nome);
                break;
            //Leggi da file
            case 7:
                cout << "Inserire nome del file da cui caricare la lista" << endl;
                cin >> nome;
                l = IOList::loadFromFile(nome);
                break;
            default:
                break;
        }
    }while(scelta != 0);
    return 0;
}
