#ifndef STUDENT_H
#define STUDENT_H
#include "SchoolMember.h"
//class extending schoolmember that represents a student at the school
class Student : public SchoolMember{
    public:
        //default constructor
        Student();
        //destructor
        ~Student();
        //overloaded comparative operations
        bool operator==(Student s);
        bool operator!=(Student s);
        bool operator<(Student s);
        bool operator<=(Student s);
        bool operator>(Student s);
        bool operator>=(Student s);
        //returns the students major 
        string getMajor();
        //returns the students GPA
        double getGPA();
        //returns the students advisor
        int getAdvisor();
        //sets the students major
        void setMajor(string tempMajor);
        //sets the students GPA
        void setGPA(double tempGPA);
        //sets the students advisor
        void setAdvisor(int tempAdvisor);
        //prints the students data for files
        string printData();
        //prints the students data for console output
        string printDataConsole();

    private:
        string Major;
        double GPA;
        int Advisor;
};
#endif