/*
 * Enum_lab1.c
 *
 *  Created on: Apr 6, 2023
 *      Author: KARIM
 */

#include<stdio.h>

enum Week {
	sunday, monday, tuesday, wednesday, thursday, friday, satarday
};

int main(){
	enum Week today;
	today = sunday;

	for(int i=0; i<7; i++){
		printf("%d \n",today);
		today++;
	}

	printf("Size of Enum = %d",sizeof(sunday));

	return 0;
}
