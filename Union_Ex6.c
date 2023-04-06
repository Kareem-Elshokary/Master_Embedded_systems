/*
 * Union_Ex6.c
 *
 *  Created on: Apr 6, 2023
 *      Author: KARIM
 */

#include<string.h>

union Ujob{
	char name[32];
	float salary;
	int worker_no;
}u;

struct Sjob{
	char name[32];
	float salary;
	int worker_no;
}s;

int main(){
	printf("Size of union = %d\n",sizeof(u));
	printf("Size of struct = %d",sizeof(s));

	return 0;
}
