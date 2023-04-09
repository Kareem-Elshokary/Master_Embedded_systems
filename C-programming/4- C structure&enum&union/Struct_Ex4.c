/*
 * Struct_Ex4.c
 *
 *  Created on: Apr 6, 2023
 *      Author: KARIM
 *  Displaying informations of student group
 */

#include<stdio.h>
#include<string.h>

struct Sstudent{
	char name[20];
	float mark;
}S[10];

int main(){
	int i=0;
	char name[20];

	//Get informations
	while(i<10){
		printf("for roll n%d \n",i+1);
		printf("Enter name: \n");
		fflush(stdin); fflush(stdout);
		fgets(name,sizeof(name),stdin);
		strcpy(S[i].name,name);

		printf("Enter mark: \n");
		fflush(stdin); fflush(stdout);
		scanf("%f",&S[i].mark);

		i++;
	}

	//Display information
	for(i=0; i<10; i++){

		printf("roll %d: \n",i+1);
		printf("%s %.2f\n",S[i].name ,S[i].mark);
	}

	return 0;
}

