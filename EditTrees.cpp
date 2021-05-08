#include "EditTrees.h"
//main runtime class that holds the functionality of the menu options for managing the data base

// default constructor
EditTrees::EditTrees(){

}
//destructor
EditTrees::~EditTrees(){

}
//return 1 means successful action
//return 2 means unsuccessful action



//prints all the students info
int EditTrees::printStudents(){
    if(!Trees.masterStudent->isEmpty()){
        cout << Trees.masterStudent->recursiveDataPrintConsole(Trees.masterStudent->root) << endl;
        return 1;
    }
    else{
        cout << "Data Base is empty. Nothing to print" << endl;
        return 2;
    }
}
//prints all the faculties info
int EditTrees::printFaculty(){
    if(!Trees.masterFaculty->isEmpty()){
        cout << Trees.masterFaculty->recursiveDataPrintConsole(Trees.masterFaculty->root) << endl;
        return 1;
    }
    else{
        cout << "Data Base is empty. Nothing to print" << endl;
        return 2;
    }
}
//prints a specific students info
int EditTrees::findStudent(){
    string inputID;
    TreeNode<Student>* tmpStudent = NULL;
    cout << "Enter the numerical ID of the student: " << endl;
    getline(cin,inputID);
    tmpStudent = Trees.masterStudent->findNode(stoi(inputID));
    if(tmpStudent != NULL){
        cout << tmpStudent->data.printDataConsole() << endl;
        return 1;
    }
    else{
        cout << "Student not found returning to menu" << endl;
        return 2;
    }
}
//prints a specific faculties info
int EditTrees::findFaculty(){
    string inputID;
    TreeNode<Faculty>* tmpFaculty = NULL;
    cout << "Enter the numerical ID of the Faculty: " << endl;
    getline(cin,inputID);
    tmpFaculty = Trees.masterFaculty->findNode(stoi(inputID));
    if(tmpFaculty != NULL){
        cout << tmpFaculty->data.printDataConsole() << endl;
        return 1;
    }
    else{
        cout << "Faculty not found returning to menu" << endl;
        return 2;
    }
}
//returns info on a students advisor
int EditTrees::findStudentAdvisor(){
    string inputID;
    TreeNode<Student>* tmpStudent = NULL;
    TreeNode<Faculty>* tmpFaculty = NULL;
    cout << "Enter the numerical ID of the student: " << endl;
    getline(cin,inputID);
    tmpStudent = Trees.masterStudent->findNode(stoi(inputID));
    if(tmpStudent != NULL){
        tmpFaculty = Trees.masterFaculty->findNode(tmpStudent->data.getAdvisor());
        if(tmpFaculty != NULL){
            cout << tmpFaculty->data.printDataConsole() << endl;
            return 1;
        }
        else{
        cout << "Faculty not found returning to menu" << endl;
        return 2;
        }
    }
    else{
        cout << "Student not found returning to menu" << endl;
        return 2;
    }
}
//prints all faculty members advisees
int EditTrees::printFacultyAdvisees(){
    string inputID;
    int numAdvisees;
    TreeNode<Faculty>* tmpFaculty = NULL;
    TreeNode<Student>* tmpStudent = NULL;
    cout << "Enter the numerical ID of the Faculty: " << endl;
    getline(cin,inputID);
    tmpFaculty = Trees.masterFaculty->findNode(stoi(inputID));
    if(tmpFaculty != NULL){
        numAdvisees = tmpFaculty->data.getNumAdvisees();
        for (int i = 0; i < numAdvisees; ++i ){
            tmpStudent = Trees.masterStudent->findNode(tmpFaculty->data.getAdvisee(i));
            if(tmpStudent != NULL){
                cout << "Student " + to_string(i+1) + ": " << endl;
                cout << tmpStudent->data.printDataConsole() << endl;
            }
            else{
                cout << "Error! Faculty has an advisee not in the student data base aborting" << endl;
                return 2;
            }
            
        }
        return 1;
    }
    else{
        cout << "Faculty not found returning to menu" << endl;
        return 2;
    }
}
//adds a student to the bst
int EditTrees::addStudent(){
    if(Trees.masterFaculty->isEmpty()){
        cout << "Please add a faculty member first" << endl;
        return 2;
    }
    Command tmpCommand;
    Student tempStudent;
    string inputData;
    cout << "Enter the students ID" << endl;
    getline(cin,inputData);
    tempStudent.setID(stoi(inputData));
    //if student exists abort
    if(Trees.masterStudent->findNode(stoi(inputData)) != NULL){
        cout << "Student with the ID already exists. Aborting" << endl;
        return 2;
    }
    cout << "Enter the students Name" << endl;
    getline(cin,inputData);
    tempStudent.setName(inputData);
    cout << "Enter the students Level" << endl;
    getline(cin,inputData);
    tempStudent.setLevel(inputData);
    cout << "Enter the students Major" << endl;
    getline(cin,inputData);
    tempStudent.setMajor(inputData);
    cout << "Enter the students GPA" << endl;
    getline(cin,inputData);
    tempStudent.setGPA(stod(inputData));
    cout << "Enter the student's advisor's ID or enter 0 to add an ID when adding its faculty member later" << endl;
    getline(cin,inputData);
    tempStudent.setAdvisor(stoi(inputData));
    //if the entered faculty member exists proceed
    if(Trees.masterFaculty->findNode(stoi(inputData)) != NULL){
        tmpCommand.previousFacultyNode = Trees.masterFaculty->findNode(stoi(inputData))->data;
        Trees.masterStudent->insert(tempStudent);
        Trees.masterFaculty->findNode(stoi(inputData))->data.addAdvisee(tempStudent.getID());
        tmpCommand.editedStudentNode = tempStudent;
        tmpCommand.action = "AddedStudent";
        Undo.rollbackPush(tmpCommand);
        return 1;
    }
    //if the user doesnt want the studentstudent to have an advisor proceed
    else if (stoi(inputData) == 0){
        cout << "WARNING!!!! THIS STUDENT HAS NO FACULTY ADVISOR PLEASE CREATE A FACULTY MEMBER OR ASSIGN THIS STUDENT TO AN EXISTING FACULTY MEMBER IN THE NEXT COMMAND" << endl;
        Trees.masterStudent->insert(tempStudent);
        tmpCommand.editedStudentNode = tempStudent;
        tmpCommand.action = "AddedStudent";
        Undo.rollbackPush(tmpCommand);
        return 1;
    }
    //invalid faculty ID
    else{
        cout << "Entered ID for faculty that does not exsist. Aborting" << endl;
        return 2;
    }
}

