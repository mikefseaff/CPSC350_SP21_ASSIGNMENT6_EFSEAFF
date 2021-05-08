#ifndef EDITTREES_H
#define EDITTREES_H
#include "MasterTrees.h"
#include "Rollback.h"
//main runtime class that holds the functionality of the menu options for managing the data base

class EditTrees{
    public:
        //default constructor
        EditTrees();
        //destructor
        ~EditTrees();
        //prints all the students info
        int printStudents();
        //prints all the faculties info
        int printFaculty();
        //prints a specific students info
        int findStudent();
        //prints a specific faculties info
        int findFaculty();
        //returns info on a students advisor
        int findStudentAdvisor();
        //prints all faculty members advisees
        int printFacultyAdvisees();
        //adds a student to the bst
        int addStudent();
        //deletes the student in the bst 
        int deleteStudent();
        //adds a faculty member to the bst
        int addFaculty();
        //deletes the faculty member from the bst
        int deleteFaculty();
        //changes a students advisor
        int changeAdvisor();
        //removes a student as  an advisee from an advisor
        int removeAdvisee();
        //undos the most recent action (saves up to 5 back)
        int rollbackTrees();
        //exits the program saving the data
        int exitProgram();
        //resets info printing strings
        int resetBSTPrintString();

        //extra credit functions

        //prints infor of all students of a major
        int printStudentsOfMajor();
        //prints all faculty by first last name
        int printFacultyByName();
        //prints all students by first last name
        int printStudentByName();
        //changes the students major
        int changeStudentMajor();
    private:
        //object that holds the bst's
        MasterTrees Trees;
        //rollback object for undoing processes
        Rollback Undo;
};
#endif