/*
 * Ptr_Ex5.c
 *
 *  Created on: Apr 14, 2023
 *      Author: KARIM
 *  a program in C to show a pointer to an array which contents are pointer to structure.
 */

#include<stdio.h>
#include<string.h>

struct Semplywee {
	char name[30];
	int ID;
};

int main(){
	struct Semplywee emp [3];
	struct Semplywee *Parr[3];
	int i;
	char name[30];

	Parr[0] = &emp[0];
	for(i=0; i<3; i++){
		Parr[i] = &emp[i];
	}

	for(i=0; i<3; i++){
		printf("Enter name: ");
		fflush(stdin);  fflush(stdout);
		fgets(name,30,stdin);
		strcpy(Parr[i]->name, name);

		printf("\nEnter ID: \t");
		fflush(stdin);  fflush(stdout);
		scanf("%d",&Parr[i]->ID);
	}

	for(int i=0; i<3; i++){
		printf("%s %d \n",Parr[i]->name ,Parr[i]->ID);
	}

	return 0;
}
