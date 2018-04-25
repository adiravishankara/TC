#This file is to gather data from the wind sensor and then save it to a file in the directory.

import pigpio
pi = pigpio.pi()

while True:
	pi.set_mode(4,pigpio.INPUT)
	print(pi.read(11))
