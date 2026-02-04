#include "notifikaattori.h"
#include "seuraaja.h"

Notifikaattori::Notifikaattori() {}

void Notifikaattori::poista(Seuraaja * follower){
    seuraajat = nullptr;

}
void Notifikaattori::lisaa(Seuraaja * uusi){
    if(uusi == nullptr) return;


    uusi->next = seuraajat;
    seuraajat = uusi;

}
void Notifikaattori::tulosta(){


}
void Notifikaattori::postita(Seuraaja * follower){


}
