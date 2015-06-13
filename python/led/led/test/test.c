/*
 * main.c
 *
 *  Created on: 2015年5月1日
 *      Author: zjh
 */


#include <stdio.h>

#include <stdlib.h>

#include <fcntl.h>

#include <unistd.h>

#include "led.h"


int main(int argc, const char *argv[])

{
	int ledNum = 0;
	char onOff = 0;

	if (argc != 3)

	{

		printf("Usage:\n");

		printf("\tledCtl <led> <on/off>\n");

		printf("\n");

		printf("<led>  : Number between 0-3\n");

		printf("<on/off>: 1 = on, 0 = off\n");



		return 1;

	}



	ledNum = atoi(argv[1]);

	onOff = atoi(argv[2]);
	printf("main lenNum %d onOff %d\n", ledNum, onOff);
	BoneLedOnOff(ledNum, onOff);

	return 0;
}
