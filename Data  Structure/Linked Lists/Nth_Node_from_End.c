/*
 * Nth_Node_from_End.c
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

//Add New Data
void Add_NewData( struct SData** p_Data, int data){
	struct SData* p_NewData = (	struct SData* ) malloc (sizeof(	struct SData));
	p_NewData->data = data;
	p_NewData->p_Next = *p_Data;
	*p_Data = p_NewData;
}

//Print the data of the list
void Print(){
	struct SData* p_Current = gp_FirstData;
	while( p_Current != NULL ){
		DPrint("Node = %d \n",p_Current->data)
		p_Current = p_Current->p_Next;
	}
}

//Get_Nth_Node_From_End
struct SData* Get_Nth_Node_From_End( struct SData* gp_FirstData, int pos){
	struct SData* p_ref = gp_FirstData;
	struct SData* p_main = gp_FirstData;

	//Check if list empty
	if( gp_FirstData == NULL)
		return NULL;

	for(int i=0; i<pos; i++){
		p_ref = p_ref->p_Next;
	}
	while( p_ref != NULL){
		p_ref = p_ref->p_Next;
		p_main = p_main->p_Next;
	}
	return p_main;
}

int main(){
	//Initialization the list
	Add_NewData(&gp_FirstData, 10);
	Add_NewData(&gp_FirstData, 20);
	Add_NewData(&gp_FirstData, 30);
	Add_NewData(&gp_FirstData, 40);
	Add_NewData(&gp_FirstData, 50);
	Add_NewData(&gp_FirstData, 60);

	//Print the list
	Print();

	int pos;
	DPrint("Enter the position: \n")
	scanf("%d",&pos);

	struct SData* ptr = Get_Nth_Node_From_End(gp_FirstData, pos);
	if( ptr == NULL ){
		DPrint("Sorry....Node not found \n")
	}
	else{
		DPrint("Node found with data = %d \n",ptr->data)
	}

	return 0;
}
