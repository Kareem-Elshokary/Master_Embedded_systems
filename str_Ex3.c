/*
 * str_Ex3.c
 *
 *  Created on: Mar 18, 2023
 *      Author: KARIM
 *  Reverse a string
 */

#include<stdio.h>
#include<string.h>

int main(){
	char str[20],temp;
	int i, j;

	printf("Enter a string: \n");
	fflush(stdin); fflush(stdout);
	gets(str);

	i=0;
	j = strlen(str);
	while(i<j){
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}

	printf("Reverse string is %s",str);

	return 0;
}
