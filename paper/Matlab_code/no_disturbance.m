close all
figure(1)
hold on
plot(orient1(:,1),orient1(:,2))
plot(orient2(:,1),orient2(:,2))
plot(orient3(:,1),orient3(:,2))
xlabel("Time (s)"); ylabel("Wind Voltage (mV)");
title("Orientation of Sensor");
legend("Normal","Parallel","Inline");