#include "MasterTrees.h"
//class that deals with creating and holding the bst's and saving them
MasterTrees::MasterTrees(){
    ifstream inputFileOne ("facultyTable");
    ifstream inputFileTwo ("studentTable");
    string lineData;
    int tmpID;
    string tmpName;
    string tmpLevel;
    string tmpDepartment;
    int numAdvisees;
    int tmpAdvisee;
    vector<int> Advisees;
    Faculty tmpFaculty;

    string tmpMajor;
    double tmpGPA;
    int tmpAdvisor;
    Student tmpStudent;
    //if the files exist read in the data and make the nodes
    if(inputFileOne.is_open() && inputFileTwo.is_open()){
        while(getline(inputFileOne,lineData)){
        
            tmpID = stoi(lineData);
            tmpFaculty.setID(tmpID);
            getline(inputFileOne,tmpName);
            tmpFaculty.setName(tmpName);
            getline(inputFileOne,tmpLevel);
            tmpFaculty.setLevel(tmpLevel);
            getline(inputFileOne,tmpDepartment);
            tmpFaculty.setDepartment(tmpDepartment);
            getline(inputFileOne,lineData);
            numAdvisees = stoi(lineData);
            for(int i = 0; i < numAdvisees; ++i){
                getline(inputFileOne,lineData);
                tmpAdvisee = stoi(lineData);
                tmpFaculty.addAdvisee(tmpAdvisee);
            }
            
            masterFaculty->insert(tmpFaculty);
            tmpFaculty.clearAdvisees();


        }
        while(getline(inputFileTwo,lineData)){
            tmpID = stoi(lineData);
            tmpStudent.setID(tmpID);
            getline(inputFileTwo,tmpName);
            tmpStudent.setName(tmpName);
            getline(inputFileTwo,tmpLevel);
            tmpStudent.setLevel(tmpLevel);
            getline(inputFileTwo,tmpMajor);
            tmpStudent.setMajor(tmpMajor);
            getline(inputFileTwo,lineData);
            tmpGPA = stod(lineData);
            tmpStudent.setGPA(tmpGPA);
            getline(inputFileTwo,lineData);
            tmpAdvisor = stoi(lineData);
            tmpStudent.setAdvisor(tmpAdvisor);
            masterStudent->insert(tmpStudent);
        }
    }
    else {
        cout << "No saved data base. Creating new empty data base..." << endl;
    }

    inputFileOne.close();
    inputFileTwo.close();

}
//destructor
MasterTrees::~MasterTrees(){
    saveTrees();
    delete masterFaculty;
    delete masterStudent;
}
//save the bst's to files
void MasterTrees::saveTrees(){
    ofstream outputFileOne ("facultyTable");
    ofstream outputFileTwo ("studentTable");
    //if the trees arent empty and the files exist write out the data
    if(outputFileOne.is_open() && outputFileTwo.is_open()){
        if(masterFaculty->isEmpty() == false){
            outputFileOne << masterFaculty->recursiveDataPrint(masterFaculty->root);
        }
        if(masterStudent->isEmpty() == false){
            outputFileTwo << masterStudent->recursiveDataPrint(masterStudent->root);
        }
    }
    else{
        cout << "something went wrong. Cannot save data" << endl;
    }
   

    outputFileOne.close();
    outputFileTwo.close();
}