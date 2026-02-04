#include <stdio.h>
#include "notifikaattori.h"
#include "seuraaja.h"

int main()
{
  Notifikaattori n;
  Seuraaja a("A");
  Seuraaja b("B");
  Seuraaja c("C");

  n.lisaa(&a);
  n.lisaa(&b);
  n.lisaa(&c);
  n.tulosta();

    return 0;
}
