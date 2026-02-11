#include "notifikaattori.h"
#include "seuraaja.h"
#include <iostream>
using namespace std;


Notifikaattori::Notifikaattori() {}

void Notifikaattori::poista(Seuraaja * follower){
    if (seuraajat == nullptr || follower == nullptr) return;
    if(seuraajat->getNimi()==follower->getNimi()){
        cout << "Poistetaan "<< follower->getNimi() << endl;
        seuraajat=seuraajat->next;
        return;
    }

    Seuraaja*cur = seuraajat;


    while (cur != nullptr && cur->next->getNimi() != follower->getNimi()) {
        cur = cur->next;
    }
    if(cur->next!=nullptr){
        cout << "Poistetaan "<< follower->getNimi() << endl;

        cur->next = cur->next->next;
    }


}
void Notifikaattori::lisaa(Seuraaja * uusi){
    if(uusi == nullptr) return;
    cout << "Lisataan "<< uusi->getNimi() << endl;
    uusi->next = seuraajat;
    seuraajat = uusi;
}

void Notifikaattori::tulosta() {
    Seuraaja* cur = seuraajat;   // aloita alusta

    while (cur != nullptr) {
        cout << cur->getNimi() << endl;
        cur = cur->next;
    }


}

void Notifikaattori::postita(string post) {
    cout<<"Notifikaattori postaa viestin "<<post<<endl;

    Seuraaja* cur = seuraajat;   // aloita alusta

    while (cur != nullptr) {
        cur->paivitys(post);
        cur = cur->next;
    }


}
