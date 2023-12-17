/**************************************
 * Module: ADC
 * File name: adc.c
 * Description: source file for the AVR ADC driver
 * Author: amr mohsen
 *************************************/
#include"adc.h"
#include"common_macros.h"
#include<avr/io.h>


/***************************************
 *         Functions Definitions       *
 **************************************/

/*
 * Description :
 * Function to initialize the ADC driver
 */
void ADC_init(const ADC_ConfigType *Config_Ptr)
{
	/* select Vref source(AREF) */
	/* Insert the Vref bits in the last two bits in register ADMUX */

	ADMUX=(ADMUX & 0x3F)| ((Config_Ptr->ref_volt) <<6);

	/*  Disable left adjust result BIT 5 */
	CLEAR_BIT(ADMUX,ADLAR);

	/* initialIze read_channel ( SET FIRST 5 BITS TO ZERO) */
	ADMUX&=0xE0;

	/* SET PRESCALAR TO 128        (ADPS2:0) */
	ADCSRA=(ADCSRA & 0xFC)|(Config_Ptr->prescalar);

	/* ENABLE ADC                  (ADEN) */
	ADCSRA|=(1<<ADEN);

	/* DISBALE ADC INTERRUPT       (ADIE = 0) */
	/* Disable ADC AUTO TRIGGER    (ADATE =0) */
	ADCSRA&=0x97;

}


uint16 ADC_readChannel(uint8 ch_num)
{
	ADMUX=(ADMUX & 0xE0) | (ch_num & 0x07);        // clear first 5 bits then insert channel_number

	SET_BIT(ADCSRA,ADSC);                 // START CONVERSION

	while(BIT_IS_CLEAR(ADCSRA,ADIF));     //WAIT until flag is raised ( polling)

	SET_BIT(ADCSRA,ADIF);               // CLEAR FLAG

	return ADC;

}
