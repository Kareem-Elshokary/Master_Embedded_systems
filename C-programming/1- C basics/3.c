/*
 * 3.c
 *
 *  Created on: Mar 16, 2023
 *      Author: KARIM
 *  Largest number among three numbers
 */

#include <stdio.h>

int main(){

	float x,y,z;
	printf("Enter three integers: \n");
	fflush(stdin); fflush(stdout);
	scanf("%f %f %f",&x,&y,&z);

	if( x>y && x>z){
		printf("%f is the largest ",x);
	}
	else if( y>x && y>z){
		printf("%f is the largest ",y);
	}
	else{
		printf("%f is the largest ",z);
	}

	return 0;
}
