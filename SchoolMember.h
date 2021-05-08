#ifndef SCHOOLMEMBER_H
#define SCHOOLMEMBER_H
#include <iostream>
using namespace std;
//base class for faculty and students at the school 
class SchoolMember{
    public:
        //returns the members id
        int getID();
        //returns the members name
        string getName();
        //returns the members level
        string getLevel();

        //sets the members id
        void setID(int tempID);
        //sets the members name
        void setName(string tempName);
        //sets the members level
        void setLevel(string templevel);

    protected:
        //members id
        int ID;
        //members name
        string Name;
        //members level
        string Level;
};
#endif
