#include "Student.h"
//default constructor
Student::Student(){
    ID = 0;
    Name = "";
    Level = "";
    Major = "";
    GPA = 0;
    Advisor = 0;
}
//destructor
Student::~Student(){

}
//overloaded comparative operations
bool Student::operator==(Student s){
  return (this->getID() == s.getID());
}

bool Student::operator!=(Student s){
    return (this->getID() != s.getID());
}

bool Student::operator<(Student s){
   return (this->getID() < s.getID());
}

bool Student::operator<=(Student s){
    return (this->getID() <= s.getID());
}

bool Student::operator>(Student s){
    return (this->getID() > s.getID());
}

bool Student::operator>=(Student s){
    return (this->getID() >= s.getID());
}
//returens the students major
string Student::getMajor(){
    return Major;
}
//returns the students gpa
double Student::getGPA(){
    return GPA;
}
//returns the students advisor
int Student::getAdvisor(){
    return Advisor;
}
//sets the students major
void Student::setMajor(string tempMajor){
    Major = tempMajor;
}
//sets the students GPA
void Student::setGPA(double tempGPA){
    GPA = tempGPA;
}
//sets the students advisor 
void Student::setAdvisor(int tempAdvisor){
    Advisor = tempAdvisor;
}
//prints out the students data for files
string Student::printData(){
    string printedData;
    printedData += (to_string(ID) + '\n');
    printedData += (Name + '\n');
    printedData += (Level + '\n');
    printedData += (Major + '\n');
    printedData += (to_string(GPA) + '\n');
    printedData += (to_string(Advisor) + '\n');
    return printedData;
}
//prints out the students data for console
string Student::printDataConsole(){
    string printedData;
    printedData += ("ID: " + to_string(ID) + '\n');
    printedData += ("Name: " + Name + '\n');
    printedData += ("Level: " + Level + '\n');
    printedData += ("Major: " + Major + '\n');
    printedData += ("GPA: " + to_string(GPA) + '\n');
    printedData += ("Advisor ID: " + to_string(Advisor) + '\n');
    printedData += '\n';
    return printedData;
}