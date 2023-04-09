/*
 * Struct_Ex1.c
 *
 *  Created on: Apr 6, 2023
 *      Author: KARIM
 *  Get student informations and display it
 */

#include<stdio.h>

struct Sstudent {
	char name[20];
	int roll;
	float degree;
};

int main(){
	struct Sstudent S;

	printf("Enter Name: \t");   //Get the studennt's name
	fflush(stdin); fflush(stdout);
	fgets(S.name,sizeof(S.name),stdin);

	printf("Enter roll number: \t");   //Get the student's roll
	fflush(stdin); fflush(stdout);
	scanf("%d",&S.roll);

	printf("Enter marks: \t");  //Get the student's mark
	fflush(stdin); fflush(stdout);
	scanf("%f",&S.degree);

	printf("Displaying informations \n");
	printf("name:%s \n roll:%d \n marks:%f",S.name,S.roll,S.degree);
	return 0;
}
