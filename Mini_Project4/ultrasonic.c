/*
 * ultrasonic.c
 *
 *  Created on: Oct 20, 2023
 *      Author: Mahy Mahrous
 */
#include "ultrasonic.h"
#include "util/delay.h"
#include <math.h>
uint8 g_edgeCount = 0;
uint16 g_highTime  = 0;
void Ultrasonic_init(void){
	ICU_ConfigType Configuration ={F_CPU_8,RAISING};
	ICU_init(&Configuration);
	GPIO_setupPinDirection(TRIG_PORT_ID,TRIG_PIN_ID,PIN_OUTPUT);
	ICU_setCallBack(Ultrasonic_edgeProcessing);
}
void Ultrasonic_Trigger(void){
	GPIO_writePin(TRIG_PORT_ID,TRIG_PIN_ID,LOGIC_LOW);
	_delay_ms(10);
	GPIO_writePin(TRIG_PORT_ID,TRIG_PIN_ID,LOGIC_HIGH);
	_delay_ms(10);
	GPIO_writePin(TRIG_PORT_ID,TRIG_PIN_ID,LOGIC_LOW);

}

uint16 Ultrasonic_readDistance(void){
	Ultrasonic_Trigger();
	uint16 distance=0;
	distance=g_highTime *  0.017 +1;

	return distance;
}
void Ultrasonic_edgeProcessing(void){
	g_edgeCount++;
	if(g_edgeCount==1){
		 ICU_clearTimerValue();
		 ICU_setEdgeDetectionType(FALLING);

	}
	if(g_edgeCount==2){
		g_highTime = ICU_getInputCaptureValue();
	}



}









