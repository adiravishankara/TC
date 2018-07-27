filename1 = "/home/adiravishankara/Documents/GIT/TC/DATA/0deg_off_on_off1.csv"
filename2 = "/home/adiravishankara/Documents/GIT/TC/DATA/0deg_off_on_off1T.csv"

data1 = csvread("/home/adiravishankara/Documents/GIT/TC/DATA/0deg_off_on_off1T.csv",0,1);
data2 = csvread("/home/adiravishankara/Documents/GIT/TC/DATA/0deg_off_on_off1.csv",0,1);

time1 = data1(:,1);
time2 = data2(:,1);

force = data1(:,10);
wind_voltage = data2(:,2);

figure(1)
plot(time1,force)

figure(2)
plot(time2,wind_voltage)