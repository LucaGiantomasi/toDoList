#include <iostream>
#include <cctype>
#include "Element.h"
#include "ListElement.h"

using namespace std;
int main() {
    ListElement lista;
    string nome, currentList;
    list<Element>::iterator el;
    int scelta = -1;
    do{
        cout << "0. Esci\n"
                "1. Aggiungi nuova lista\n"
                "2. Cambia lista\n"
                "3. Elimina questa lista\n"
                "4. Leggi la lista\n"
                "5. Aggiungi un elemento alla lista\n"
                "6. Elimina un elemento della lista\n"
                "7. Completa/Decompleta un elemento\n"
                "8. Modifica il nome di un elemento\n"
                "9. Salva la lista su un file\n"
                "10. Carica la lista da un file\n"
                "Lista attuale: " + (lista.getCurrentListName().empty()?"Nessuna" : lista.getCurrentListName()) << endl;
        cin >> scelta;
        cin.ignore();
        switch (scelta){
            case 1:
                cout << "Inserire il nome della nuova lista" << endl;
                getline(cin, currentList);
                if(!currentList.empty())
                    lista.addList(currentList);
                break;
            case 2:
                cout << "Inserire il nome della lista" << endl;
                getline(cin, currentList);
                lista.changeList(currentList);
                if(lista.getCurrentListName() != currentList)
                    cout << "Lista inesistente" << endl;
                break;
            case 3:
                if(!lista.getCurrentListName().empty())
                    lista.removeList();
                else
                    cout << "Nessuna lista selezionata" << endl;
                break;
            case 4:
                try{
                    for(const auto& elem : lista.getElements())
                        cout << elem.toString() << endl;
                }catch(std::out_of_range& ex){
                    cout << "Nessuna lista selezionata" << endl;
                }
                break;
            case 5:
                if( !lista.getCurrentListName().empty()) {
                    cout << "Scrivi il nome dell'elemento da aggiungere" << endl;
                    getline(cin, nome);
                    lista.addElement(Element(nome));
                }
                else
                    cout << "Nessuna lista selezionata" << endl;
                break;
            case 6:
                if(!lista.getCurrentListName().empty()) {
                    cout << "Scrivi il nome dell'elemento da eliminare" << endl;
                    getline(cin, nome);
                    el = lista.find(nome);
                    if (el != lista.getElements().end()) {
                        lista.removeElement(*el);
                    } else
                        cout << "Elemento non trovato" << endl;
                }
                else
                    cout << "Nessuna lista selezionata" << endl;
                break;
            case 7:
                if(!lista.getCurrentListName().empty()) {
                    cout << "Scrivi il nome dell'elemento da completare/decompletare" << endl;
                    getline(cin, nome);
                    el = lista.find(nome);
                    if (el != lista.getElements().end())
                        el->toggle();
                    else
                        cout << "Elemento non trovato" << endl;
                }
                else
                    cout << "Nessuna lista selezionata" << endl;
                break;
            case 8:
                if(!lista.getCurrentListName().empty()) {
                    cout << "Scrivi il nome dell'elemento da modificare" << endl;
                    getline(cin, nome);
                    el = lista.find(nome);
                    if (el != lista.getElements().end()) {
                        string newName;
                        cout << "Scrivi il nuovo nome dell'elemento" << endl;
                        getline(cin, newName);
                        auto elem = lista.find(newName);
                        if (elem == lista.getElements().end())
                            el->setName(newName);
                        else
                            cout << "Il nuovo nome scelto è già esistente" << endl;
                    } else
                        cout << "Elemento non trovato" << endl;
                }
                else
                    cout << "Nessuna lista selezionata" << endl;
                break;
            case 9:
                if(!lista.getCurrentListName().empty())
                    lista.writeToFile();
                else
                    cout << "Nessuna lista selezionata" << endl;
                break;
            case 10:
                cout << "Inserire nome del file da cui caricare la lista" << endl;
                cin >> nome;
                lista.loadFromFile(nome);
                break;
            default:
                break;
        }
    }while(scelta != 0);
    return 0;
}
