/*
 * Struct_lab2.c
 *
 *  Created on: Apr 6, 2023
 *      Author: KARIM
 */

#include <stdio.h>
#include <string.h>

struct SDate {
	int Day;
	int Month;
	int Year;
};

struct SEmployee {
	char name[30];
	struct SDate BirthDate;
	struct SDate GraduationDate;
	int salary;
};

int main(){
	struct SEmployee X[5], temp;
	char name[30];
	int i,j;

	// Get Employee Data
	for(i=0; i<5; i++){
		printf("%d) Enter Name: \t",i+1);
		fflush(stdin); fflush(stdout);
		fgets(name,30,stdin);
		strcpy(X[i].name,name);

		printf("Enter Birth date (dd/mm/yy) \t");
		fflush(stdin); fflush(stdout);
		scanf("%d %d %d",&X[i].BirthDate.Day ,&X[i].BirthDate.Month ,&X[i].BirthDate.Year);

		printf("Enter Graduation date (dd/mm/yy) \t");
		fflush(stdin); fflush(stdout);
		scanf("%d %d %d",&X[i].GraduationDate.Day ,&X[i].GraduationDate.Month ,&X[i].GraduationDate.Year);

		printf("Enter Salary \t");
		fflush(stdin); fflush(stdout);
		scanf("%d",&X[i].salary);

		printf("\n");
	}

	// Sort Employee by Birth Date
	for(i=0; i<5; i++){
		for(j=1; j<10; j++){
			if(X[i].BirthDate.Year>X[j].BirthDate.Year || (X[i].BirthDate.Year==X[j].BirthDate.Year && X[i].BirthDate.Month>X[j].BirthDate.Month) ||
			(X[i].BirthDate.Year==X[j].BirthDate.Year && X[i].BirthDate.Month==X[j].BirthDate.Month && X[i].BirthDate.Day>X[j].BirthDate.Day)){
				temp = X[i];
				X[i] = X[j];
				X[j] = temp;
			}
		}
	}

	// Print the Result
	for(i=0; i<5; i++){
		printf("%s (%d/%d/%d) (%d/%d/%d) %d \n",X[i].name ,X[i].GraduationDate.Day ,X[i].BirthDate.Month ,X[i].BirthDate.Year ,X[i].GraduationDate.Day
				,X[i].GraduationDate.Month ,X[i].GraduationDate.Year ,X[i].salary);
	}

	return 0;
}
