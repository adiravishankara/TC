wdpT= csvread("../final3/paper_data/wind_disturb_pulse.csv",1,0);
%  curr_testtorq = pt;
[r,c] = find(wdpT(:,10) == 0);
wdpT(r,:) = [];

% [r,c] = find(curr_testtorq(:,9) == 0);
% 
% curr_testtorq(r,:) = [];
% 
clear r c