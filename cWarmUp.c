/*
The implemenation of the class database.
 */

#include "cWarmUp.h"


int main (void){
  welcome();
  classSize = askClassSize();
  fillStudentArray(classSize);
  printClassStats();
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
  printf("Enter the number of students \n");
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
  printf("Enter the student's name: \n");
  scanf("%s", name);
  flush_stdin();
};

int askStudentID(void){
  int ID;
  printf("Enter the student's ID: \n");
  scanf("%d", &ID);;
  flush_stdin();
  return ID;
};
char askStudentGrade(void){
  char grade;

  printf("Enter the student's grade: \n");
  scanf("%c", &grade);
  flush_stdin();

  switch(grade){
  case 'A':
    numberAs++;
    break;
  case 'B':
    numberBs++;
    break;
  case 'C':
    numberCs++;
    break;
  case 'D':
    numberDs++;
    break;
  case 'F':
    numberFs++;
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

  int i;
  for(i= 0 ; i < classSize ; i++){
    printf("\n");
    printf("%s \n", myClass[i].name);
    printf("ID: %d \n", myClass[i].ID);
    printf("Grade: %c \n", myClass[i].grade);
  }
  printf("\n");
  printf("Number of As: %d \n", numberAs);
  printf("Number of Bs: %d \n", numberBs);
  printf("Number of Cs: %d \n", numberCs);
  printf("Number of Ds: %d \n", numberDs);
  printf("Number of Fs: %d \n", numberFs);

};
