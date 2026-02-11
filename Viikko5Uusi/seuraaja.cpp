#include "seuraaja.h"
#include <iostream>
using namespace std;

Seuraaja::Seuraaja(string name): nimi(name) {

}

string Seuraaja::getNimi(){
    return nimi;
}

void Seuraaja::paivitys(string post){
    cout<<"Seuraaja "<< nimi << " sai viestin "<<post<<endl;
}


