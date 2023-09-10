/*
 * Student.h
 *
 *  Created on: Sep 10, 2023
 *      Author: KARIM
 */

#ifndef STUDENT_H_
#define STUDENT_H_

#include<stdio.h>
#include<string.h>


#define print(...) fflush(stdin);\
	                fflush(stdout);\
	                printf(__VA_ARGS__);\
	                fflush(stdin);\
	                fflush(stdout);
// choose data type (int, char, float, ...)
#define Element_type S_info


//Informations of the student
typedef struct {
	char first_name[30];
	char last_name[30];
	int id;
	float GPA;
	int course_id[5];
}S_info;

//Initialization of fifo buffer
typedef struct {
	int length;
	int count;
	Element_type* head;
	Element_type* base;
	Element_type* tail;
}fifo_t;

typedef enum {
	Error,
	No_Error,
	Full,
	Empty,
	Null,
}fifo_status;



//APIs

fifo_status fifo_init(fifo_t* fifo, S_info* student, int S_length); //initialization of the fifo
fifo_status Enqueue(fifo_t* fifo, S_info item);                     //Add an item
fifo_status Dequeue(fifo_t* fifo, S_info* item);                    //Get an item


fifo_status Add_Student_Manually(fifo_t* fifo);
fifo_status Add_Student_ByFile(fifo_t* fifo);
fifo_status Find_Student_ByName(fifo_t* fifo);
fifo_status Find_Student_ByID(fifo_t* fifo, int num);
fifo_status TheCourses(fifo_t* fifo);
fifo_status Count_of_Students(fifo_t* fifo);
fifo_status Delete_Student(fifo_t* fifo);
fifo_status Update_student_info(fifo_t* fifo);
fifo_status Print_All_Data(fifo_t* fifo);



#endif /* STUDENT_H_ */
