#ifndef COMMAND_H
#define COMMAND_H
#include "BST.h"
//class representing the commands done by the user that change information in the data bases or the structure of the data base

class Command{
    public:
        //default constructor
        Command();
        //overloaded constructor
        Command(Student studentNode, Faculty facultyNode, string choice);
        //destructor
        ~Command();
        //action done by the user
        string action;
        //the current student node 
        Student editedStudentNode;
        //the current student nodes previous state
        Student previousStudentNode;
        //the current faculty node
        Faculty editedFacultyNode;
        //the current faculty nodes previous state
        Faculty previousFacultyNode;

};
#endif
