/* * led.c
 *
 *  Created on: 2015年5月1日
 *      Author: zjh
 */

#include "led.h"
#include <pthread.h>


#define TAG "[LED] "
#define MAX_LED_NUM 4
/*led state definition*/
typedef enum{
	None,
	Init,
	Processing,
}LedState;

/*led status data structure*/
typedef struct{
	char ledNum;
	LedState state;
	int fid;
	char onoff;
}LedData;

LedData* theLed[MAX_LED_NUM];
char theLedCount = 0;
pthread_t theLedThread;
pthread_mutex_t theLedMutex;
pthread_cond_t theLedWake;
static void BoneLedRun(void)
{
	printf("%s BoneLedRun begin\n", TAG);
	while(1)
	{
		char index = 0;
		pthread_cond_wait(&theLedWake, &theLedMutex);
		pthread_mutex_lock(&theLedMutex);
		for(index = 0; index < theLedCount; index++)
		{
			if(theLed[index] != NULL && theLed[index]->state == Processing)
			{
				int fid = theLed[index]->fid;
				printf("%s Led %d OnOff %d\n", TAG, theLed[index]->ledNum, theLed[index]->onoff);
				switch (theLed[index]->onoff)
				{
					case 0:
						write(fid, "0", 1);
						break;

					case 1:
						write(fid, "1", 1);
						break;
					default:
						printf("<on/off>: 1 = on, 0 = off\n");
						break;
				}
				theLed[index]->state = Init;
			}
		}

		pthread_mutex_unlock(&theLedMutex);
	}
}

char BoneLedInit(char maxLedNum)
{
	int code = 0;
	int i = 0;
	if(maxLedNum > MAX_LED_NUM)
		return ParamErr;
	for(i = 0; i < maxLedNum; i++)
	{

		theLed[i] = (LedData*)malloc(sizeof(LedData));
		memset(theLed[i], 0x00, sizeof(LedData));
	}
	theLedCount = maxLedNum;
	code = pthread_create(&theLedThread, 
				NULL,
				BoneLedRun,
				NULL);
	if(code != 0)
	{
		printf("%s create thread failed code 0x%x\n", TAG, code);
		for(i = 0; i < maxLedNum; i++)
		{
			free(theLed[i]);
			theLed[i] = NULL;
		}
		theLedCount = 0;
		return Fail;
	}
	return Success;
	 		
}

char BoneLedPortInit(char ledNum)
{
	
	char ledPath[1024] = {0};
	int fid;
	printf(" %s %s ledNum %d \n", TAG, __FUNCTION__, ledNum);
	char index = 0;
	for(index  = 0; index < theLedCount; index++)
	{
		if(theLed[index]->state == None)
		{
			break;
		}		
	}
	if(index >= theLedCount)
	{
		printf("%s the led num has arrived the max\n", TAG);
		return Fail;
	}

	if (ledNum < 0 || ledNum > 3)
	{

		printf("%s <ledNum>  : Number between 0-3\n", TAG);



		return ParamErr;

	}

	sprintf(ledPath, "/sys/class/leds/beaglebone\:green\:usr%d/brightness", ledNum);
	printf("%s ledPath %s\n", TAG, ledPath);
	fid = open(ledPath, O_WRONLY);
	if(fid < 0)
	{
		printf("%s error fid %d", TAG,fid);
		return Fail;
	}
	theLed[index]->fid = fid;
	theLed[index]->state = Init;
	theLed[index]->ledNum = ledNum;
	
	return Success;
	
}

int BoneLedOnOff(int ledNum, char onOff)
{
	char index = 0;
	int fid = 0;
	pthread_mutex_lock(&theLedMutex);
	for(index  = 0; index < theLedCount; index++)
	{
		if(theLed[index] != NULL && 
			theLed[index]->ledNum == ledNum &&
			 theLed[index]->state == Init )
		{
			break;
		}		
	}
	if(index >= theLedCount)
	{
		printf("%s could not find the ledNum %d\n", TAG, ledNum);
		pthread_mutex_lock(&theLedMutex);
		return Fail;
	}

	fid = theLed[index]->fid;
	theLed[index]->state = Processing; /*wait for thread process*/
	theLed[index]->onoff = onOff;
	printf("%s %s fid 0x%x\n", TAG, __FUNCTION__, fid);
	pthread_mutex_unlock(&theLedMutex);
	pthread_cond_signal(&theLedWake);
#if 0
	switch (onOff)
	{

		case 0:

			write(fid, "0", 1);

			break;

		case 1:

			write(fid, "1", 1);

			break;
-
		default:

			printf("<on/off>: 1 = on, 0 = off\n");

			return 1;

	}
#endif	
	return Success;
}
char BoneLedClose(char ledNum)
{
	
	char index = 0;
	int fid = 0;
	for(index  = 0; index < theLedCount; index++)
	{
		if(theLed[index] != NULL && theLed[index]->ledNum == ledNum &&
			 (theLed[index]->state == Init) )
		{
			break;
		}		
	}
	if(index >= theLedCount)
	{
		printf("%s could not find the ledNum %d\n", TAG, ledNum);
		return Fail;
	}
	fid = theLed[index]->fid;
	printf("%s %s fid 0x%x\n", TAG, __FUNCTION__, fid);
	close(fid);
	theLed[index]->fid = -1;
	theLed[index]->state = None;
	theLed[index]->ledNum = 0;
	free(theLed[index]);
	theLed[index] = NULL;
	return Success;

}
char BoneLedDeinit(void)
{
	char index = 0;
	
	for(index  = 0; index < theLedCount; index++)
	{
		if(theLed[index] != NULL &&
			theLed[index]->fid >= 0  &&
			 theLed[index]->state == Init )
		{
			BoneLedClose(index);
		}		
	}
	return Success;
}
