/*
 * 9.c
 *
 *  Created on: Mar 26, 2023
 *      Author: KARIM
 *  Know 4th LSB in binary
 */

#include<stdio.h>

int main(){
	int n,c,k;

	printf("Enter a number = \n");
	fflush(stdin); fflush(stdout);
	scanf("%d",&n);

	printf("Number in binary : ");
	for(c=31; c>=0; c--){
		k = n >> c;
		if( k&1 )
			printf("1");
		else
			printf("0");
	}
	printf("\n");

	k = n>>3;
	if( k&1 )
		printf("1");
	else
		printf("0");


	return 0;
}
