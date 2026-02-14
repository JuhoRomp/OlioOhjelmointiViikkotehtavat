#include <iostream>
#include <vector>
#include "student.h"
#include <algorithm>
using namespace std;


int main ()
{
    int selection =0;
    vector<Student>studentList;

    do
    {
        cout<<endl;
        cout<<"Select"<<endl;
        cout<<"Add students = 0"<<endl;
        cout<<"Print all students = 1"<<endl;
        cout<<"Sort and print students according to Name = 2"<<endl;
        cout<<"Sort and print students according to Age = 3"<<endl;
        cout<<"Find and print student = 4"<<endl;
        cin>>selection;

        switch(selection)
        {
        case 0: {

            // Kysy käyttäjältä uuden opiskelijan nimi ja ikä
            string nimi;
            int ika;
            cout<<"Valitse opiskelijan nimi: ";
            cin>>nimi;
            cout<<endl;
            cout<<"Valitse opiskelijan ika: ";
            cin>>ika;
            cout<<endl;
            // Lisää uusi student StudentList vektoriin.
            Student s{nimi, ika};
            studentList.push_back(s);

            break;
        }
        case 1: {

            // Tulosta StudentList vektorin kaikkien opiskelijoiden
            // nimet.
            for ( auto& stud : studentList) {
                stud.printStudentInfo();
            }
            break;
        }
        case 2: {
            auto sortFunktio = [](const Student& a, const Student& b){
                return a.getName()<b.getName();
            };

            sort(studentList.begin(), studentList.end(),sortFunktio);
            // algoritmikirjaston sort funktion avulla
            // ja tulosta printStudentInfo() funktion avulla järjestetyt
            // opiskelijat
            for ( auto& stud : studentList) {
                stud.printStudentInfo();
            }
            break;
        }
        case 3: {

            // Järjestä StudentList vektorin Student oliot iän mukaan
            auto sortFunktio = [](const Student& a, const Student& b){
                return a.getAge()<b.getAge();
            };
            sort(studentList.begin(), studentList.end(), sortFunktio);
            // algoritmikirjaston sort funktion avulla
            // ja tulosta printStudentInfo() funktion avulla järjestetyt
            // opiskelijat
            for ( auto& stud : studentList) {
                stud.printStudentInfo();
            };
            break;
        }
        case 4: {
            string nimi;
            // Kysy käyttäjältä opiskelijan nimi
            cin>>nimi;
            // Etsi studenListan opiskelijoista algoritmikirjaston
            // find_if funktion avulla löytyykö käyttäjän antamaa nimeä
            // listalta. Jos löytyy, niin tulosta opiskelijan tiedot.
            auto it = find_if(studentList.begin(), studentList.end(), [&](const Student& s){
                return s.getName()== nimi;
            });
            if(it!=studentList.end()){
                it->printStudentInfo();
            } else {
                cout<<"Ei loytynyt"<<endl;
            }

            break;
        }
        default:
            cout<< "Wrong selection, stopping..."<<endl;
            break;
        }
}while(selection < 5);

return 0;
}
