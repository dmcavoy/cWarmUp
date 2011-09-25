/*
The implemenation of the class database.
 */

#include "cWarmUp.h"

// Runs through filling the class "database" with information
int main (void){
  welcome();
  while(classSize){
    classSize = askClassSize();
    if (classSize == 0){
      return 0;
    }
    fillStudentArray(classSize);
    printClassStats();
    free(myClass);
  }
  return 0;
};

void welcome(void){
  printf("Welcome. This program is to help you keep track of all your students. \n");
  printf("Just follow the prompts! \n");
};


void flush_stdin() {
  char c;
  while((c = getchar()) != '\n');
};

int askClassSize(void){
  int classNumber;
  printf("How many students are in this class? \n");
  printf("Enter the number of students: ");
  scanf("%d", &classNumber);
  printf("\n");
  flush_stdin();
  return classNumber;
};

void fillStudentArray(int classSize){
  myClass = (struct student*) calloc(classSize, sizeof(struct student));
  int j;
  for(j=0 ; j < classSize; j++){
    askStudentName(myClass[j].name);
    myClass[j].ID = askStudentID();
    myClass[j].grade = askStudentGrade();
    printf("\n");
  }
};

void askStudentName(char* name){
  printf("Enter the student's name: ");
  scanf("%s", name);
  flush_stdin();
};

int askStudentID(void){
  int ID;
  printf("Enter the student's ID: ");
  scanf("%d", &ID);;
  flush_stdin();
  return ID;
};
char askStudentGrade(void){
  char grade;

  printf("Enter the student's grade: ");
  scanf("%c", &grade);
  flush_stdin();

  switch(grade){
  case 'A':
    grades[0]++;
    break;
  case 'B':
    grades[1]++;
    break;
  case 'C':
    grades[2]++;
    break;
  case 'D':
    grades[3]++;
    break;
  case 'F':
    grades[4]++;
    break;
  default:
    printf("Not a real grade try again");
    printf("\n");
    grade = askStudentGrade();
    break;
  }

  return grade;

};

void printClassStats(void){

  printf("*STUDENTS*\n");
  int i;
  for(i= 0 ; i < classSize ; i++){
    printf("%s \n", myClass[i].name);
    printf("ID: %d \n", myClass[i].ID);
    printf("Grade: %c \n", myClass[i].grade);
    printf("\n");
  }
  printf("GRADE DISTRIBUTION \n");
  printf("Number of As: %d \n", grades[0]);
  printf("Number of Bs: %d \n", grades[1]);
  printf("Number of Cs: %d \n", grades[2]);
  printf("Number of Ds: %d \n", grades[3]);
  printf("Number of Fs: %d \n", grades[4]);
  resetGrades();
  printf("\n");

};

void resetGrades(void){
  int i;
  for( i=0 ; i< NUM_GRADES ; i++){
    grades[i] = 0;
  }
};
