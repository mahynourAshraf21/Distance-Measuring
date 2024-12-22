/*
 * ultrasonic.h
 *
 *  Created on: Oct 20, 2023
 *      Author: Mahy Mahrous
 */

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_
#include "icu.h"
#include "gpio.h"
#include "std_types.h"
#include "common_macros.h"

#define TRIG_PORT_ID      PORTB_ID
#define TRIG_PIN_ID       PIN5_ID
void Ultrasonic_init(void);
void Ultrasonic_Trigger(void);
uint16 Ultrasonic_readDistance(void);
void Ultrasonic_edgeProcessing(void);



#endif /* ULTRASONIC_H_ */
