#include <stdio.h>
#include <stdlib.h>

typedef struct student{
	int id;
	int age;
}
student_t;

void printStudent(student_t* aStudent){
	printf("Student ID: %d, age: %d\n",aStudent->id, (*aStudent).age);
}

void updateStudent(student_t* aStudent,int id, int age){
	aStudent->id = id; // (*aStudent).id
	aStudent->age = age;
}

student_t* makeStudent(int age, int id){
	student_t* p_aStudent = (student_t*)malloc(sizeof(student_t));

	p_aStudent->age = age;
	p_aStudent->id = id;
	return p_aStudent;
}

int main(){
	student_t* s1 = makeStudent(23, 1001);
	student_t* s2 = makeStudent(24, 1002);

	//assign some values to s1 and s2;
	
	//s1.id = 1001;
	//s2.id = 1002;

	//s1.age = 23;
	//s2.age = 24;
	
	//updateStudent(&s1, 1001,23);
	//updateStudent(&s2, 1002,24);

	printStudent(s1);
	printStudent(s2);

	//printf("The student id is: %d\n,Age is: %d/n", s1.id, s1.age);
	//printf("The student id is: %d\n,Age is: %d/n", s2.id, s2.age);
       
	free(s1);
	free(s2);//free the memory. c does not have memory garbage collector
       	return 0;

}
