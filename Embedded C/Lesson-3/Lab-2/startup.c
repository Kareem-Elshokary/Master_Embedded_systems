/*
Lesson4_Lab3
Eng. Kareem abdelkader
*/

#include<stdint.h>

void Reset_Handler() ;
extern int main() ;

void Defualt_Handler() {
	Reset_Handler() ;
}

void NMI_Handler()          __attribute__ ((weak, alias ("Defualt_Handler"))); ;
void H_Fault_Handler()      __attribute__ ((weak, alias ("Defualt_Handler"))); ;
void MM_Fault_Handler()     __attribute__ ((weak, alias ("Defualt_Handler"))); ;
void Bus_Fault()            __attribute__ ((weak, alias ("Defualt_Handler"))); ;
void Usage_Fault_Handler()  __attribute__ ((weak, alias ("Defualt_Handler"))); ;

//Booking 1024B located by .bss through unintialized array of int (256*4=1024)
static unsigned long Stack_top[256];

//Vectors section is an array of pointers to function
void (* const G_P_Fn_Vectors[])() __attribute__((section(".vectors"))) = {
	 (void (*)()) ((unsigned long) Stack_top + sizeof(Stack_top)),
       &Reset_Handler,
	 &NMI_Handler,
	 &H_Fault_Handler,
	 &MM_Fault_Handler,
	 &Bus_Fault,
	 &Usage_Fault_Handler
};

extern unsigned int _E_text ;
extern unsigned int _S_DATA ;  //Start of data section
extern unsigned int _E_DATA ;  //End of data section
extern unsigned int _S_bss ;   //Start of bss section
extern unsigned int _E_bss ;   //End of bss section

void Reset_Handler ()
{
	//Copy data section from flash to RAM
	unsigned int data_size = (unsigned char*)&_E_text - (unsigned char*)&_S_DATA ;
	unsigned char* P_src = (unsigned char*)&_E_text ;
	unsigned char* P_dst = (unsigned char*)&_S_DATA ;
	for(int i=0; i < data_size; i++){
		*((unsigned char*)P_dst++) = *((unsigned char*)P_src++);
	}

	//init .bss section in SRAM = 0
	unsigned int bss_size = (unsigned char*)&_E_bss - (unsigned char*)&_S_bss ;
	P_dst = (unsigned char*)&_S_bss ;
	for(int i=0; i < bss_size; i++){
		*((unsigned char*)P_dst++) = (unsigned char)0 ;
	}

	main() ;
}
