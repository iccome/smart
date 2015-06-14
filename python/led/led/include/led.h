/* * led.h
 *
 *  Created on: 2015年5月1日
 *      Author: zjh
 */
#ifndef __LED_H_
#define __LED_H_

#include <stdio.h>

#include <stdlib.h>

#include <fcntl.h>

#include <unistd.h>
enum{
	Success = 0,
	ParamErr,
	Fail
};
int BoneLedOnOff(int ledNum, char onOff);

#endif
