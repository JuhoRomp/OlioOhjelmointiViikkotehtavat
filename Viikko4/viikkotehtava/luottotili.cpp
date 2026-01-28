#include "luottotili.h"
#include "pankkitili.h"
#include <iostream>
using namespace std;

Luottotili::Luottotili(string o, double lr)
    : Pankkitili(o)
{
    luottoraja = lr;
    cout<<"Luottotili luotu "<< o<< ":lle, luottoraja "<<lr <<endl;
}

bool Luottotili::deposit(double luottoMaksu) {
    if (saldo >= 0) {
        cout<<"Luottotili: luottovelkaa ei ole"<< endl;
        return false;
    }

    if (luottoMaksu <= 0) {
        cout<<"Luottotili: maksu ei voi olla 0 tai negatiivinen" <<endl;
        return false;
    }

    double velka = -saldo;

    if (luottoMaksu >= velka) {
        cout<<"Luottotili: luottovelka maksettu kokonaan. Maksettu: "<< velka<< endl;
        saldo = 0;
    } else {
        saldo += luottoMaksu;
        cout<< "Luottotili: luottovelkaa maksettu: "<<luottoMaksu<< ", velkaa jaljella: " <<-saldo<< endl;
    }

    return true;
}

bool Luottotili::withdraw(double nosto) {
    if (nosto <= 0) {
        cout<<"Luottotili: nosto ei voi olla 0 tai negatiivinen"<<endl;
        return false;
    }

    double uusiSaldo = saldo - nosto;
    double uusiVelka = -uusiSaldo;

    if (uusiVelka > luottoraja) {
        cout<< "Luottotili: et saa ottaa luottoa yli luottorajan"<<endl;
        return false;
    }

    saldo = uusiSaldo;
    cout<<"Luottotili: nosto "<<nosto<< " tehty, luottoa jaljella "<<(luottoraja - (-saldo)) <<endl;
    return true;
}
