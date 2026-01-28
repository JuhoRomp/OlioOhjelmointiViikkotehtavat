#include "asiakas.h"
#include <iostream>

using namespace std;

Asiakas::Asiakas(string o, double lr)
    : kayttotili(o),
    luottotili(o, lr)
{
    // Minun piti siirtää pankkitilin luomisen logi tänne, koska luottotili peri pankkitilin,
    // jonka vuoksi  logi tulostui sekä asiakaskonstruktorissa sekä luottotilin konstruktorissa
    cout<<"Pankkitili luotu "<<o <<":lle" <<endl;

    nimi = o;
    cout <<"Asiakas luotu "<<nimi<< endl;
}

void Asiakas::showSaldo() {
    cout<< nimi << endl;
    cout<< "Kayttotilin saldo "<<kayttotili.getBalance()<< endl;
    cout <<"Luottotilin saldo " <<luottotili.getBalance()<< endl;
}

bool Asiakas::talletus(double summa) {
    cout<< "Pankkitili: " <<nimi << " tallettaa "<< summa << endl;
    bool ok = kayttotili.deposit(summa);
    return ok;
}

bool Asiakas::nosto(double summa) {
    cout<< "Pankkitili: "<< nimi <<" nostaa " << summa<<endl;
    bool ok = kayttotili.withdraw(summa);
    return ok;
}

bool Asiakas::luotonMaksu(double summa) {
    cout<< "Luottotili: " <<nimi << " maksaa luottoa " <<summa << endl;
    bool ok = luottotili.deposit(summa);
    return ok;
}

bool Asiakas::luotonNosto(double summa) {
    cout << "Luottotili: " << nimi << " nostaa luottoa "<< summa <<endl;
    bool ok = luottotili.withdraw(summa);
    return ok;
}

string Asiakas::getNimi() {
    return nimi;
}

bool Asiakas::tilisiirto(double summa, Asiakas& vastaanottaja) {
    cout<<"Pankkitili: "<< nimi << " siirtaa " << summa<<" " << vastaanottaja.nimi <<":lle" <<endl;

    bool okNosto = kayttotili.withdraw(summa);
    if (!okNosto) {
        cout <<"Tilisiirto epaonnistui: nostoa ei saatu tehtya"<< endl;
        return false;
    }

    bool okTalletus = vastaanottaja.kayttotili.deposit(summa);
    if (okTalletus) {
        cout<< "Tilisiirto onnistui."<< endl;
    } else {
        cout<<"Tilisiirto epaonnistui: vastaanottajan talletus ei onnistunut"<<endl;
    }
    return okTalletus;
}
