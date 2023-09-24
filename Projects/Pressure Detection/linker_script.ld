/* Mastring Embedded System Diploma 
   Unit2 - Lesson3 - Lab2
   Linker_Script file
   Eng: Kareem Abdelkader
*/

MEMORY            /* Memory Map */
{
	flash(RX) : ORIGIN = 0x00000000, LENGTH = 512M
	sram(RWX) : ORIGIN = 0x20000000, LENGTH = 512M
}

SECTIONS
{
	.text : {
		*(.vectors*)     /* Vector handler will be in text section    */ 
		*(.text*)
		*(.rodata)       /* Global const data will be in text section */
		_E_text = . ;    /* End of the text section.                  */
	}> flash                 /* Create in ROM.                            */

	.data : {
		_S_DATA = . ;    /* The start of .data section.               */
		*(.data)
		. = ALIGN(4) ;
		_E_DATA = . ;    /* End of the .data section.                 */
	}> sram AT> flash        /* Create in ROM and send data to RAM at run time */

	.bss : {
		_S_bss = . ;     /* The start of .bss section.                */ 
		*(.bss*)
		_E_bss = . ;     /* End of the .bss section.                  */
	}> sram                  /* Create in RAM.                            */
}