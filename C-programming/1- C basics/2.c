/*
 * Ex2.c
 *
 *  Created on: Mar 14, 2023
 *      Author: KARIM
 *  Check vowel or consonant
 */

#include<stdio.h>

int main(){
	char alpha;
	printf("Enter a character: \n");
	fflush(stdin); fflush(stdout);
	scanf("%c",&alpha);

	if(alpha=='a' || alpha=='e' || alpha=='i' || alpha=='u' || alpha=='o'){
		printf("%c is vowel",alpha);
	}
	else{
		printf("%c is consonant",alpha);
	}

	return 0;
}


