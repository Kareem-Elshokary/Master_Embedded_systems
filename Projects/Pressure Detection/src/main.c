#include <stdint.h>
#include <stdio.h>

#include "Driver.h"
#include "Pressure_sensor.h"
#include "Alarm.h"


int main (){
	GPIO_INITIALIZATION();
	while (1)
	{
		Check_P_val();
		
		if( Check_P_val() == low ){
			Alarm_Off();
			Delay(60000);
		}
		
		if( Check_P_val() == high ){
			Alarm_On();
			Delay(60000);
		}
	}

}
