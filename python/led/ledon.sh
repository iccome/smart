#!/bin/sh
#Replace the names with what is used on your system
#Disconnect  1 LEDs on the Beaglebon so we can use it.
echo none > /sys/class/leds/beaglebone:green:usr3/trigger
#Tun on user 3 Leds

echo 255 > /sys/class/leds/beaglebone:green:usr3/brightness