//adds faculty member to bst
int EditTrees::addFaculty(){
    Faculty tempFaculty;
    string inputData;
    Command tmpCommand;
    cout << "Enter the faculty's ID" << endl;
    getline(cin,inputData);
    //faculty cant have id of 0
    if (inputData == "0"){
        cout << "ID's cannot be 0. Aborting" << endl;
        return 2;
    }
    tempFaculty.setID(stoi(inputData));
    if(Trees.masterFaculty->findNode(stoi(inputData)) != NULL){
        cout << "Faculty with that ID already exists. Aborting" << endl;
        return 2;
    }
    cout << "Enter the faculty's Name" << endl;
    getline(cin,inputData);
    tempFaculty.setName(inputData);
    cout << "Enter the faculty's Level" << endl;
    getline(cin,inputData);
    tempFaculty.setLevel(inputData);
    cout << "Enter the faculties department" << endl;
    getline(cin,inputData);
    tempFaculty.setDepartment(inputData);
    //if there are no students make one
    if(Trees.masterStudent->isEmpty()){
        Trees.masterFaculty->insert(tempFaculty);
        cout << "there are no students to advise for this faculty member please create one now" << endl;
        int addedStudent = addStudent();
        if (addedStudent == 1){
            return 1;
        }
        else{
            cout << "Error with student creation. Removing faculty memeber" << endl;
            Trees.masterFaculty->deleteNode(Trees.masterFaculty->root->data);
            return 2;
        }
        
    }
    //if there are students in the tree with no advisor
    cout << "Enter the ID of the student advisee" << endl;
    getline(cin,inputData);
    if(Trees.masterStudent->findNode(stoi(inputData)) != NULL && Trees.masterStudent->findNode(stoi(inputData))->data.getAdvisor() <= 0){
        tempFaculty.addAdvisee(stoi(inputData));
        tmpCommand.editedFacultyNode = tempFaculty;
        tmpCommand.previousStudentNode = Trees.masterStudent->findNode(tempFaculty.getAdvisee(0))->data;
        Trees.masterStudent->findNode(tempFaculty.getAdvisee(0))->data.setAdvisor(tempFaculty.getID());
        Trees.masterFaculty->insert(tempFaculty);
        tmpCommand.editedStudentNode = Trees.masterStudent->findNode(tempFaculty.getAdvisee(0))->data;
        tmpCommand.action = "AddedFaculty";
        Undo.rollbackPush(tmpCommand);
        return 1;
    }
    else{
        cout << "invalid advisee ID or advisee already has an advisor. Aborting" << endl;
        return 2;
    }
    
}
//delests a student from the bst
int EditTrees::deleteStudent(){
    if(Trees.masterFaculty->isEmpty() && Trees.masterStudent->isEmpty()){
        cout << "data base is empty cannot delete. Aborted" << endl;
        return 2;
    }
    if(Trees.masterStudent->isEmpty()){
        cout << "no students to delete. Aborted" << endl;
        return 2;
    }
    TreeNode<Student>* tmpStudent = NULL;
    TreeNode<Faculty>* tmpFaculty = NULL;
    string inputData;
    Command tmpCommand;
    cout << "Enter the ID number for the student" << endl;
    getline(cin,inputData);
    if(Trees.masterStudent->findNode(stoi(inputData)) == NULL){
        cout << "Student does not exist" << endl;
        return 2;
    }
    tmpStudent = Trees.masterStudent->findNode(stoi(inputData));
    //cant have an id of 0
    if(tmpStudent->data.getID() <= 0){
        cout << "this student is invalid deleting. This cannot be undone" << endl;
        Trees.masterStudent->deleteNode(tmpStudent->data);
        return 1;
    }
    //if student exists continue
    if(tmpStudent != NULL){
        tmpFaculty = Trees.masterFaculty->findNode(tmpStudent->data.getAdvisor());
        tmpCommand.previousFacultyNode = tmpFaculty->data;
        tmpCommand.previousStudentNode = tmpStudent->data;
        //deletes student 
        if(tmpFaculty == NULL){
            cout << "this student has no faculty advisor, removing student for clean up..." << endl;
            Trees.masterStudent->deleteNode(tmpStudent->data);
            tmpCommand.action = "DeletedStudent";
            Undo.rollbackPush(tmpCommand);
            return 2;
        }
        //if students advisor only has one advisee
        if(tmpFaculty->data.getNumAdvisees() == 1){
            cout << "removing this student will cause their advisor to have no advisees, continuing will remove the faculty member as well. CONTINUE? (y/n) CASE SENSATIVE" << endl;
            getline(cin,inputData);
            if (inputData == "y"){
                Trees.masterStudent->deleteNode(tmpStudent->data);
                Trees.masterFaculty->deleteNode(tmpFaculty->data);
                tmpCommand.action = "DeletedStudent";
                Undo.rollbackPush(tmpCommand);
                return 1;
            }
            else{
                cout << "Aborting student deletion" << endl;
                return 2;
            }
        }
        //if student is one of many advisee's to advisor
        cout << "Student: " + to_string(tmpStudent->data.getID()) + " deleted." << endl;
        Trees.masterFaculty->findNode(tmpStudent->data.getAdvisor())->data.removeAdvisee(tmpStudent->data.getID());
        Trees.masterStudent->deleteNode(tmpStudent->data);
        tmpCommand.editedFacultyNode = Trees.masterFaculty->findNode(tmpCommand.previousFacultyNode.getID())->data;
        tmpCommand.action = "DeletedStudent";
        Undo.rollbackPush(tmpCommand);
        return 1;
    }
    else{
        cout << "invaid student ID. Aborting" << endl;
        return 2;
    }
     
}
//deletes a faculty memeber from the bst
int EditTrees::deleteFaculty(){
    //cant delete if trees empty
    if(Trees.masterFaculty->isEmpty() && Trees.masterStudent->isEmpty()){
        cout << "data base is empty cannot delete. Aborted" << endl;
        return 2;
    }
    TreeNode<Student>* tmpStudent = NULL;
    TreeNode<Faculty>* tmpFaculty = NULL;
    string inputData;
    Command tmpCommand;
    cout << "Enter the ID number for the Faculty" << endl;
    getline(cin,inputData);
    tmpFaculty = Trees.masterFaculty->findNode(stoi(inputData));
    //check to see if faculty exists
    if (tmpFaculty == NULL){
        cout << "invalid favulty ID" << endl;
        return 2;
    }
    //invalid faculty clean up
    if(tmpFaculty->data.getNumAdvisees() == 0){
        cout << "This faculty has no advisee's and shouldnt exist in the system. Cleaning up now (this cannot be undone)" << endl;
        Trees.masterFaculty->deleteNode(tmpFaculty->data);
        return 1;

    }
    //options for deleting faculty memeber
    cout << "deleting this faculty member will cause the students to have no advisor would you like to 1) replace the current faculty member with a new one (the new faculty will have the same ID as the deleted one)? or 2) assign the students to a new faculty memeber (enter 1 or 2)" << endl;
    getline(cin,inputData);
    tmpCommand.previousFacultyNode = tmpFaculty->data;
    if(inputData == "1"){
        cout << "Enter the new faculty's Name" << endl;
        getline(cin,inputData);
        tmpFaculty->data.setName(inputData);
        cout << "Enter the new faculty's Level" << endl;
        getline(cin,inputData);
        tmpFaculty->data.setLevel(inputData);
        cout << "Enter the faculties department" << endl;
        getline(cin,inputData);
        tmpFaculty->data.setDepartment(inputData);
        tmpCommand.editedFacultyNode = tmpFaculty->data;
        tmpCommand.action = "DeletedFaculty";
        Undo.rollbackPush(tmpCommand);
        return 1;
    }
    else if (inputData == "2"){
        cout << "enter the ID of the faculty memeber that will inherit this faculty's advisees: " << endl;
        getline(cin,inputData);
        TreeNode<Faculty>* newFacultyAdvisor = Trees.masterFaculty->findNode(stoi(inputData));
        if (newFacultyAdvisor == NULL){
            cout << "invalid faculty ID or no other faculty. Aborting deletion" << endl;
            return 2;
        }
        for (int i = 0; i < tmpFaculty->data.getNumAdvisees(); ++i){
             newFacultyAdvisor->data.addAdvisee(tmpFaculty->data.getAdvisee(i));
             tmpStudent = Trees.masterStudent->findNode(tmpFaculty->data.getAdvisee(i));
             tmpStudent->data.setAdvisor(newFacultyAdvisor->data.getID());
        }
        Trees.masterFaculty->deleteNode(tmpFaculty->data);
        tmpCommand.editedFacultyNode = Trees.masterFaculty->findNode(stoi(inputData))->data;
        tmpCommand.action = "DeletedFaculty";
        Undo.rollbackPush(tmpCommand);
        return 1;
    }
    else{
        cout << "invalid input" << endl;
        return 2;
    }
}
//changes a students advisor
int EditTrees::changeAdvisor(){
    TreeNode<Student>* tmpStudent = NULL;
    TreeNode<Faculty>* tmpFaculty = NULL;
    TreeNode<Faculty>* newFacultyAdvisor = NULL;
    string inputData;
    Command tmpCommand;
    cout << "Enter the ID of the student who is changing advisors" << endl;
    getline(cin,inputData);
    tmpStudent = Trees.masterStudent->findNode(stoi(inputData));
    //checks if student exists
    if(tmpStudent == NULL){
        cout << "Invalid ID. Aborting" << endl;
        return 2;
    }
    cout << "enter the ID of the faculty memeber that will become this students new advisor: " << endl;
    getline(cin,inputData);
    newFacultyAdvisor = Trees.masterFaculty->findNode(stoi(inputData));
    //checks if the new advisor exists and if the new advisor is the students current advisor
    if (newFacultyAdvisor == NULL || newFacultyAdvisor->data.getID() == tmpStudent->data.getAdvisor()){
        cout << "invalid faculty ID, no other faculty, or inputed the same faculty id twice. Aborting change" << endl;
        return 2;
    }
    tmpCommand.previousStudentNode = tmpStudent->data;
    //process if student had no previous advisor
    if(tmpStudent->data.getAdvisor() == 0){
         
        tmpStudent->data.setAdvisor(newFacultyAdvisor->data.getID());
        newFacultyAdvisor->data.addAdvisee(tmpStudent->data.getID());
        tmpCommand.editedFacultyNode = newFacultyAdvisor->data;
        tmpCommand.editedStudentNode = tmpStudent->data;
        tmpCommand.action = "MovedAdvisee";
        Undo.rollbackPush(tmpCommand);
        return 1;
    }
    tmpFaculty = Trees.masterFaculty->findNode(tmpStudent->data.getAdvisor());
    tmpCommand.previousFacultyNode = tmpFaculty->data;
    //process if students current advisor only has one advisee
    if(tmpFaculty->data.getNumAdvisees() == 1){
        cout << "switching the student from their current advisor will cause the advisor to have no advisees you can either 1) delete the faculty member or 2) abort this change (enter 1 or 2)" << endl;
        getline(cin,inputData);
        if(inputData == "1"){
            Trees.masterFaculty->deleteNode(tmpFaculty->data);
            tmpStudent->data.setAdvisor(newFacultyAdvisor->data.getID());
            newFacultyAdvisor->data.addAdvisee(tmpStudent->data.getID());
            tmpCommand.editedFacultyNode = newFacultyAdvisor->data;
            tmpCommand.editedStudentNode = tmpStudent->data;
            tmpCommand.action = "MovedAdvisee";
            Undo.rollbackPush(tmpCommand);
            return 1;
        }
        else{
            cout << "Aborting change" << endl;
            return 2;
        }
    }
    //every other scenerio
    tmpFaculty->data.removeAdvisee(tmpStudent->data.getID());
    tmpStudent->data.setAdvisor(newFacultyAdvisor->data.getID());
    newFacultyAdvisor->data.addAdvisee(tmpStudent->data.getID());
    tmpCommand.editedFacultyNode = newFacultyAdvisor->data;
    tmpCommand.editedStudentNode = tmpStudent->data;
    tmpCommand.action = "MovedAdvisee";
    Undo.rollbackPush(tmpCommand);
    return 1;
}
//removes advisee from advisor
int EditTrees::removeAdvisee(){
    TreeNode<Student>* tmpStudent = NULL;
    TreeNode<Faculty>* tmpFaculty = NULL;
    string inputData;
    Command tmpCommand;
    cout << "Enter the ID of the student who will be removed as an advisee" << endl;
    getline(cin,inputData);
    tmpStudent = Trees.masterStudent->findNode(stoi(inputData));
    //checks if student exists and has an advisor
    if(tmpStudent == NULL || tmpStudent->data.getAdvisor() == 0){
        cout << "Invalid ID or student doesnt have an advisor. Aborting" << endl;
        return 2;
    }
   
    tmpFaculty = Trees.masterFaculty->findNode(tmpStudent->data.getAdvisor());
    //advisor only has one advisee 
    if(tmpFaculty->data.getNumAdvisees() <= 1){
        cout << "Cannot remove and advisee from a faculty who only has one advisee. Please choose option 11 for more options for this situation" << endl;
        return 2;
    }
    //check if faculty member exists
    if (tmpFaculty == NULL){
        cout << "Faculty member does not exist. removing advisor ID from student. This cannot be undo'd (serves as clean up)" << endl;
        tmpStudent->data.setAdvisor(0);
        return 2;
    }
    //removed advisee from faculty member
    tmpCommand.previousFacultyNode = tmpFaculty->data;
    tmpCommand.previousStudentNode = tmpStudent->data;
    tmpFaculty->data.removeAdvisee(tmpStudent->data.getID());
    tmpStudent->data.setAdvisor(0);
    tmpCommand.editedFacultyNode = tmpFaculty->data;
    tmpCommand.editedStudentNode = tmpStudent->data;
    tmpCommand.action == "RemovedAdvisee";
    Undo.rollbackPush(tmpCommand);
    cout << "Student removed from faculty ID: " << tmpFaculty->data.getID() << " Student will now have an advisor, 0, to represent no advisor. Please add one at your convenience :)" << endl;
    return 1;

}

