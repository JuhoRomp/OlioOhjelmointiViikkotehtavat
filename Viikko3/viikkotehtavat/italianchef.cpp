#include <iostream>
#include "italianchef.h"
#include <string>
using namespace std;
#include "chef.h"

ItalianChef::ItalianChef(string name) : Chef(name) {
     cout<<"ItalianChef "<<name<<" Constructor"<<endl;
}


ItalianChef::~ItalianChef(){
    cout<<"ItalianChef "<<chefName<< " Destructor"<<endl;
}

bool ItalianChef:: askSecret(string secret, int flour, int water){
    if (password==secret){
        cout<<"Secret is ok!"<<endl;

        makepizza(flour, water);
        return true;
    } else {
        cout<<"Secret is wrong!"<<endl;
        return false;
    }
}

int ItalianChef::makepizza(int flour, int water){
    if(flour<water){
        cout<<"ItalianChef "<<chefName<<" luo "<<flour<<" maaralla jauhoja ja "<<water<<" maaralla vetta "<<flour/5<<" pitsaa"<<endl;

        return flour/5;
    } else {
        cout<<"ItalianChef "<<chefName<<" luo "<<flour<<" maaralla jauhoja ja "<<water<<" maaralla vetta "<<water/5<<" pitsaa"<<endl;

        return water/5;
    }
}
