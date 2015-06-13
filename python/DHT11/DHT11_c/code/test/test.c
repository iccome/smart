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

#include "bbb_dht_read.h"


int main(int argc, const char *argv[])

{
	char group = 0;
	char ioport = 0;
	float humidity = 0;
	float temperature = 0;
	

	if (argc != 3)

	{

		printf("Usage:\n");

		printf("\tdht11_test <group>  <ioport>\n");

		printf("\n");

		return 1;

	}



	group = atoi(argv[1]);
	ioport = atoi(argv[2]);
	printf("main group %d ioport %d \n", group, ioport );
	
// Read DHT sensor connected to GPIO bin GPIO<base>_<number>, for example P8_11 is GPIO1_13 with
// base = 1 and number = 13.  Humidity and temperature will be returned in the provided parameters.
// If a successfull reading could be made a value of 0 (DHT_SUCCESS) will be returned.  If there
// was an error reading the sensor a negative value will be returned.  Some errors can be ignored
// and retried, specifically DHT_ERROR_TIMEOUT or DHT_ERROR_CHECKSUM.
	if(bbb_dht_read(DHT11, group, ioport, &humidity, &temperature)  == DHT_SUCCESS)
	{
		printf("bbb_dht_read success humidity %f temperature %f\n", humidity, temperature);
	}
	else
	{
		printf("bbb_dht_read failed\n");
	}

	return 0;
}
