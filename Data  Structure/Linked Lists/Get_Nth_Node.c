/*
 * Get_Nth_Node.c
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

struct Sdata {
	unsigned int data;
	struct Sdata* p_Next;
};

struct Sdata* gp_FirstData = NULL;

void Get_Nth_Node();

int main(){
	//Initialization of nodes
	struct Sdata* data1;
	struct Sdata* data2;
	struct Sdata* data3;
	struct Sdata* data4;

	//Allocate memory
	data1 = (struct Sdata*) malloc (sizeof(struct Sdata));
	data2 = (struct Sdata*) malloc (sizeof(struct Sdata));
	data3 = (struct Sdata*) malloc (sizeof(struct Sdata));
	data4 = (struct Sdata*) malloc (sizeof(struct Sdata));

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
	Get_Nth_Node();

	return 0;
}

void Get_Nth_Node(){
	struct Sdata* p_Current = gp_FirstData;
	int count, selected_node;
	DPrint("Enter the selected node position: \n")
	scanf("%d",&selected_node);

	//Check if list is empty
	if( gp_FirstData == NULL){
		DPrint("List is Empty \n")
	}
	//if not empty
	else{
		//Loop through the List
		while( (p_Current != NULL) && (count != selected_node) ){
			p_Current = p_Current->p_Next;
			count++;
		}

			DPrint("Node %d = %d",selected_node,p_Current->data)

	}

}

