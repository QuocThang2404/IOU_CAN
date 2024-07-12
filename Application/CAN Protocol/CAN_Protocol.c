/*
 * CAN_MCP2515.c
 *
 * Created: 06/07/2024 4:38:04 PM
 *  Author: QUOC THANG
 */ 

#include "CAN_Protocol.h"

static	void	CAN_task_update(void);
uCAN_MSG rxMessage;


typedef struct CAN_TaskContextTypedef_
{
	SCH_TASK_HANDLE               taskHandle;
	SCH_TaskPropertyTypedef       taskProperty;
} CAN_TaskContextTypedef;



static CAN_TaskContextTypedef           CAN_task_context =
{
	SCH_INVALID_TASK_HANDLE,                 // Will be updated by Schedular
	{
		SCH_TASK_SYNC,                      // taskType;
		SCH_TASK_PRIO_7,                    // taskPriority;
		100,                                // taskPeriodInMS;
		CAN_task_update					// taskFunction;
	}
};

void CAN_Protocol_Init(void)
{
	CAN_Init();
}

static void CAN_task_update(void)
{
	CANSPI_Receive(&rxMessage);
	Control_LED();
}

void CAN_create_task(void)
{
	SCH_TASK_CreateTask(&CAN_task_context .taskHandle, &CAN_task_context .taskProperty);
}

void	CAN_report(void)
{
		UARTprintf("%d", rxMessage.frame.data0);
		UARTprintf("\r\n");
		UARTprintf("%d", rxMessage.frame.data1);
		UARTprintf("\r\n");
		UARTprintf("%d", rxMessage.frame.data2);
		UARTprintf("\r\n");
		UARTprintf("%d", rxMessage.frame.data3);
		UARTprintf("\r\n");
		UARTprintf("%d", rxMessage.frame.data4);
		UARTprintf("\r\n");
		UARTprintf("%d", rxMessage.frame.data5);
		UARTprintf("\r\n");
		UARTprintf("%d", rxMessage.frame.data6);
		UARTprintf("\r\n");
		UARTprintf("%d", rxMessage.frame.data7);
		UARTprintf("\r\n");
}

void Control_LED(void)
{
	if(rxMessage.frame.id == 0x005)
	{
		if(rxMessage.frame.data0 == SET_BRIGHTNESS_CMD)
		{
			uint8_t duty = rxMessage.frame.data1;
			IR_led_set_DutyCyclesPercent(duty);
			UARTprintf("duty: %d", duty);
		}
		else if(rxMessage.frame.data0 == SET_RGBW_CMD)
		{
			uint8_t red = rxMessage.frame.data1;
			uint8_t green = rxMessage.frame.data2;
			uint8_t blue = rxMessage.frame.data3;
			uint8_t white = rxMessage.frame.data4;
			ringled_set_RGBW(red, green, blue, white);
			UARTprintf("%d %d %d %d", red, green, blue, white);
		}
	} 
}
