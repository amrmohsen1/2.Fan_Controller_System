#include "lcd.h"
#include "adc.h"
#include "lm35.h"
#include "dc_motor.h"
#include "pwm.h"

/**************************************************
 *                Type Declarations            *
 *************************************************/
typedef enum
{
	OFF,ON
}Fan_Status;

/**************************************************
 *                Global Variables                *
 *************************************************/
uint8 g_temp=0;

Fan_Status g_fan_status=OFF;

/***************************************************
 *                Functions Definitions            *
 ***************************************************/
/*
 * Description :
 * Function to update fan status and adjust motor speed.
 */
void Fan_control(uint8 temp)
{
	if(temp>=120)
	{
		g_fan_status=ON;
		DcMotor_Rotate(CW,100);
	}

	else if(temp>=90)
	{
		g_fan_status=ON;
		DcMotor_Rotate(CW,75);
	}
	else if(temp>=60)
	{
		g_fan_status=ON;
		DcMotor_Rotate(CW,50);
	}
	else if(temp>=30)
	{
		g_fan_status=ON;
		DcMotor_Rotate(CW,25);
	}
	else
	{
		g_fan_status=OFF;
		DcMotor_Rotate(OFF,0);
	}
}


int main(void)
{
	/* ADC Configurations & initialization */
	ADC_ConfigType ADC_Configurations={INTERNAL,F_CPU_8};

	/* ADC & LCD & DC-MOTOR initialization */
	ADC_init(&ADC_Configurations);
	LCD_init();
	DcMotor_Init();

	LCD_moveCursor(0,4);
	LCD_displayString("FAN is  ");
	LCD_moveCursor(1,4);
	LCD_displayString("Temp=    C");

	while(1)
	{
		g_temp=LM35_getTemperature();

		Fan_control(g_temp);

		LCD_moveCursor(0,11);

		if(g_fan_status==OFF)
		{
			LCD_displayString("OFF");
		}
		else
		{
			LCD_displayString("ON");
			LCD_displayCharacter(' ');
		}

		LCD_moveCursor(1,10);
		if(g_temp>=100)
		{
			LCD_integerToString(g_temp);
		}
		else
		{
			LCD_integerToString(g_temp);
			LCD_displayCharacter(' ');
		}
	}
}






