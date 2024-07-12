/*
 * PDUFirmware.c
 *
 * Created: 5/15/2024 10:28:50 AM
 * Author : Admin
 */ 
# define F_CPU 8000000UL

#include <avr/io.h>
#include "AD.h"
#include "ntc_10k.h"
#include "status_led.h"
#include "temperature.h"
#include "uart.h"
#include "scheduler.h"
#include "COPC.h"
//#include "MCP4921.h"
#include "TEC.h"
#include "command.h"
#include "watchdog.h"
#include <util/delay.h>
#include "ring_led.h"
#include "Accel_Gyro.h"
#include "Pressure.h"
#include "ir_led.h"

//new code
#include "CAN_Protocol.h"
//

int main(void)
{
	SCH_Initialize();
	command_init();
	watchdog_init();
	watchdog_create_timer();
	status_led_init();
// 	temperature_init();
// 	ringled_init();
// 	IR_led_init();
// 	Accel_and_Gyro_init();
// 	Pressure_init();
// 	COPC_init();
	
 	status_led_create_task();
 	command_create_task();
//  	temperature_create_task();
// 	ringled_create_task();
// 	Accel_and_Gyro_create_task();
// 	Pressure_create_task();
// 	COPC_create_task();
	SCH_StartSchedular();
	
	
	//new code 3/7/2024
	CAN_Protocol_Init();
	CAN_create_task();
	//end new code 3/7/2024
	
	
	while (1)
	{
		SCH_HandleScheduledTask();
	}
}