//undos the past actions (up to 5 back)
int EditTrees::rollbackTrees(){
    //below are all the possible outcomes of making a change and their respective counter operations to undo
    if(Undo.isEmpty()){
        cout << "no commands to undo" << endl;
        return 2;
    }
    //last command to analyze
    Command tmpCommand = Undo.rollbackPop();
    //if last action added a faculty member
    if(tmpCommand.action == "AddedFaculty"){
        //deleted the added fac
        Trees.masterFaculty->deleteNode(tmpCommand.editedFacultyNode);
        //if the previous student and current student are equal then there was no advisor previously
        if(tmpCommand.previousStudentNode == tmpCommand.editedStudentNode){
            Trees.masterStudent->findNode(tmpCommand.editedStudentNode.getID())->data.setAdvisor(0);
        }
        //if the faculty tree is empty then the student tree can only have one student created from starting with empty bst's
        else if(Trees.masterFaculty->isEmpty()){
            Trees.masterStudent->deleteNode(Trees.masterStudent->root->data);
        }
    }
    //if last action was adding a student
    else if(tmpCommand.action == "AddedStudent"){
        Trees.masterStudent->deleteNode(tmpCommand.editedStudentNode);
        //if the faculty tree is empty then the student tree can only have one student created from starting with empty bst's
        if(Trees.masterFaculty->root->data.getNumAdvisees() == 0 && tmpCommand.editedStudentNode.getAdvisor() == 0){
                Trees.masterFaculty->deleteNode(Trees.masterFaculty->root->data);
        }
        //if the current student had an advisor remove it from the advisee list of the advisor
        if(tmpCommand.editedStudentNode.getAdvisor() != 0){
            
            Trees.masterFaculty->findNode(tmpCommand.previousFacultyNode.getID())->data.removeAdvisee();
        }
    }
    //if the last action was deleting a faculty
    else if(tmpCommand.action == "DeletedFaculty"){
        //if the previous fac and the current fac have the same advisee's then reset the current fac back to the previous ones data
        if(tmpCommand.previousFacultyNode.getAdvisee(0) == tmpCommand.editedFacultyNode.getAdvisee(0)){
            Trees.masterFaculty->findNode(tmpCommand.previousFacultyNode.getID())->data.setName(tmpCommand.previousFacultyNode.getName());
            Trees.masterFaculty->findNode(tmpCommand.previousFacultyNode.getID())->data.setLevel(tmpCommand.previousFacultyNode.getLevel());
            Trees.masterFaculty->findNode(tmpCommand.previousFacultyNode.getID())->data.setDepartment(tmpCommand.previousFacultyNode.getDepartment());
        }
        //loop through previous fac advisee's and remove them from the current advisor and add them back to the previous advisor
        else{
            int adviseeID;
            for(int i = 0; i < tmpCommand.previousFacultyNode.getNumAdvisees(); ++i){
                cout << "test" << endl;
                adviseeID = Trees.masterFaculty->findNode(tmpCommand.editedFacultyNode.getID())->data.removeAdvisee();
                Trees.masterStudent->findNode(adviseeID)->data.setAdvisor(tmpCommand.previousFacultyNode.getID());
            }
            Trees.masterFaculty->insert(tmpCommand.previousFacultyNode);
        }
    }
    //if the last command was to delete a student
    else if (tmpCommand.action == "DeletedStudent"){
        //if the deleted students advisor still exists add them back as an advisee
        if(Trees.masterFaculty->findNode(tmpCommand.editedFacultyNode.getID()) != NULL){
            Trees.masterFaculty->findNode(tmpCommand.editedFacultyNode.getID())->data = tmpCommand.previousFacultyNode;
            Trees.masterStudent->insert(tmpCommand.previousStudentNode);
        }
        //if the advisor was seleted
        else{
            //if the student had an advisor add the advisor back in
            if(tmpCommand.previousStudentNode.getAdvisor() != 0){
                Trees.masterFaculty->insert(tmpCommand.previousFacultyNode);
            }
            //otherwise just add the student back in
            Trees.masterStudent->insert(tmpCommand.previousStudentNode);
        }
    }
    //if the last command was to move an advisee to another advisor
    else if (tmpCommand.action == "MovedAdvisee"){
        //if the student didnt previously have an advisor
        if(tmpCommand.previousStudentNode.getAdvisor() == 0){
            Trees.masterFaculty->findNode(tmpCommand.editedStudentNode.getAdvisor())->data.removeAdvisee(tmpCommand.editedStudentNode.getID());
            Trees.masterStudent->findNode(tmpCommand.editedStudentNode.getID())->data = tmpCommand.previousStudentNode;
        }
        //if the student was the previous advisors only advisee
        else if(tmpCommand.previousFacultyNode.getNumAdvisees() == 1){
            Trees.masterFaculty->findNode(tmpCommand.editedStudentNode.getAdvisor())->data.removeAdvisee(tmpCommand.editedStudentNode.getID());
            Trees.masterStudent->findNode(tmpCommand.editedStudentNode.getID())->data = tmpCommand.previousStudentNode;
            Trees.masterFaculty->insert(tmpCommand.previousFacultyNode);
        }
        //if the student was just moved from one advisor to another
        else{
            Trees.masterFaculty->findNode(tmpCommand.editedStudentNode.getAdvisor())->data.removeAdvisee(tmpCommand.editedStudentNode.getID());
            Trees.masterStudent->findNode(tmpCommand.editedStudentNode.getID())->data = tmpCommand.previousStudentNode;
            Trees.masterFaculty->findNode(tmpCommand.previousFacultyNode.getID())->data = tmpCommand.previousFacultyNode;
        }
    }
    //if the last command was to change a students major
    else if (tmpCommand.action == "ChangedMajor"){
        //reset the major back to the previous one
        Trees.masterStudent->findNode(tmpCommand.editedStudentNode.getID())->data = tmpCommand.previousStudentNode;
    }
    //if the last command was to remove an advisee
    else if (tmpCommand.action == "RemovedAdvisee"){
        //add the advisee back to the advisor and add the advisor back to the advisee
        Trees.masterFaculty->findNode(tmpCommand.editedFacultyNode.getID())->data = tmpCommand.previousFacultyNode;
        Trees.masterStudent->findNode(tmpCommand.editedStudentNode.getID())->data = tmpCommand.previousStudentNode;
    }
    return 1;
}
//returns indicator to exit prog
int EditTrees::exitProgram(){
    cout << "Exiting program and saving data..." << endl;
    return 3;
}
//resets info strings
int EditTrees::resetBSTPrintString(){
    Trees.masterFaculty->wipeTreeNodesData();
    Trees.masterStudent->wipeTreeNodesData();
    return 1;
}


