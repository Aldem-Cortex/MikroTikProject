/*
 * interrupts.h
 *
 *  Created on: May 20, 2024
 *      Author: User
 */

#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_

#include <stm32c031xx.h>
#include "defines.h"
#include "main.h"
#include <string>

using namespace std;
extern string ReceiveBuffer;

void TIM3_IRQHandler()
{
	if( TIM3->SR & TIM_SR_UIF )
	{
		TIM3->SR &= ~TIM_SR_UIF;
		TIM3->CR1 &= ~TIM_CR1_CEN;
		recFlg.led0off = true;
		switch( LED_1_PIN ) // deactivate LED_1_PIN output
		{
		case 4:
			GPIOA->ODR &= ~GPIO_ODR_OD4;
			break;
		case 5:
			GPIOA->ODR &= ~GPIO_ODR_OD5;
			break;
		case 6:
			GPIOA->ODR &= ~GPIO_ODR_OD6;
			break;
		case 7:
			GPIOA->ODR &= ~GPIO_ODR_OD7;
			break;
		default:
			break;
		}
	}
}

void TIM14_IRQHandler()
{

	if( TIM14->SR & TIM_SR_UIF )
	{
		TIM14->SR &= ~TIM_SR_UIF;
		TIM14->CR1 &= ~TIM_CR1_CEN;
		recFlg.led1off = true;
		switch( LED_2_PIN ) // deactivate LED_2_PIN output
		{
		case 4:
			GPIOA->ODR &= ~GPIO_ODR_OD4;
			break;
		case 5:
			GPIOA->ODR &= ~GPIO_ODR_OD5;
			break;
		case 6:
			GPIOA->ODR &= ~GPIO_ODR_OD6;
			break;
		case 7:
			GPIOA->ODR &= ~GPIO_ODR_OD7;
			break;
		default:
			break;
		}
	}
}

void USART1_IRQHandler()
{
	if( USART1->ISR & USART_ISR_RXNE_RXFNE )
	{
		char ch = USART1->RDR;
		if( ch != '\r' )
		{
			ReceiveBuffer += ch;
		}
		else if( ch == '\r' || ch == 0x00 )
		{
			recFlg.ReceiveFinised = true;
		}
	}
}


#endif /* INTERRUPTS_H_ */
