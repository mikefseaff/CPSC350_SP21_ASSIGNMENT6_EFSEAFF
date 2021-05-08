#include "RunTimeController.h"

RunTimeController::RunTimeController(){

}

RunTimeController::~RunTimeController(){

}

void RunTimeController::printMenuOptions(){
    cout << "Enter the number corrosponding to the command options to use the data base" << endl;
    cout << 
    "1. Print all students and their information. " << '\n' <<
    "2. Print all faculty and their information. " << '\n' <<
    "3. Find and display a student's information." << '\n' <<
    "4. Find and display faculty's information." << '\n' <<
    "5. Display information of student advisor. " << '\n' <<
    "6. Print all info of a faculty members advisees. " << '\n' <<
    "7. Add a new student. " << '\n' <<
    "8. Delete a student. " << '\n' <<
    "9. Add a new faculty member. " << '\n' <<
    "10. Delete a faculty member. " << '\n' <<
    "11. Change a student’s advisor. " << '\n' <<
    "12. Remove an advisee from a faculty member. " << '\n' <<
    "13. Print all information of students taking a specific major. " << '\n' <<
    "14. Print all faculty members that share the same name. " << '\n' <<
    "15. Print all students that share the same name.  " << '\n' <<
    "16. Change a students major. " << '\n' <<
    "17. Undo " << '\n' <<
    "18. Exit" << '\n';
}

void RunTimeController::runProgram(){
    string inputString = "";
    int input = 0;
    int functionReturn = 0;
    while(functionReturn != 3){
        if (functionReturn == 2){
            cout << "You made an error in the last command please follow the instructions and enter valid information..." << endl;
        }
        printMenuOptions();
        getline(cin,inputString);
        input = stoi(inputString);
        switch (input)
        {
        case 1:
            functionReturn = edit.printStudents();
            edit.resetBSTPrintString();
            break;
        case 2:
            functionReturn = edit.printFaculty();
            edit.resetBSTPrintString();
            break;
        case 3:
            functionReturn = edit.findStudent();
            edit.resetBSTPrintString();
            break;
        case 4:
            functionReturn = edit.findFaculty();
            edit.resetBSTPrintString();
            break;
        case 5:
            functionReturn = edit.findStudentAdvisor();
            edit.resetBSTPrintString();
            break;
        case 6:
            functionReturn = edit.printFacultyAdvisees();
            edit.resetBSTPrintString();
            break;
        case 7:
            functionReturn = edit.addStudent();
            edit.resetBSTPrintString();
            break;
        case 8:
            functionReturn = edit.deleteStudent();
            edit.resetBSTPrintString();
            break;
        case 9:
            functionReturn = edit.addFaculty();
            edit.resetBSTPrintString();
            break;
        case 10:
            functionReturn = edit.deleteFaculty();
            edit.resetBSTPrintString();
            break;
        case 11:
            functionReturn = edit.changeAdvisor();
            edit.resetBSTPrintString();
            break;
        case 12:
            functionReturn = edit.removeAdvisee();
            edit.resetBSTPrintString();
            break;
        case 13:
            functionReturn = edit.printStudentsOfMajor();
            edit.resetBSTPrintString();
            break;
        case 14:
            functionReturn = edit.printFacultyByName();
            edit.resetBSTPrintString();
            break;
        case 15:
            functionReturn = edit.printStudentByName();
            edit.resetBSTPrintString();
            break;
        case 16:
            functionReturn = edit.changeStudentMajor();
            edit.resetBSTPrintString();
            break;
        case 17:
            functionReturn = edit.rollbackTrees();
            edit.resetBSTPrintString();
            break;
        case 18:
            functionReturn = edit.exitProgram();
            edit.resetBSTPrintString();
            break;
        
        default:
            cout << "invalid input try again..." << endl;
            break;
        }
    }
}