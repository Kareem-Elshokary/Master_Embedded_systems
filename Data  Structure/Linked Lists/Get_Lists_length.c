/*
 * Get_Lists_length.c
 *
 *  Created on: May 11, 2023
 *      Author: KARIM
 */


#include"stdio.h"
#include"stdlib.h"

#define DPrint(...)  fflush(stdin);\
			         fflush(stdout);\
                     printf(__VA_ARGS__);\
                     fflush(stdin);\
			         fflush(stdout);

struct SData {
	unsigned int data;
	struct SData* p_Next;
};

struct SData* gp_FirstData = NULL;
int Length_Of_lists();

int main(){
	//Initialization of nodes
	struct SData* data1;
	struct SData* data2;
	struct SData* data3;
	struct SData* data4;

	//Allocate memory
	data1 = (struct SData*) malloc (sizeof(struct SData));
	data2 = (struct SData*) malloc (sizeof(struct SData));
	data3 = (struct SData*) malloc (sizeof(struct SData));
	data4 = (struct SData*) malloc (sizeof(struct SData));

	//Assign data
	data1->data = 10;
	data2->data = 20;
	data3->data = 30;
	data4->data = 40;

	//Connecting nodes
	data1->p_Next = data2;
	data2->p_Next = data3;
	data3->p_Next = data4;
	data4->p_Next = NULL;
	gp_FirstData = data1;

	DPrint("Node1 : %d \n",data1->data)
	DPrint("Node2 : %d \n",data2->data)
	DPrint("Node3 : %d \n",data3->data)
	DPrint("Node4 : %d \n",data4->data)

	int result = Length_Of_lists(gp_FirstData);
	DPrint("Length = %d",result)

	return 0;
}

int Length_Of_lists( struct SData* gp_FirstData ){
	if( gp_FirstData == NULL)
		return 0;
	else
		return 1 + Length_Of_lists(gp_FirstData->p_Next);
}


