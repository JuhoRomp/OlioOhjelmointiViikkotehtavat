#include "seuraaja.h"
#include <iostream>

Seuraaja::Seuraaja(string name): nimi=name {

}

string Seuraaja::getNimi(){
    return nimi;
}

void päivitys(string post){
    cout<<post<<endl;
}


