/* Mastring Embedded System Diploma 
   Project-1 (Pressure Detection)
   Sturtup file
   Eng: Kareem Abdelkader
*/

.section .vectors          /* All next inst will be in vector section */

.word 0x20001000           /* stack top address */
.word _reset               /* 1- Reset */
.word Vector_handler       /* 2- NMI   */
.word Vector_handler       /* 3- Hard fualt */
.word Vector_handler       /* 4- MM fault */
.word Vector_handler       /* 5- Bus fault */
.word Vector_handler       /* 6- Usage fault */
.word Vector_handler       /* 7- Reserved */
.word Vector_handler       /* 8- Reserved */
.word Vector_handler       /* 9- Reserved */
.word Vector_handler       /* 10- Reserved */
.word Vector_handler       /* 11- SV call */
.word Vector_handler       /* 12- Debug reserved */
.word Vector_handler       /* 13- Reserved */
.word Vector_handler       /* 14- Pend SV  */
.word Vector_handler       /* 15- SysTick  */
.word Vector_handler       /* 16- IRQ0 */
.word Vector_handler       /* 17- IRQ1 */
.word Vector_handler       /* 18- IRQ2 */
.word Vector_handler       /* 19- .... */


.section .text
_reset:
	bl main            /* branch to the main */
	bl .

.thumb_func
Vector_handler:            /* Any interrupt handler */
	bl _reset
