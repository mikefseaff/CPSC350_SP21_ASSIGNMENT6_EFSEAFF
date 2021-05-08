#include "SchoolMember.h"
//returns the members id
int SchoolMember::getID(){
    return ID;
}
//returns the members name
string SchoolMember::getName(){
    return Name;
}
//returns the members level
string SchoolMember::getLevel(){
    return Level;
}
//returns the members id
void SchoolMember::setID(int tempID){
    ID = tempID;
}
//returns the members name
void SchoolMember::setName(string tempName){
    Name = tempName;
}
//returns the members level
void SchoolMember::setLevel(string tempLevel){
    Level = tempLevel;
}