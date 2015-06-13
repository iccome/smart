/* * led.h
 *
 *  Created on: 2015年5月1日
 *      Author: zjh
 */
#ifndef __LED_H_
#define __LED_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int BoneRelayInit(char group, char ioport);
int BoneRelayOnOff(char group, char ioport, char onOff);
int BoneRelayDeinit(char group, char ioport);



#endif
