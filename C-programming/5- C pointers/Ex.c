/*
 * ex.c
 *
 *  Created on: Mar 14, 2023
 *      Author: KARIM
 */

#include<stdio.h>

struct Sdata{
	unsigned int data1;
	unsigned char data2;
	unsigned short data3;
};
struct Sdata data;

int main(){
	data.data1 = 0xffffeeee;
	data.data2 = 0x22;
	data.data3 = 0xffee;

	char* p = &data;
	for(int i=0; i<sizeof(data); i++){
		printf("%x \t %x \n",p, (unsigned char)*p);
		p++;
	}

	struct Sdata* Pdata = &data;
	Pdata->data1 = 0x33;
	Pdata->data2 = 0x12;
	Pdata->data3 = 0x11;
	printf("\n %x %x %x ",Pdata->data1, Pdata->data2, Pdata->data3);
	return 0;
}
