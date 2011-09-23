
GradeBook: cWarmUp.o
	gcc -o GradeBook cWarmUp.o
cWarmUp.o: cWarmUp.h
	gcc -c cWarmUp.c
clean:
	rm *.o