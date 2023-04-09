/*
 * Ex8.c
 *
 *  Created on: Mar 14, 2023
 *      Author: KARIM
 *  Simple Calculator (+\-\*\/)
 */
#include<stdio.h>

int main(){

	float a,b,result;
	char op;
	printf("Enter two Integers: \n");
	fflush(stdin); fflush(stdout);
	scanf("%f %f",&a,&b);
	printf("Choose operation: \n");
	fflush(stdin); fflush(stdout);
	scanf("%c",&op);

	switch(op){
	case '+':
	{ result = a+b;
	  printf("result = %f",result); }
	break;

	case '-':
	{ result = a-b;
	  printf("result = %f",result); }
	break;

	case '*':
	{ result = a*b;
	  printf("result = %f",result); }
	break;

	case '/':
	{ result = a/b;
	  printf("result = %f",result);}
	break;
	default :
		printf("wrong operation");
		break;

	}
	return 0;
}


