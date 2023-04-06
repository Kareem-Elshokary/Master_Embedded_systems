/*
 * Struct_Ex2.c
 *
 *  Created on: Apr 6, 2023
 *      Author: KARIM
 *  C program to add two distances (inch-feet)
 */

#include<stdio.h>

struct Sdistance{
	float inch;
	float feet;
};

int main(){
	struct Sdistance D1, D2, D3;

	printf("Enter First distance \n");
	printf("Enter inch: \t\n Enter feet: \t\n");
	fflush(stdin); fflush(stdout);
	scanf("%f %f",&D1.inch ,&D1.feet);
	printf("Enter second distance \n");
	printf("Enter inch: \t Enter feet: \t\n");
	fflush(stdin); fflush(stdout);
	scanf("%f %f",&D2.inch ,&D2.feet);

	//Adding distances
	D3.inch = D1.inch + D2.inch;
	D3.feet = D1.inch + D2.feet;
	while(D3.inch >= 12.0){
		D3.inch -= 12.0;
		++D3.feet;
	}
	printf("Sum of distances = %f-%f ",D3.inch,D3.feet);

	return 0;
}
