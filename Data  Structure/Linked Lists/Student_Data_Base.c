/*
 * main.c
 *
 *  Created on: May 10, 2023
 *      Author: KARIM
 *
 *  Create a Student Data Base by Linked Lists
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

#define DPrint(...)  fflush(stdin);\
			         fflush(stdout);\
                     printf(__VA_ARGS__);\
                     fflush(stdin);\
			         fflush(stdout);

//Informations
struct SData {
	char name[40];
	unsigned int ID;
	float height;
};

struct SStudent {
	struct SData Student;
	struct SStudent* PNext;
};

struct SStudent* gp_FirstStudent = NULL ;

void Fill_The_Record(struct SStudent* p_NewStudent){
	char temp[40];

	DPrint("Enter the full name: \n")
	gets(p_NewStudent->Student.name);

	DPrint("Enter the ID: \n")
	gets(temp);
	p_NewStudent->Student.ID = atoi (temp);

	DPrint("Enter the height: \n")
	gets(temp);
	p_NewStudent->Student.height = atof (temp);

}

void Add_Student(){
	struct SStudent* p_LastStudent;
	struct SStudent* p_NewStudent;

	//Check if the list is empty
	if( gp_FirstStudent == NULL){
		p_NewStudent = (struct SStudent*) malloc (sizeof(struct SStudent));
		gp_FirstStudent = p_NewStudent;
	}
	//Not empty
	else{
		//navigate until reach the last one
		p_LastStudent = gp_FirstStudent ;
		while(p_LastStudent){
			p_LastStudent = p_LastStudent->PNext;
		}
		p_NewStudent = (struct SStudent*) malloc (sizeof(struct SStudent));
		p_LastStudent->PNext = p_NewStudent;
	}

	Fill_The_Record(p_NewStudent);

	p_NewStudent->PNext = NULL;
}

void View_Records(){
	struct SStudent* p_CurrentRecord = gp_FirstStudent;
	int count = 0 ;
	//Check if the list is empty
	if( gp_FirstStudent == NULL){
		DPrint("Sorry.....The list is Empty \n")
	}
	else{
		while( p_CurrentRecord != NULL){
			DPrint("Record %d \n",count+1)
			DPrint("The Student name: %s\n",p_CurrentRecord->Student.name)
			DPrint("The student ID: %d \n",p_CurrentRecord->Student.ID)
			DPrint("The student height: %f \n",p_CurrentRecord->Student.height)
			p_CurrentRecord = p_CurrentRecord->PNext;
			count++;
		}
	}
}

int Delete_Element(){
	char temp[40];
	unsigned int Slected_id;

	//Get the id to be removed
	DPrint("Enter the ID:  \n")
	gets(temp);
	Slected_id = atoi (temp);

	if( gp_FirstStudent ){      //Check if list has records
		struct SStudent* p_Selected = gp_FirstStudent;
		struct SStudent* p_Previous = NULL;

		while( p_Selected){
			if(p_Selected->Student.ID == Slected_id ){
				if( p_Previous )
					p_Previous->PNext = p_Selected->PNext;
				else
					gp_FirstStudent = p_Selected->PNext;
				free(p_Selected);
				return 1 ;      //Find it
			}
		}
		//Store the previous record pointer
		p_Previous = p_Selected;
		p_Selected = p_Selected->PNext;
	}

	//Not find the ID
	DPrint("Sorry........Cannot find the ID")
	return 0;
}

void Delete_All(){
	struct SStudent* p_Current = gp_FirstStudent;
	if( gp_FirstStudent == NULL ){
		DPrint("Empty List \n")
	}
	else{
		while( p_Current ){
			struct SStudent* p_temp = p_Current;
			p_Current = p_Current->PNext;
			free(p_temp);
		}
	}
	gp_FirstStudent = NULL;

}



int main(){
	char temp[5];

	while(1){
		DPrint("\n......Choose one of this options...... \n")
		DPrint("1- Add new student \n")
		DPrint("2- View the records \n")
		DPrint("3- Delete a student \n")
		DPrint("4- Delete all \n")
		DPrint("Enter the option number: \n")
		gets(temp);

		switch( atoi(temp) ){
		case 1 :
			Add_Student();
			break;
		case 2 :
			View_Records();
			break;
		case 3 :
			Delete_Element();
			break;
		case 4 :
			Delete_All();
			break;
		default :
			DPrint("Wrong option")
			break;
			}
	}

	return 0;
}


