#!/usr/bin/python
import os
import sys
import time
import ctypes
beaglebone = ctypes.CDLL("./libbeaglebone_led.so")
if os.geteuid():
	args = [sys.executable] + sys.argv
# get root privilege by su
#	os.execlp('su', 'su', '-c', ' '.join(args))
# get root privilege by sudo
	os.execlp('sudo', 'sudo', *args)
print('Running at root privilege. Your euid is', os.geteuid())
i = 0
led = 0
count = 5
while i < count:
	print 'i %d' % i
	print 'led %d on' % led
	beaglebone.BoneLedOnOff(led,1);
	time.sleep(1)
	print 'led %d off' % led
	beaglebone.BoneLedOnOff(led,0);
	time.sleep(1)
	i +=1
print 'exit'
