# TC
Thrust Control code

Ssh into rpi
The ip address is set to 192.168.1.200

code to ssh
sudo ssh pi@192.168.1.200

directory of git
cd Documents/GIT/TC

to get user input into the system use input()


How the system works:
1. GPIO on pi starts (“sudo pigpiod”)
2. Start Reading data from wind sensor.
3. Do a motor pwm test, make sure we can control it.
4. wait for thrust desired input form user.
5. User starts thrust stand board. Recieve pwm signal (countdown of sorts)
6. Once pi and RCB board are synced, start running TC program.
7. Collect data from both RCB and wind sensor, as well as data of pwm sent out.
