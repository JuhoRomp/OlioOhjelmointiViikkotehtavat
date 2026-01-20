#include <iostream>
#include "italianchef.h"
using namespace std;

int main()
{
    {
    ItalianChef italiankokki("Pentti");
    italiankokki.askSecret("pizza", 6,10);
    }
    cout << "Press enter to exit...!" << endl;
    cin.get();
    return 0;
}
