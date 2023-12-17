/**************************************
 * Module: DC-MOTOR
 * File name: dc_motor.c
 * Description: source file for the AVR DC-MOTOR driver
 * Author: amr mohsen
 *************************************/

#include"dc_motor.h"
#include "gpio.h"
#include "pwm.h"
#include <avr/io.h>




/*******************************************************************************
 *                             Functions Definitions                           *
 *******************************************************************************/
/*
 * Description:
 * The Function responsible for setup the direction for the two motor pins through the GPIO driver.
 * Stop at the DC-Motor at the beginning through the GPIO driver.
 */
void DcMotor_Init(void)
{
	/* Set PB0,PB1 (OUTPUT PINS) (IN1,IN2) */
	GPIO_setupPinDirection(PORTB_ID,PIN0_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(PORTB_ID,PIN1_ID,PIN_OUTPUT);

	/* Stop  DC-Motor at the beginning */
	GPIO_writePin(PORTB_ID,PIN0_ID,LOGIC_LOW);
	GPIO_writePin(PORTB_ID,PIN1_ID,LOGIC_LOW);

}

/*
 * Description:
 * The function responsible for rotate the DC Motor CW/ or A-CW or stop the motor based on the state input state value.
 * Send the required duty cycle to the PWM driver based on the required speed value.
 */
void DcMotor_Rotate(DcMotor_State state,uint8 speed)
{

	switch(state)
	{
	 case STOP:
		 /* STOP THE MOTOR PB0,PB1=0 (IN1,IN2 ARE LOW) */
		 PORTB&=0xFC;
		 break;

	 case CW:
		 /* Rotate THE MOTOR clockwise PB0=0,PB1=1 (IN1=LOW, IN2=HIGH ) */
		 GPIO_writePin(PORTB_ID,PIN0_ID,LOGIC_LOW);
		 GPIO_writePin(PORTB_ID,PIN1_ID,LOGIC_HIGH);
		 break;
	 case A_CW:
		 /* Rotate THE MOTOR Anti-clockwise PB0=1,PB1=0 (IN1=HIGH, IN2=LOW ) */
		 GPIO_writePin(PORTB_ID,PIN0_ID,LOGIC_HIGH);
		 GPIO_writePin(PORTB_ID,PIN1_ID,LOGIC_LOW);
		 break;
	}


	PWM_Timer0_Start(speed);
}

