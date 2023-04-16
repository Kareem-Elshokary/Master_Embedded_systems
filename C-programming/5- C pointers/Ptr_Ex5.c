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
	struct Semplywee emp1 ={"Kareem",1122}, emp2 ={"Ahmed",3344}, emp3 ={"Mostafa",5566};
	struct Semplywee *Parr[] = {&emp1, &emp2, &emp3};

	for(int i=0; i<3; i++){
		printf("%s \t%d \n",Parr[i]->name ,Parr[i]->ID);
	}

	return 0;
}
