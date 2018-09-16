wind_d= csvread("paper_data/wind_disturbance.csv",1,0);
%  curr_testtorq = pt;
[r,c] = find(wind_d(:,10) == 0);
wind_d(r,:) = [];

% [r,c] = find(curr_testtorq(:,9) == 0);
% 
% curr_testtorq(r,:) = [];
% 
clear r c