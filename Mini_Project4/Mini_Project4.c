/*
 * Mini_Project4.c
 *
 *  Created on: Oct 20, 2023
 *      Author: Mahy Mahrous
 */
#include <avr/io.h>
#include "ultrasonic.h"
#include "lcd.h"
#include "icu.h"
extern uint8 g_edgeCount;
int main(void){
	SREG |= (1<<7);
	Ultrasonic_init();
	uint16 distanceInCm=0;
	LCD_init();
	LCD_displayString("Distance=    cm");
	LCD_moveCursor(0,10);

	while(1){
		if(g_edgeCount==2){
		    ICU_deInit();
			g_edgeCount = 0;
			distanceInCm=Ultrasonic_readDistance();
			LCD_integerToString(distanceInCm);
		}



		}

	}



