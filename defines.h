/*
 * defines.h
 *
 *  Created on: May 20, 2024
 *      Author: User
 */

#ifndef DEFINES_H_
#define DEFINES_H_


#define OK "OR\r\n"
#define ERROR "ERROR\r\n"

#ifndef BAUDRATE
#define BAUDRATE 115200
#endif

#ifndef LED_1_PIN
#define LED_1_PIN 4
#endif

#ifndef LED_2_PIN
#define LED_2_PIN 5
#endif

#if ( ( LED_1_PIN < 4 ) || (LED_1_PIN > 7 ) || ( LED_2_PIN < 4) || ( LED_2_PIN > 7) )
#define LED_1_PIN 4
#define LED_2_PIN 5
#endif

#if ( LED_1_PIN == LED_2_PIN )
#if ( LED_1_PIN < 7 )
#define LED_2_PIN LED_1_PIN + 1
#else
#define LED_1_PIN 4
#define LED_2_PIN 5
#endif
#endif

#endif /* DEFINES_H_ */
