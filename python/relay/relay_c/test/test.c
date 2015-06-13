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

#include "relay.h"


int main(int argc, const char *argv[])

{
	char group = 0;
	char ioport = 0;
	char i = 0;

	if (argc != 3)

	{

		printf("Usage:\n");

		printf("\trelay_test  <group> <ioport>\n");

		printf("\n");

		return 1;

	}



	group = atoi(argv[1]);

	ioport = atoi(argv[2]);
	printf("main group %d ioport %d \n", group, ioport );
	BoneRelayInit(group, ioport);
	sleep(1);
	for(i =0; i < 5; i++)
	{
		printf("relay switch to on\n");
		BoneRelayOnOff(group, ioport, 1);
		sleep(1);
		printf("relay switch to off\n");
		BoneRelayOnOff(group, ioport, 0);
		sleep(1);
	}
	BoneRelayDeinit(group,ioport);
	

	return 0;
}
