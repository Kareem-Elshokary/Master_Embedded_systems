/*
 * Ptr_Ex2.c
 *
 *  Created on: Apr 14, 2023
 *      Author: KARIM
 *  a program in C to print all the alphabets using a pointer.
 */

#include<stdio.h>

int main(){
	char str[27];
	char* p = str;
	int i=0 ;

	for(i=0; i<26; i++){
		*p = i + 'A';
		p++;
	}

	p = str;
	for(i=0; i<26; i++){
		printf("%c \t",*p);
		p++;
	}

	return 0;
}
