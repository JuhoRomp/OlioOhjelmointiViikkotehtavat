#include <iostream>
#include "game.h"
using namespace std;

int main()
{
    {
        Game gameOlio(40);
        gameOlio.play();
    }
    cout << "Press enter to exit...!" << endl;
    cin.get();
    return 0;
}
