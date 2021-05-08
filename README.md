Michael Efseaff
2343166
Assignment 6
CPSC-350-01
German

LATE DAYS:
Used all 3 for this assignment


Resources:

cplusplus.com
stackoverflow.com
geeksforgeeks.org


Extra Credit functions and functionality:

rollback works for any command that edits the data base information
can search for students by major
can search for students by first and last name 
can search for faculty by first and last name 
can change a students major

deviations and design choices:

all search functions requiring a string are case sensative

students dont need a faculty member to exist in order to prevent some restrictive loops from happening. so you can make a bunch of students and assign them to a faculty at any point. it will just give you a warning after the command is done that the student has no advisor. 

Faculty cannot exist without an advisee however the only situation where this can happen is if you start with two empty bst's or change the saved data of a faculty member. When starting with two bsts that are empty you have to make a faculty and student pair to act as root nodes for the bst's. if you enter the data properly and the faculty's advisee is the students advisor and vise vera. Rollbacking this deletes only the student and the fac will be in there with no advisee. this is a violation but it shouldnt break anything and you can delete the fac normally or add in a student and make the lonley faculty its advisor

alot of other things that you may come accross grading. its hard to list out every single specific that i went with but it will tell you if you do something wrong

also depending on your console size it might seem like nothing is happening but if you scroll up after a command the stuff will be there

some actions cannot be undone but it will tell you why. like deleting a faculty member with invaid advisees (seen as an error). 





KNOWN BUGS!!!!!!!!:

this program doesnt work too well with preset data bases that are intentionally messed up but nothing should break it just wont auto detect or change anything (like having a bunch of faculty with no students or having none of the ids match ect)

I have came across some errors that had to do with information input into the ID's but I have no been able to reproduce them consistently

