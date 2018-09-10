Hello, here is some general information on how the files are organized.

The data files (.mat) which contain 10 cols are the ones recorded by the arduino with the wind sensor.
The file is organized as follows:
Time Wind PWM Error Wind_Thrust_Model PWM_Thrust_Model Kalman_Filter(Use This) Kalman Filter(Dont use) Kalman_PWM(Use This) Kalman_PWM(Dont use)

the data files (.csv) which contain 34 cols are the ones recorded by the testbed
The files are organized as follows:
file(:,1)-Time, file(:,9)-Torque , file(:,10)-thrust, file(:,13)-RPM


