#include "Uart.h"

unsigned char string_buffer[100] = "learn-in-depth: <Kareem Abdelkader>";

void main (void)
{

  Uart_Send_string(string_buffer);

}