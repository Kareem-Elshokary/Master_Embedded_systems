/*
 * Student.c
 *
 *  Created on: Sep 10, 2023
 *      Author: KARIM
 */

#include"Student.h"

fifo_status fifo_init(fifo_t* fifo, S_info* student, int S_length){
	//Check if fifo is excite
	if( !fifo )
		return Null;

	fifo->base = student;
	fifo->head = student;
	fifo->tail = student;
	fifo->count = 0;
	fifo->length = S_length;

	return No_Error;
}

fifo_status Enqueue(fifo_t* fifo, S_info item){
	//Check if fifo is null
	if( !fifo->base || !fifo->head || !fifo->tail )
		return Null;

	//Check if fifo is full
	if( fifo->count == fifo->length )
		return Full;

	//Add the item
	*(fifo->head) = item;
	fifo->count++;
	if( fifo->head == (fifo->base + (fifo->length * sizeof(S_info))))
		fifo->head = fifo->base;
	else
		fifo->head++;

	return No_Error;
}

fifo_status Dequeue(fifo_t* fifo, S_info* item){
	//Check if fifo is null
	if( !fifo->base || !fifo->head || !fifo->tail )
		return Null;

	//Check if it empty
	if( fifo->count == 0 )
		return Empty;

	//Get the item
	*item = *(fifo->tail);
	fifo->count--;
	if( fifo->head == (fifo->base + (fifo->length * sizeof(S_info))))
		fifo->head = fifo->base;
	else
		fifo->head++;

	return No_Error;
}


fifo_status Add_Student_Manually(fifo_t* fifo){

	//Check if fifo is full
	if( fifo->count == fifo->length ){
		print("Sorry... The list is full \n")
				return Full;
	}

	Element_type New_student;
	Element_type* ptr_student = fifo->tail;
	int i;
	print("... Enter the details of the student ... \n")
	print("Enter the ID: \n")
	scanf("%d",&New_student.id);
	for(i=0; i<fifo->count; i++){
		if( ptr_student->id == New_student.id){
			print("you entered an exist ID \n")
					return Error;
		}
		if( ptr_student == (fifo->base + (fifo->length * sizeof(Element_type)))){
			ptr_student = fifo->base;
		}
		else{
			ptr_student++;
		}
	}

	print("Enter the first name: \n")
	scanf("%s",New_student.first_name);
	print("Enter the last name: \n")
	scanf("%s",New_student.last_name);
	print("Enter the GPA: \n")
	scanf("%f",&New_student.GPA);
	for(i=0; i<5; i++){
		print("Enter course%d id: \n",i+1)
				scanf("%d",&New_student.course_id[i]);
	}

	if( Enqueue(fifo, New_student) == No_Error){
		print("...Add the student successfully... \n")
				return No_Error;
	}
	else{
		print("...Cann't add the student... \n")
				return Error;
	}
}

fifo_status Add_Student_ByFile(fifo_t* fifo){
	//Check if fifo is full
	if( fifo->count == fifo->length ){
		print("Sorry... The list is full \n")
					return Full;
	}


	FILE* fptr;
	fptr = fopen("Students.txt","r");
	char ch[500];
	Element_type New_student ;
	Element_type* ptr_student = fifo->tail;
	int i;

	if( fptr == NULL){
		print("...Cann't open the file... \n")
				return Error;
	}

	while(fgets(ch,500,fptr)){
		fscanf(fptr,"%d %s %s %f %d %d %d %d %d",&New_student.id,New_student.first_name,New_student.last_name,
				&New_student.GPA, &New_student.course_id[0], &New_student.course_id[1], &New_student.course_id[2],
				&New_student.course_id[3], &New_student.course_id[4]);

		for(i=0; i<fifo->count; i++){
				if( ptr_student->id == New_student.id){
					print("you entered an exist ID \n")
							return Error;
				}
				if( ptr_student == (fifo->base + (fifo->length * sizeof(Element_type)))){
					ptr_student = fifo->base;
				}
				else{
					ptr_student++;
				}
			}

		if( Enqueue(fifo, New_student) == No_Error){
			print("...Add is successfully... \n")
		}
		else{
			return Error;
		}
	}

	fclose(fptr);
	return No_Error;
}

fifo_status Find_Student_ByName(fifo_t* fifo){

	//Check if it empty
	if( fifo->count == 0 )
		return Empty;

	S_info* ptr_student = fifo->tail;
	int i, counter = 0;
	char name[25];

	print("Enter the name you want to search: \n")
	scanf("%s",name);
	for(i=0; i<fifo->count; i++){
		if( strcmp(ptr_student->first_name, name) == 0){
			print("The name is: %s %s \n",ptr_student->first_name,ptr_student->last_name)
			print("The ID: %d \n",ptr_student->id)
			print("The GPA: %f \n",ptr_student->GPA)
			for(i=0; i<5; i++){
				print("The Course%d : %d \n",i+1,ptr_student->course_id[i])
			}
		}
		else{
			counter++;
		}
		if( (ptr_student+1) == (fifo->base + fifo->length)){
			ptr_student = fifo->base;
		}
		else{
			ptr_student++;
		}
	}
	if( counter == fifo->count ){
		print("Sorry... The name not found \n")
				return Error;
	}
	return No_Error;
}

