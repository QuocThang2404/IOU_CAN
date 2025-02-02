/*
 * Pressure.h
 *
 * Created: 6/14/2024 1:01:13 PM
 *  Author: HTSANG
 */ 


#ifndef PRESSURE_H_
#define PRESSURE_H_

#include "scheduler.h"
#include "BMP390.h"
#include "IOU_board.h"
#include "IOU_data.h"

void	Pressure_init(void);
void	Pressure_create_task(void);
int16_t	get_pressure(void);

#endif /* PRESSURE_H_ */