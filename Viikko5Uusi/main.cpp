#include <stdio.h>
#include <iostream>
#include "notifikaattori.h"
#include "seuraaja.h"
using namespace std;

int main()
{


    {
        Notifikaattori n;
        Seuraaja a("A");
        Seuraaja b("B");
        Seuraaja c("C");

        n.lisaa(&a);
        n.lisaa(&b);
        n.lisaa(&c);


        n.poista(&a);
        n.tulosta();
        n.postita("Tama on viesti 1");
    }
    cout << "Press enter to exit...!" << endl;
    cin.get();

    return 0;
}
