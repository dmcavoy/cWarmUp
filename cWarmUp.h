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

The program will only read one name. You can't enter someones
full name.  For example you can enter "Dani" but you can not
enter "Dani McAvoy" to the database.


@author Danielle McAvoy
@date September 26 2011

 */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH_NAME 16

// A student consists of a name, ID and grade.
struct student{
    char name[MAX_LENGTH_NAME];
    int ID;
    char grade;
};

// Array of students.  Size is decided by user at
// at run time.
struct student *myClass;

// Variable to hold the size of the class when
// the user inputs it.
int classSize = -1;

// Which keep track of the number of each grade
int numberAs = 0;
int numberBs = 0;
int numberCs = 0;
int numberDs = 0;
int numberFs = 0;

// Prints the welcome message
void welcome(void);

// Gets the Class Size from the user
int askClassSize(void);

// Fills the array with all the student information
void fillStudentArray(int classSize);

// Gets the student information from the user
void askStudentName(char* name);
char askStudentGrade(void);
int askStudentID(void);

// Prints information on every student and
// then class statistics on grades
void printClassStats(void);

// Cleans up user input after scanf runs
void flush_stdin();
