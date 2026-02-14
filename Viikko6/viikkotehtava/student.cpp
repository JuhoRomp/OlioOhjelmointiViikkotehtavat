#include "student.h"
#include <string>
#include <iostream>
using namespace std;

Student::Student(string nimi, int ika) {
    setName(nimi);
    setAge(ika);
}

void Student::setAge(int ika)
{
    age = ika;

}

void Student::setName(string nimi)
{
    name = nimi;

}

string Student::getName() const
{
    return name;
}

int Student::getAge() const
{
    return age;
}

void Student::printStudentInfo()
{
    cout<<"Student name: "<<name<<", Student age: "<<age<<endl;

}
