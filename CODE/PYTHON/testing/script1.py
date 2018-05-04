import time
import subprocess, sys
import random
from time import sleep


rand1 = random.randint(1,100)
time1 = time.time()
stringa = (time1, "random value: ", rand1)
print(stringa)
printstat = True
sleep(2)
printstat = False

