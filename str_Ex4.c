/*
 * str_Ex4.c
 *
 *  Created on: Mar 26, 2023
 *      Author: KARIM
 *  Take string and check it the same
 */

#include<stdio.h>
#include<string.h>

int main(){
	char str[20], name[20];

	printf("Enter a string \n");
	fflush(stdin); fflush(stdout);
	fgets(str,20,stdin);
	printf("Enter your name \n");
	fflush(stdin); fflush(stdout);
	fgets(name,20,stdin);

	if( stricmp(str,name) == 0){
		printf("identical");
	}
	else{
		printf("different");
	}

	return 0;
}
