#ifndef  PRESSURE_SENSOR_H
#define  PRESSURE_SENSOR_H



typedef enum {
	low,
	high,
}P_state;


P_state Check_P_val();

#endif