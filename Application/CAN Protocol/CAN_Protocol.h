/*
 * CAN_MCP2515.h
 *
 * Created: 06/07/2024 4:38:17 PM
 *  Author: QUOC THANG
 */ 


#ifndef CAN_PROTOCOL_H_
#define CAN_PROTOCOL_H_

#include "scheduler.h"
#include "CANSPI.h"
#include "uart.h"

#include "ir_led.h"
#include "SK6812.h"

#define SET_BRIGHTNESS_CMD		0x0D
#define SET_RGBW_CMD			0x0F

void CAN_Protocol_Init(void);
void CAN_create_task(void);
void CAN_report(void);

void Control_LED(void);

#endif /* CAN_PROTOCOL_H_ */