/* * led.c
 *
 *  Created on: 2015年5月1日
 *      Author: zjh
 */

#include "led.h"

#define TAG "[LED] "

int BoneLedOnOff(int ledNum, char onOff)
{
	char ledPath[1024] = {0};
	int fid;
	printf(" %s %s ledNum %d onoff %d\n", TAG, __FUNCTION__, ledNum, onOff);

	if (ledNum < 0 || ledNum > 3)
	{

		printf("<led>  : Number between 0-3\n");



		return 1;

	}

	sprintf(ledPath, "/sys/class/leds/beaglebone\:green\:usr%d/brightness", ledNum);
	printf("ledPath %s\n", ledPath);
	fid = open(ledPath, O_WRONLY);
	
	printf("%s %s fid 0x%x\n", TAG, __FUNCTION__, fid);

	switch (onOff)
	{

		case 0:

			write(fid, "0", 1);

			break;

		case 1:

			write(fid, "1", 1);

			break;

		default:

			printf("<on/off>: 1 = on, 0 = off\n");

			return 1;

	}



	close(fid);

	printf("%s %s exit\n", TAG, __FUNCTION__); 
	return 0;
}
