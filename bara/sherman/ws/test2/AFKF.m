%% This is for IMU/Optical Flow/Sonar sensor fusion algorithm 
clc
clear 
close all


%% Load Kalman matrices 
load('input1.mat')
load('Kalman1.mat')
load('measured1.mat')
load('true1.mat')
load('xhafkf.mat')
FAKF = readfis('FAKF');


%% Kalman Declaration
xh= zeros(2,1);
P= eye(2);
Crk=0;
N=50; % estimation window
        
Ad = [0.9998  0.009851; -0.0394    0.9702];
Bd = [0.000198; 0.0394];
Cd = [1 0];

Q = 1;
R = diag([0.2,5]);
H1 = [1 0];
Ts = 0.0001;

%% Kalman Procedure

 for counter = 2:50000
% Model information
xh_bar(:,counter) = xh(:,counter-1)+(Ad * xh(:,counter-1) + Bd * input1(counter,1))*Ts;
P_bar = Ad * P * Ad' + R;

% Measurement update

K = P_bar * Cd' * (Cd * P_bar * Cd' + Q)^-1;
S1= Cd * P_bar * Cd' + Q;
xh = xh_bar +  K * (measured1(counter,1) - Cd * xh_bar(:,counter));
P = (1 - K * Cd) * P_bar;

% R matrix adaptation
r= Cd * xh_bar(:,counter);
% 

% Fuzzy code begins 

for s= counter-N+1:counter 
Crk=Crk+((r)*(r)'/N);
%Crk=((r)*(r)'/N);
end
 
DoM(1,1)=S1(1,1)- Crk(1,1);% deg of Matching 
Domk= 2*DoM(1,1); % Input for the FIS
Domk= min(max(Domk,-10),10);
R_delta(1,1)=evalfis(Domk,FAKF);
R(1,1)=R(1,1)+0.001*R_delta(1,1);% 0.0018 for the disturbance rejection

end
 
% %% RMSE calculations for each state
% K=1:11;
% RMSE = sqrt(mean((states.signals.values(2000:3000,K) - X_KF(K,2000:3000)').^2))';% sqrt(mean(real - estimated).^2))'

%% State estimation plots 

i =1:50000;

figure (1)
plot(i/100,measured1(i,1),'g')
hold on
plot(i/100,true1(i,1),'r','linewidth',2)
plot(i/100,xh(1,i),'b','linewidth',2)
plot(i/100,xhafkf(1,i)','c','linewidth',2)
xlabel('Time (sec)','fontsize',22)
ylabel('Thrust(N)','fontsize',22)
set(gca,'fontsize',22)
legend('Measured','Real','KF','AFKF')
grid on

% xlim([0 50])



