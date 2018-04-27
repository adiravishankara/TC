#This file is to gather data from the wind sensor and then save it to a file in the directory.

import time
import pigpio
pi = pigpio.pi()

while True:
	pi.set_mode(4,pigpio.INPUT)
	print(time.asctime(), "    ", pi.read(11))
	time.sleep(5)
