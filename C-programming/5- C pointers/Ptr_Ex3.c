/*
 * Ptr_Ex3.c
 *
 *  Created on: Apr 14, 2023
 *      Author: KARIM
 *  a program in C to print a string in reverse using a pointer
 */

#include<stdio.h>
#include<string.h>

int main(){
	char str[50];
	char rev[50];
	int i,j;
	char* ptr1 = str;
	char* ptr2 = rev;

	printf("Enter a string: \n");
	fflush(stdin);  fflush(stdout);
	fgets(str,50,stdin);

	for(i=0; i<strlen(str); i++){
		ptr1++;
	}

	for(i=strlen(str); i>=0; i--){
		for(j=0; j<strlen(str); j++){
			ptr1--;
			*ptr2 = *ptr1 ;
			ptr2++;
		}
	}

	ptr2 = rev;
	printf("%s",ptr2);

	return 0;
}
