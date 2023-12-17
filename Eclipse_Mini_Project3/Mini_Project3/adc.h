/**************************************
 * Module: ADC
 * File name: adc.h
 * Description: header file for the AVR ADC driver
 * Author: amr mohsen
 *************************************/

#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"

/**************************************************
 *                   Definitions                  *
 *************************************************/
#define ADC_MAXIMUM_VALUE       1023
#define ADC_REF_VOLT_VALUE      2.56

/**************************************************
 *                Type Declarations            *
 *************************************************/
typedef enum
{
	AREF,AVCC,RESERVED,INTERNAL

}ADC_ReferenceVoltage;

typedef enum
{
	F_CPU_2,F_CPU_4=2,F_CPU_8,F_CPU_16,F_CPU_32,F_CPU_64,F_CPU_128

}ADC_Prescaler;

typedef struct
{
	ADC_ReferenceVoltage ref_volt;
	ADC_Prescaler prescalar;

}ADC_ConfigType;

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/*
 * Description :
 * Function to initialize the ADC driver
 */
void ADC_init(const ADC_ConfigType *Config_Ptr);


/*
 * Description :
 * Function to read analog data from certain ADC channel(pin)
 * then convert it to digital using ADC driver
 */
uint16 ADC_readChannel(uint8 ch_num);





#endif /* ADC_H_ */


