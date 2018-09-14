load("pulse1T.mat");
pulse1T = Data;
load("pulse2T.mat");
pulse2T = Data;
load("pulse3T.mat");
pulse3T = Data;
load("pulse4T.mat");
pulse4T = Data;
load("step1T.mat");
step1T = Data;
load("step2T.mat");
step2T = Data;
load("step3T.mat");
step3T = Data;
load("step4T.mat");
step4T = Data;

pulse1 = csvread("pulse1.csv",1,0);
pulse2 = csvread("pulse2.csv",1,0);
pulse3 = csvread("pulse3.csv",1,0);
pulse4 = csvread("pulse4.csv",1,0);

step1 = csvread("step1.csv",1,0);
step2 = csvread("step2.csv",1,0);
step3 = csvread("step3.csv",1,0);
step4 = csvread("step4.csv",1,0);