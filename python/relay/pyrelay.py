#!/usr/bin/python
import os
import sys
import time
import ctypes
beaglebone = ctypes.CDLL("./libbeaglebone_relay.so")
if os.geteuid():
	args = [sys.executable] + sys.argv
# get root privilege by su
#	os.execlp('su', 'su', '-c', ' '.join(args))
# get root privilege by sudo
	os.execlp('sudo', 'sudo', *args)
print('Running at root privilege. Your euid is', os.geteuid())
i = 0
#gpio1_28 P9--12
group = 1
ioport = 28
#beaglebone.BoneRelayInit(group, ioport)
count = 5
while i < count:
	print 'relay on' 
	beaglebone.BoneRelayOnOff(group,ioport, 1);
	time.sleep(1)
	print 'relay off'
	beaglebone.BoneRelayOnOff(group,ioport, 0);
	time.sleep(1)
	i +=1
beaglebone.BoneRelayDeinit(group,ioport)
print 'exit'
