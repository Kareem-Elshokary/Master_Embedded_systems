#include "Pressure_sensor.h"
#include "Driver.h"

P_state Check_P_val(){

	int P_val = 0;
	int Threshold = 20;

	P_val = getPressureVal();
	
	if( P_val < Threshold ){
		return low;
	}
	else{
		return high;
	}
}