#include <iostream>
#include "asiakas.h"
using namespace std;

int main()
{
    {
        Asiakas mina("Juho", 50);
        mina.talletus(300);
        Asiakas kaveri("Jarkko", 100);
        kaveri.talletus(400);
        mina.showSaldo();
        kaveri.showSaldo();
        mina.tilisiirto(200, kaveri);
        mina.showSaldo();
        kaveri.showSaldo();
    }
    cout << "Press enter to exit...!" << endl;
    cin.get();
    return 0;
}