fifo_status Find_Student_ByID(fifo_t* fifo, int num){
	//Check if it empty
	if( fifo->count == 0 )
		return Empty;

	Element_type* ptr_student = fifo->tail;
	int i, counter = 0;


	for(i=0; i<fifo->count; i++){
		if( num == ptr_student->id ){
			print("The name is: %s %s \n",ptr_student->first_name,ptr_student->last_name)
			print("The ID: %d \n",ptr_student->id)
			print("The GPA: %f \n",ptr_student->GPA)
			for(i=0; i<5; i++){
				print("The Course%d : %d \n",i+1,ptr_student->course_id[i])
			}
		}
		else{
			counter++;
		}
		if( (ptr_student+1) == (fifo->base + fifo->length) ){
			ptr_student = fifo->base;
		}
		else{
			ptr_student++;
		}
	}
	if( counter == fifo->count ){
		print("Sorry... the Id not found \n")
								return Error;
	}

	return No_Error;
}

fifo_status Count_of_Students(fifo_t* fifo){

	//Check if it empty
	if( fifo->count == 0 ){
		print("Sorry... No student \n")
								return Empty;
	}

	int i, counter = 0;
	for(i=0; i<fifo->count; i++){
		counter++;
	}
	print("The total number of students is %d \n",counter)
	return No_Error;
}

fifo_status TheCourses(fifo_t* fifo)
{
	if( fifo->count == 0 ){
		print("Sorry... The list is empty \n")
		return Error;
	}

	int number, i, j, counter;
	Element_type* ptr_student = fifo->tail;
	print("Enter the course ID (1:10) : \n")
	scanf("%d",&number);
	for(i=0; i<fifo->count; i++){
		for(j=0; j<5; j++){
			if( ptr_student->course_id[j] == number )
				counter++;
		}
		if( ptr_student == (fifo->base + fifo->length * sizeof(Element_type)))
			ptr_student = fifo->base;

		else
			ptr_student++;
	}

	print("The number of students in this course is %d \n",counter)
	return No_Error;
}


fifo_status Delete_Student(fifo_t* fifo){

	//Check if it empty
	if( fifo->count == 0 ){
		print("The list is empty \n")
								return Empty;
	}

	int id, i;
	print("Enter the student ID: \n")
	scanf("%d",&id);
	Element_type* ptr_student = fifo->tail;

	for(i=0 ; i< fifo->count ; i++)
	{
		if(ptr_student->id == id)
			break;

		if( ptr_student == (fifo->base + fifo->length * sizeof(Element_type)))
			ptr_student = fifo->base;

		else
			ptr_student++;
	}

	if( i == fifo->count ){
		print("Sorry... No student has this id \n")
				return Error;
	}
	else{
		if( Dequeue(fifo, ptr_student) == No_Error) {
			print("It deleting successfully \n")
		}
		else{
			print("Deleting failed \n")
					return Error;
		}
	}
	return No_Error;
}

fifo_status Update_student_info(fifo_t* fifo){

	//Check if it empty
	if( fifo->count == 0 ){
		print("Sorry... No student \n")
				return Empty;
	}

	int i, choise, id;
	print("Enter the student ID: \n")
	scanf("%d",&id);
	Element_type* ptr_student = fifo->tail;
	for(i=0; i<fifo->count; i++){
		if( ptr_student->id == id ){
			print("1. Update the first name \n")
					print("2. Update the last name \n")
					print("3. Update the ID \n")
					print("4. Update the GPA \n")
					print("5. Update the courses \n")
					print("Choose the operation to do: \n")
					scanf("%d",&choise);
			switch(choise){
			case 1: {
				print("Enter the new name \n")
						scanf("%s",ptr_student->first_name);
			}
			break;
			case 2: {
				print("Enter the new name \n")
						scanf("%s",ptr_student->last_name);
			}
			break;
			case 3: {
				print("Enter the new ID \n")
						scanf("%d",&ptr_student->id);
			}
			break;
			case 4: {
				print("Enter the new GPA \n")
						scanf("%f",&ptr_student->GPA);
			}
			break;
			case 5: {
				for(i=0; i<5; i++){
					print("Enter the course%d id \n",i+1)
							scanf("%d",&ptr_student->course_id[i]);
				}
			}
			break;
			default : {
				print("...Wrong choice...")
			}
			break;
			}
			print("Update successfully \n")
		}

		if( ptr_student == (fifo->base + (fifo->length * sizeof(Element_type))) )
			ptr_student = fifo->base;
		else
			ptr_student++;
	}

	if( i == fifo->count ){
		print("Sorry... The ID is not found \n")
				return Error;
	}

	return No_Error;
}

fifo_status Print_All_Data(fifo_t* fifo){

	//Check if it empty
	if( fifo->count == 0 ){
		print("Sorry... No students to show \n")
		return Empty;
	}

	Element_type* ptr_student = fifo->tail;
	int i;
	for(i=0; i<fifo->count; i++){
		print("Student%d info: \n",i+1)
		print("The name is: %s %s \n",ptr_student->first_name,ptr_student->last_name)
		print("The ID: %d \n",ptr_student->id)
		print("The GPA: %f \n",ptr_student->GPA)
		for(i=0; i<5; i++){
			print("The Course%d : %d \n",i+1,ptr_student->course_id[i])
		}

		if( ptr_student == (fifo->base + (fifo->length * sizeof(Element_type))) ){
			ptr_student = fifo->base;
		}
		else{
			ptr_student++;
		}
	}

	return No_Error;
}


