#ifndef RUNTIMECONTROLLER_H
#define RUNTIMECONTROLLER_H
#include "EditTrees.h"
//class to handle the functionality when the user is using the system
class RunTimeController{
    public:
        //default constructor
        RunTimeController();
        //destructor
        ~RunTimeController();
        //prints out the avaliable menu options
        void printMenuOptions();
        //program running loop
        void runProgram();
    private:
        //functions to edit the trees and the trees themselves
        EditTrees edit;
};
#endif