/*
This class was created for Operating Systems - Fall 2011.

This class was created for C practice.  It is a very simple
database which keeps track of a class of students. A user
answers a bunch of prompts to enter their class and then
gets a number of statistics at the end.

The user first gives the size of the class.  Then the
program creates an array of students, which the user
fills in one by one.  Once all the students have been
entered the information of all the students plus the
number of each grade prints out.


@author Danielle McAvoy
@date September 26 2011

 */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct student{
    int ID;
    char name[16];
    char grade;
};

struct student *myClass;

int classSize;

// I should make these into an array once this works
int numberAs = 0;
int numberBs = 0;
int numberCs = 0;
int numberDs = 0;
int numberFs = 0;

// Welcome Message
void welcome(void);

//Gets the Class Size from the User
int askClassSize(void);

//Gets the information for each Student
void fillStudentArray(int classSize);
char* askStudentName(void);
char askStudentGrade(void);
int askStudentID(void);

//Prints all the Class Information
void printClassStats(void);

// Cleans up user input
void flush_stdin();
