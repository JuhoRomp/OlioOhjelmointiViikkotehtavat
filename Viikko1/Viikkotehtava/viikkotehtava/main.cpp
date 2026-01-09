#include <iostream>
#include <cstdlib>  // rand, srand
#include <ctime>    // time


using namespace std;
int game(int maxnum);

int main()
{
    srand(time(0));
    int x = game(40);
    cout<<x<<endl;
    return 0;
}

int game(int maxnum){
    int arvottuluku = rand()%maxnum+1;
    int arvaus;
    int montakoArvausta=0;
    do{
        montakoArvausta++;
        cout << "Arvaa!" << endl;
        cin>>arvaus;
        if(arvaus>arvottuluku){
            cout << "liian suuri" << endl;

        } else if (arvaus<arvottuluku){
            cout << "liian pieni" << endl;

        } else {
            cout << "oikein" << endl;

        }
    } while(arvaus!=arvottuluku);
    return montakoArvausta;

}
