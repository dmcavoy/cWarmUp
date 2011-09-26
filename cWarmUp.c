/*
The implemenation of the class database.
Contains the functions which create fill and free the
array of students.
 */

#include "cWarmUp.h"

// Runs through filling the class "database" with information
// Exits when classSize is 0
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
  printf("If you wish to exit type 0 for the number of students. \n");
};


void flush_stdin() {
  char c;
  while((c = getchar()) != '\n');
};

int askClassSize(void){
  int classNumber;
  printf("How many students are in this class? \n");
  printf("Enter the number of students (or 0 to exit): ");
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
  int i;
  for (i=0; i < NUM_GRADES; i++){
    if (grade == grades[i]){
      gradeAmount[i]++;
      return grade;
    }
  }

  printf("Not a real grade try again");
  printf("\n");
  grade = askStudentGrade();

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
  int k, j;
  for ( k= 0, j=0; k < NUM_GRADES ; k++, j++){
    printf("Number of %cs: %d \n", grades[k], gradeAmount[j]);
  }

  resetGrades();
  printf("\n");

};

void resetGrades(void){
  int i;
  for( i=0 ; i< NUM_GRADES ; i++){
    gradeAmount[i] = 0;
  }
};
