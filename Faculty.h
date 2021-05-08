#ifndef FACULTY_H
#define FACULTY_H
#include "SchoolMember.h"
#include <vector>
//class that extends the schoolmember class representing a faculty member at the school
class Faculty : public SchoolMember{
    public:
        //default constructor
        Faculty();
        //destructor
        ~Faculty();
        //overloading comparative operators
        bool operator==(Faculty f);
        bool operator!=(Faculty f);
        bool operator<(Faculty f);
        bool operator<=(Faculty f);
        bool operator>(Faculty f);
        bool operator>=(Faculty f);
        //returns the fac's department
        string getDepartment();
        //returns the ID of a specific advisee
        int getAdvisee(int key);
        //returns how many advisee's the fac has
        int getNumAdvisees();
        //removes all advisees
        void clearAdvisees();
        //removes the last inserted advisee
        int removeAdvisee();
        //removes a specific advisee
        int removeAdvisee(int key);
        //sets the dept of the fac
        void setDepartment(string tempDepartment);
        //ads and advisee to the fac
        void addAdvisee(int adviseeID);
        //prints the fac's data to the file in a format
        string printData();
        //prints the fac's data to the console
        string printDataConsole();

    private:
        //faculties department
        string Department;
        //list of ints of advisee ids
        vector<int> Advisees;
        
        
};
#endif