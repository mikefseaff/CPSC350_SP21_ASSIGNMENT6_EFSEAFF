#ifndef MASTERTREES_H
#define MASTERTREES_H
#include "BST.h"
#include <fstream>
#include <iostream>
using namespace std;
//class that deals with creating and holding the bst's and saving them
class MasterTrees{
    public:
        //default constructor
        MasterTrees();
        //destructor
        ~MasterTrees();
        //saves the bst's to files
        void saveTrees();
        //bsts of factulty and students
        BST<Faculty> *masterFaculty = new BST<Faculty>;
        BST<Student> *masterStudent = new BST<Student>;
};
#endif 

