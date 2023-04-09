/*
 * str_Ex1.c
 *
 *  Created on: Mar 18, 2023
 *      Author: KARIM
 *  Find the frequency of a character in a string
 */

#include<stdio.h>
#include<string.h>

int main(){
	int i,flag=0;
	char f, str[15];

	printf("Enter a string: \n");
	fflush(stdin); fflush(stdout);
	fgets(str,sizeof(str),stdin);

	printf("Enter a character to find the freq: \n");
	fflush(stdin); fflush(stdout);
	scanf("%c",&f);

	for(i=0; str[i]!='\0'; ++i){
		if(f==str[i]){
			++flag;
		}
	}
	printf("frequency is %d",flag);
	return 0;
}
