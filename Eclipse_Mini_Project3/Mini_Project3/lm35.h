/**************************************
 * Module: Temperature Sensor
 * File name: lm35.h
 * Description: header file for the AVR LM35 Temperature Sensor driver
 * Author: amr mohsen
 *************************************/

#ifndef LM35_H_
#define LM35_H_

#include"std_types.h"

/**************************************************
 *                   Definitions                  *
 *************************************************/

#define SENSOR_CHANNEL_ID            2
#define SENSOR_MAX_VOLT_VALUE        1.5
#define SENSOR_MAX_TEMPERATURE       150

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

uint8 LM35_getTemperature(void);

#endif /* LM35_H_ */
