#include "Faculty.h"

//default constructor
Faculty::Faculty(){
    ID = 0;
    Name = "";
    Level = "";
    Department = "";
}
//destructor
Faculty::~Faculty(){

}
//overloading comparative operators
bool Faculty::operator==(Faculty f){
  return (this->getID() == f.getID());
}

bool Faculty::operator!=(Faculty f){
    return (this->getID() != f.getID());
}

bool Faculty::operator<(Faculty f){
   return (this->getID() < f.getID());
}

bool Faculty::operator<=(Faculty f){
    return (this->getID() <= f.getID());
}

bool Faculty::operator>(Faculty f){
    return (this->getID() > f.getID());
}

bool Faculty::operator>=(Faculty f){
    return (this->getID() >= f.getID());
}

//returns the fac's department
string Faculty::getDepartment(){
    return Department;
}
//returns the ID of a specific advisee
int Faculty::getAdvisee(int key){
    if (key >= Advisees.size()){
        cout << "invalid index in advisee list" << endl;
        return 1;
    }
    else{
        return Advisees.at(key);
    }
    
}
//returns how many advisee's the fac has
int Faculty::getNumAdvisees(){
    return Advisees.size();
}
//removes all advisees
void Faculty::clearAdvisees(){
    Advisees.clear();
}
//removes the last inserted advisee
int Faculty::removeAdvisee(){
    int adviseeID;
    adviseeID = Advisees.back();
    Advisees.pop_back();
    return adviseeID;
}
//removes a specific advisee
int Faculty::removeAdvisee(int key){
    int adviseeID;
    for (int i = 0; i < Advisees.size(); ++i){
        if(Advisees[i] == key){
            adviseeID = Advisees.at(i);
            Advisees.erase(Advisees.begin()+i);   
        }
    }
    return adviseeID;
}
//sets the dept of the fac
void Faculty::setDepartment(string tempDepartment){
    Department = tempDepartment;
}
//ads and advisee to the fac
void Faculty::addAdvisee(int adviseeID){
   Advisees.push_back(adviseeID);
}
//prints the fac's data to the file in a format
string Faculty::printData(){
    string printedData = "";
   
    printedData += to_string(ID) + '\n';
    printedData += (Name + '\n');
    printedData += (Level + '\n');
    printedData += (Department + '\n');
    printedData += (to_string(Advisees.size()) + '\n');
    for (int i = 0; i < Advisees.size(); ++i){
        printedData += (to_string(Advisees[i]) + '\n');
    }
    return printedData;
}
//prints the fac's data to the console
string Faculty::printDataConsole(){
    string printedData = "";
   
    printedData += "ID: " + to_string(ID) + '\n';
    printedData += ("Name: " + Name + '\n');
    printedData += ("Level: " + Level + '\n');
    printedData += ("Department: " + Department + '\n');
    printedData += ("Number of Advisees: " + to_string(Advisees.size()) + '\n');
    for (int i = 0; i < Advisees.size(); ++i){
        printedData += ("Advisee " + to_string(i+1) + " ID: " + to_string(Advisees[i]) + '\n');
    }
    printedData += '\n';
     //cout << printedData << endl;
    return printedData;
}