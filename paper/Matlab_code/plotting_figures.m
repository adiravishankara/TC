close all
% figure(1)
% hold on
% plot(orient1(:,1),orient1(:,2))
% plot(orient2(:,1),orient2(:,2))
% plot(orient3(:,1),orient3(:,2))
% xlabel("Time (s)"); ylabel("Wind Voltage (mV)");
% title("Orientation of Sensor");
% legend("Normal","Parallel","Inline");
% 
% figure(2)
% data = [510,550,520,630,660,667,610;
%    597,589,659,680,682,676,660;
%    657,675,667,635,668,672,673;
%    599,650,670,680,640,630,675;
%    540,660,650,630,660,670,620];
% 
% data2 = [676;686;676;681;680;679;680;676;672;670];
% m = heatmap(data,'ColorbarVisible','off')
% p = caxis
% colormap jet
% n = heatmap(data2,'ColorbarVisible','off')
% colormap jet
% 
% xlim({'1','1'})
% ylim({'1','10'})

% figure(2)
% hold on
% yyaxis left
% plot(resp(:,1),resp(:,2)+13.29)
% ylabel("Wind Voltage (mV)");
% 
% yyaxis right
% plot(respT(:,1)-4.59,respT(:,10))
% ylabel("Thrust Value (N)");
% xlabel("Time (s)");
% title("Demonstration of Wind Sensor Range");
% legend("Wind Response","Thrust Response");
% hold off

figure(3)
title("PWM_r");
hold on
plot(pwm_r_comparison(:,1),pwm_r_comparison(:,8))
plot(pwm_r(:,1),pwm_r(:,10))
plot(pwm_r_comparison(:,1),pwm_r_comparison(:,7))

legend("Desired","Actual Thrust","Kalman Estimation")

figure(2)
hold on
plot(wind(:,1),wind(:,8),'k')
plot(wind(:,1),wind(:,7)+.15,'r')
plot(wind_control(1959:end,1),wind_control(1959:end,7),'g')
legend("Desired Thrust","No Control","Control")
xlabel("Time (s)"); ylabel("Thrust (N)"); title("Response of Control System to Wind Disturbance");
