/*
 * Project.c
 *
 *  Created on: Sep 10, 2023
 *      Author: KARIM
 *
 *  The student management system is designed to be used in
 *  operations on data through addition, deletion or modification
 *  using queue data structure (FIFO).
 *
 */

#include"Student.h"

int main(){
	fifo_t FIFO_Data;
	Element_type Student[55];
	int choise, number;

	if( fifo_init(&FIFO_Data, Student, 55) == No_Error )
		printf("...Work Successfully... \n");

	while(1){
		print("...Welcome to Student Management System... \n")
		print("1. Enter a student manually \n")
		print("2. Enter a student by text file \n")
		print("3. Find a student by name \n")
		print("4. Find a student by ID \n")
		print("5. The total number of the students \n")
		print("6. Delete a student \n")
		print("7. Update a student details \n")
		print("8. Show the courses \n")
		print("9. Print all the content \n ")
		print("10. Exit \n")
		print("Enter your choise: \n")
		scanf("%d",&choise);

		switch(choise){
		case 1: { Add_Student_Manually(&FIFO_Data); }
		break;
		case 2: { Add_Student_ByFile(&FIFO_Data); }
		break;
		case 3: { Find_Student_ByName(&FIFO_Data); }
		break;
		case 4: {
			print("Enter the ID that you want to search for:")
			scanf("%d",&number);
			Find_Student_ByID(&FIFO_Data,number); }
		break;
		case 5: { Count_of_Students(&FIFO_Data); }
		break;
		case 6: { Delete_Student(&FIFO_Data); }
		break;
		case 7: { Update_student_info(&FIFO_Data); }
		break;
		case 8: { TheCourses(&FIFO_Data); }
		break;
		case 9: { Print_All_Data(&FIFO_Data); }
		break;
		case 10: { exit(0); }
		break;
		default : { printf("...Wrong Choise... \n");}
		break;
		}
	}


	return 0;
}
