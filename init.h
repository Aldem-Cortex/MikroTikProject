/*
 * init.h
 *
 *  Created on: May 20, 2024
 *      Author: User
 */

#ifndef INIT_H_
#define INIT_H_

#include <stm32c031xx.h>
#include "defines.h"

void InitUSART1()
{
	RCC->APBENR2 |= RCC_APBENR2_USART1EN;
	RCC->IOPENR |= RCC_IOPENR_GPIOAEN;

	GPIOA->MODER &= ~GPIO_MODER_MODE0_0;
	GPIOA->MODER |= GPIO_MODER_MODE0_1;

	GPIOA->MODER &= ~GPIO_MODER_MODE1_0;
	GPIOA->MODER |= GPIO_MODER_MODE1_1;

	USART1->CR1 &= ~USART_CR1_PCE;	// No Parity

	USART1->CR1 &= ~USART_CR1_M0;	// 8 bits
	USART1->CR1 &= ~USART_CR1_M1;	// 8 bits

	USART1->CR2 &= ~USART_CR2_STOP_0;	// 1 Stop bit
	USART1->CR2 &= ~USART_CR2_STOP_1;	// 1 Stop bit

	uint16_t freq = ( 12000000 / BAUDRATE ); // Default system clock is 48MHz with divider == 4
	USART1->BRR = freq;

	USART1->CR1 |= USART_CR1_UE;	// enable USART
	USART1->CR1 |= USART_CR1_RE;	// enable RX

	NVIC_SetPriority( USART1_IRQn, 0x00 );
	NVIC_EnableIRQ( USART1_IRQn );
}

void InitGPIO()
{
	switch( LED_1_PIN ) // set LED_1_PIN as output and lock it
	{
	case 4:
		GPIOA->MODER &= ~GPIO_MODER_MODE4_1;
		GPIOA->MODER |= GPIO_MODER_MODE4_0;
		break;
	case 5:
		GPIOA->MODER &= ~GPIO_MODER_MODE5_1;
		GPIOA->MODER |= GPIO_MODER_MODE5_0;
		break;
	case 6:
		GPIOA->MODER &= ~GPIO_MODER_MODE6_1;
		GPIOA->MODER |= GPIO_MODER_MODE6_0;
		break;
	case 7:
		GPIOA->MODER &= ~GPIO_MODER_MODE7_1;
		GPIOA->MODER |= GPIO_MODER_MODE7_0;
		break;
	default:
		break;
	}

	switch( LED_2_PIN ) // set LED_2_PIN as output and lock it
	{
	case 4:
		GPIOA->MODER &= ~GPIO_MODER_MODE4_1;
		GPIOA->MODER |= GPIO_MODER_MODE4_0;
		break;
	case 5:
		GPIOA->MODER &= ~GPIO_MODER_MODE5_1;
		GPIOA->MODER |= GPIO_MODER_MODE5_0;
		break;
	case 6:
		GPIOA->MODER &= ~GPIO_MODER_MODE6_1;
		GPIOA->MODER |= GPIO_MODER_MODE6_0;
		break;
	case 7:
		GPIOA->MODER &= ~GPIO_MODER_MODE7_1;
		GPIOA->MODER |= GPIO_MODER_MODE7_0;
		break;
	default:
		break;
	}
}

void InitTimers()
{
	RCC->APBENR1 |= RCC_APBENR1_TIM3EN;
	RCC->APBENR2 |= RCC_APBENR2_TIM14EN;

	NVIC_SetPriority( TIM3_IRQn, 0x03 );
	NVIC_SetPriority( TIM14_IRQn, 0x03 );
	NVIC_EnableIRQ( TIM3_IRQn );
	NVIC_EnableIRQ( TIM14_IRQn );

	TIM3->DIER |= TIM_DIER_UIE;
	TIM14->DIER |= TIM_DIER_UIE;
}



#endif /* INIT_H_ */
