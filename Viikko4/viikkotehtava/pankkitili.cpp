#include "pankkitili.h"
#include <iostream>
using namespace std;


Pankkitili::Pankkitili(string o) {

    omistaja = o;

}


bool Pankkitili::deposit(double talletus){
    if(talletus>=0){
        saldo+=talletus;
        cout<<"Pankkitili: talletus " <<talletus <<" tehty" <<endl;
        return true;
    } else {
        cout<<"Pankkitili: talletus ei voi olla 0 tai negatiivinen"<< endl;
        return false;
    }
}

bool Pankkitili::withdraw(double nosto){
    if(nosto>0){
        if(saldo==0){
            cout<<"Pankkitili: Tililla ei ole rahaa"<<endl;
            return false;

        }

        if(nosto>=saldo){
            cout<< "Pankkitili: saldo oli "<< saldo<< ", nosto "<<saldo <<" tehty (tili tyhjaksi)"<<endl;
            saldo = 0;
            return true;
        } else {
            saldo -= nosto;
            cout<< "Pankkitili: nosto "<<nosto<< " tehty, saldo "<<saldo << endl;
            return true;
        }


    } else {
        cout<<"Pankkitili: Nosto ei voi olla negatiivinen tai 0"<<endl;
        return false;
    }
}

double Pankkitili::getBalance(){
    return saldo;
}
