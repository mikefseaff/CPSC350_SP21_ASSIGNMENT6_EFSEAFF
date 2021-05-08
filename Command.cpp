#include "Command.h"
//class representing the commands done by the user that change information in the data bases or the structure of the data base

//default constructor
Command::Command(){

}

//overloaded constructor
Command::Command(Student studentNode, Faculty facultyNode, string choice){
    previousStudentNode = studentNode;
    previousFacultyNode = facultyNode;
    action = choice;
}

//destructor
Command::~Command(){

}