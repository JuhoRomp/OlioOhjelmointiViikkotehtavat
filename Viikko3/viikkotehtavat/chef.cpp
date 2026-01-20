#include <iostream>
#include "chef.h"
#include <string>
using namespace std;

Chef::Chef(string name) : chefName(name) {
    cout<<"Chef "<<name<< " Constructor"<<endl;
    makeSalad(11);
    makeSoup(14);

}

Chef::~Chef(){
    cout<<"Chef "<<chefName<< " Destructor"<<endl;
}

string Chef::getName(){
    cout<<"Palautetaan kokin nimi "<<chefName<<endl;
    return chefName;
}

int Chef::makeSalad(int maara){
    cout<<"Chef "<<chefName<<" luo "<<maara<<" maaralla aineksia "<<maara/5<<" annosta salaattia"<<endl;
    return maara/5;
}

int Chef::makeSoup(int maara){
    cout<<"Chef "<<chefName<<" luo "<<maara<<" maaralla aineksia "<<maara/3<<" annosta keittoa"<<endl;
    return maara/3;
}
