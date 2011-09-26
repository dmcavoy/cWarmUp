/*
This class was created for Operating Systems - Fall 2011.

This class was created for C practice.  It is a very simple
database which keeps track of a class of students. A user
answers a bunch of prompts to enter their class and then
gets a number of statistics at the end.

The user first gives the size of the class.  Then the
program creates an array of students, which the user
fills in one by one. Each student has an ID, name and grade.
Once all the students have been
entered the information of all the students plus the
grade distribution prints out.

Important: The program will only read one name for a student.
You can't enter someones full name.  For example you can enter
"Dani" but if you enter "Dani McAvoy" it will only read the Dani.

The program will only exit if you type 0 for the number
of students. Typing 0 anywhere else will not exit the program.

Also the program will change any input to the ID to a number if it
is not already a number.


@author Danielle McAvoy
@date September 26 2011

 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH_NAME 16
#define NUM_GRADES 5

// A student consists of a name, ID and grade.
struct student{
    char name[MAX_LENGTH_NAME];
    int ID;
    char grade;
};

// Variable to hold the size of the class when
// the user inputs it.
int classSize = -1;


//*ARRAYS*

// Array of students.  Size is decided by user at
// at run time.
struct student *myClass;

// Which keep track of the number of each grade
int gradeAmount[NUM_GRADES] = {0};

// Keeps track of the different grades
char grades[NUM_GRADES] = { 'A', 'B', 'C', 'D', 'F'};


//*FUNCTIONS*

// Prints the welcome message
void welcome(void);

// Gets the Class Size from the user
int askClassSize(void);

// Fills the array with all the student information
void fillStudentArray(int classSize);

// Gets the student information from the user
void askStudentName(char* name);
char askStudentGrade(void);
int askStudentID();

// Prints information on every student and
// then class statistics on grades
void printClassStats(void);

// Resets all the values for grades counts to 0
void resetGrades(void);

// Cleans up user input after scanf runs
void flush_stdin();