//prints all students info that are taking a major
int EditTrees::printStudentsOfMajor(){
    string tmpMajor =  "";
    string output = "";
    cout << "What major do you want to find all the students for? (case sensative). If there are none found it will print a blank line" << endl;
    getline(cin,tmpMajor);
    output = Trees.masterStudent->findAllOfMajor(tmpMajor,Trees.masterStudent->root);
    cout << output << endl;
    return 1; 
}
//prints all faculty of a name
int EditTrees::printFacultyByName(){
    string tmpName = "";
    cout << "Enter the first and last name of the Faculty you want to find with that name (case sensative). If there are none found it will print a blank line" << endl;
    getline(cin,tmpName);
    cout << Trees.masterFaculty->findAllOfSameName(tmpName, Trees.masterFaculty->root) << endl;
    return 1;
}
//prints all students of a name
int EditTrees::printStudentByName(){
    string tmpName = "";
    cout << "Enter the first and last name of the Students you want to find with that name (case sensative). If there are none found it will print a blank line" << endl;
    getline(cin,tmpName);
    cout << Trees.masterStudent->findAllOfSameName(tmpName, Trees.masterStudent->root) << endl;
    return 1;
}
//changes a studnets major
int EditTrees::changeStudentMajor(){
    TreeNode<Student>* tmpStudent = NULL;
    string inputData;
    Command tmpCommand;
    cout << "Enter the ID of the student you want to change the Major of" << endl;
    getline(cin,inputData);
    tmpStudent = Trees.masterStudent->findNode(stoi(inputData));
    if(tmpStudent == NULL){
        cout << "Invalid ID. Aborting" << endl;
        return 2;
    }
    tmpCommand.previousStudentNode = tmpStudent->data;
    cout << "Enter the new Major the student has delclared" << endl;
    getline(cin,inputData);
    tmpStudent->data.setMajor(inputData);
    tmpCommand.editedStudentNode = tmpStudent->data;
    tmpCommand.action = "ChangedMajor";
    Undo.rollbackPush(tmpCommand);
    return 1;
}