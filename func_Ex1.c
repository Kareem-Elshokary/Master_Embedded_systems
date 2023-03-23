/*
 * func_Ex1.c
 *
 *  Created on: Mar 23, 2023
 *      Author: KARIM
 *  Prime numbers between intervals
 */

#include<stdio.h>
int PrimeCheck (int a);

int main(){
	int n1,n2,i;
	printf("Enter two interval numbers: \n");
	fflush(stdin); fflush(stdout);
	scanf("%d %d",&n1,&n2);

	for(i=n1; i<n2; i++){
		if(PrimeCheck(i)==0){
			printf("%d \t",i);
		}
	}

	return 0;
}

int PrimeCheck (int a){
	int i,flag;
	for(i=2; i<=a/2; i++){
		if( a==0 || a==1 ){
			flag = 1;
		}
		else if(a%2 == 0){
			flag = 1;
		}
		else{
			flag = 0;
		}
	}
	return flag;
}
