/*
 * main.h
 *
 *  Created on: May 20, 2024
 *      Author: User
 */

#ifndef MAIN_H_
#define MAIN_H_


#include <stdint.h>
#include <stdlib.h>
#include <string>
#include <stm32c031xx.h>
#include <regex>
#include <vector>
#include "defines.h"

using namespace std;
string ReceiveBuffer = "";

typedef struct
{
	bool led0off = false;
	bool led1off = false;
	bool ReceiveFinised = false;
} flags;
flags recFlg;


#endif /* MAIN_H_ */
