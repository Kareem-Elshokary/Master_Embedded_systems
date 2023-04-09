/*
 * Struct_Ex3.c
 *
 *  Created on: Apr 6, 2023
 *      Author: KARIM
 *  C function to adding to complex numbers
 */

#include<stdio.h>

struct Scomplex {
	int real;
	int complex;
};

struct Scomplex  ReadNumber (){
	struct Scomplex N;
	printf("Enter the number (r,c): \n");
	fflush(stdin); fflush(stdout);
	scanf("%d %d",&N.real ,&N.complex);

	return N;
}

struct Scomplex Add (struct Scomplex A, struct Scomplex B){
	struct Scomplex N3;
	N3.real = A.real + B.real;
	N3.complex = A.complex + B.complex;

	return N3;
}

int main(){
	struct Scomplex N1, N2, N3;
	N1 = ReadNumber();
	N2 = ReadNumber();
	N3 = Add(N1,N2);
	printf("Result = %d + j%d",N3.real, N3.complex);

	return 0;
}
