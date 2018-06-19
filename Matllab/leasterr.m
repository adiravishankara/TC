%sdData = Log20180606115949;

dt = mean(sdData.Times(2:end)-sdData.Times(1:end-1));
%sdData = sdData(S:E,:);
%sdData = [sdData(552:820,:); sdData(827:1123,:)];
%sdData = [sdData(2350:2450,:)];
i = sdData.CurrentA;
w = sdData.MotorElectricalSpeedRPM *2*pi/60;
v = sdData.VoltageV;
t = sdData.
idot = [0;(i(2:end)-i(1:end-1))/dt];
A = [w i];

p = (A'*A)\A'*v;
V = A * p;
n = mvregress(A,v)
m = mvregress(
figure(1);
plot(sdData.Times,v,sdData.Times,V)
figure(2)
plot(sdData.Times,w)