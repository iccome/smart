/* * led.c
 *
 *  Created on: 2015年5月1日
 *      Author: zjh
 */

#include "relay.h"

#define TAG "[RELAY] "
#define EXPORT_PATH "/sys/class/gpio/export"
#define UNEXPORT_PATH "/sys/class/gpio/unexport"
typedef enum{
	NONE,
	INIT
}RelayStatus;
typedef struct{
	int port;
	RelayStatus status;
}RelayState;
static RelayState mRelayStatus = {0,NONE};
int BoneRelayInit(char group, char ioport)
{
	char path[1024] = {0};
	FILE *fp = NULL;
	int port = group * 32 + ioport;
	mRelayStatus.status = NONE;
	mRelayStatus.port = 0;

	printf("%s %s group %d ioport %d port %d \n", TAG, __FUNCTION__, group, ioport,  port );
	printf("EXPORT_PATH %s\n", EXPORT_PATH);	
	fp = fopen(EXPORT_PATH, "w");

	if(fp)
	{

		if(fprintf(fp,"%d", port) < 0)
		{
			printf("%s %s open EXPORT_PATH  port error\n", TAG, __FUNCTION__);
			return -1 ;
		}
	}
	else
	{
		printf("%s %s open EXPORT_PATH error\n", TAG, __FUNCTION__);
		return -1;
	}
	fclose(fp);
	printf("%s set direction out begin\n", TAG);
	sprintf(path,"/sys/class/gpio/gpio%d/direction", port);
	printf("%s GPIO Directon Path: %s\n", TAG, path);
	fp = fopen(path, "w");
	if(fp)
	{
		/*Caution must set "out" instead of "1"*/
		/*if set 1 the status is weird*/
		if(fprintf(fp, "%s", "out") < 0)
		{
			
			printf("%s %s open set direction out error\n", TAG, __FUNCTION__);
			return -1;
		}

	}
	else
	{
		printf("%s %s open set direction error\n", TAG, __FUNCTION__);
		return -1;
	}

	fclose(fp);
	mRelayStatus.port = port;
	mRelayStatus.status = INIT;
	printf("%s GPIO Directon finished\n", TAG);
	return 0;
}
/*GPIO1_28 means group is 1 , ioport = 18*/
int BoneRelayOnOff(char group, char ioport, char onOff)
{
	char path[1024] = {0};
	int port = group * 32 + ioport;
	FILE *fp = NULL;

	printf("%s %s group %d ioport %d port %d onoff %d\n", TAG, __FUNCTION__, group, ioport,  port, onOff);
	if(mRelayStatus.status == NONE)
	{
		if(BoneRelayInit(group, ioport) == 0)
			sleep(1);
		else
		{
			printf("%s %s Init Failed exit\n", TAG, __FUNCTION__);
			return -1;
		}
	}	
	sprintf(path,"/sys/class/gpio/gpio%d/value", port);
	printf("%s %s path %s\n", TAG, __FUNCTION__, path);
	
	fp = fopen(path, "w");
	if(fp)
	{
		fprintf(fp,"%d", onOff);
	}
	else
	{
		printf("%s open path error\n", TAG);
		return -1;
	}
	printf("%s %s exit\n", TAG, __FUNCTION__);
	fclose(fp);
	return 0;
}
int BoneRelayDeinit(char group, char ioport)
{
	char path[1024] = {0};
	FILE *fp = NULL;
	int port = group * 32 + ioport;
	mRelayStatus.status = NONE;

	printf("%s %s BEGIN group %d, ioport %d\n", TAG, __FUNCTION__, group, ioport); 
	printf("UNEXPORT_PATH %s\n", UNEXPORT_PATH);	
	fp = fopen(UNEXPORT_PATH, "w");

	if(fp)
	{

		fprintf(fp,"%d", port);
	}
	else
	{
		printf("%s %s open path error exit", TAG, __FUNCTION__);
		return -1;
	}
	mRelayStatus.status = NONE;
	mRelayStatus.port = 0;
	printf("%s %s exit\n", TAG, __FUNCTION__);
	return 0;
}
