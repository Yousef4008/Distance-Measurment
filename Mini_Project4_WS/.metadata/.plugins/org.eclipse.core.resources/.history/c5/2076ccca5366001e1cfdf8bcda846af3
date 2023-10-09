 /*	______________________________________________________________________________
   |																			  |
   | Layer : APP																  |
   |																			  |
   | File Name: app.c															  |
   |																			  |
   | Description: Source file of the main application							  |
   |																			  |
   | Author: Youssif Hossam														  |
   |______________________________________________________________________________|
   */


#include "HAL/LCD/lcd.h"
#include "HAL/LM35_SENSOR/lm35_sensor.h"
#include "HAL/L293D/l293d.h"
#include "MCAL/ADC/adc.h"
#include "LIB/std_types.h"

int main (void){

	uint8 tempetaure = 0 , speed = 0;

	uint8 LCD_degreePatern []={0x1C, 0x14, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x00};

	LCD_DisplayCustomPtrn(0,0,0);
	L293D_Init(CHANNEL1_MODE );		/* LM35 Sensor Initialization */
	LCD_init();						/* LCD Display Initialization */

	LCD_StoreCustomPtrn(LCD_degreePatern , 0);


	/* Defining the configuration structure of the ADC (2.56v internal ref. voltage and 8 prescaler). */
	ADC_ConfigType ADC_MyConfiguration = {Int_2_56V , PRESCALER_8};

	ADC_init(&ADC_MyConfiguration);	/* ADC Initialization */

	LCD_displayStringRowColumn(0,2,"Temp	= ");
	LCD_displayStringRowColumn(1,2,"FAN is ");

	while(1){

		tempetaure = LM35_getTemperature();

		if(tempetaure < 30){
			speed = 0;
			LCD_displayStringRowColumn(1,9,"OFF");
		}
		else if (tempetaure < 60){
			speed = 25;
			LCD_displayStringRowColumn(1,9,"ON ");
		}
		else if (tempetaure < 90){
			speed = 50;
			LCD_displayStringRowColumn(1,9,"ON ");
		}
		else if (tempetaure < 120){
			speed = 75;
			LCD_displayStringRowColumn(1,9,"ON ");
		}
		else{
			speed = 100;
			LCD_displayStringRowColumn(1,9,"ON ");
		}

		L293D_Rotate(CHANNEL1_MODE , CW , speed);

		LCD_moveCursor(0,9);
		LCD_intgerToString(tempetaure);
		if(tempetaure < 10)
			LCD_displayString("  ");
		else if(tempetaure < 100)
			LCD_displayString(" ");

		LCD_displayCharacter('C');
		LCD_DisplayCustomPtrn(0,0,13);
	}
	return 0;
}
