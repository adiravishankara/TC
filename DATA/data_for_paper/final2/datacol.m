pt= csvread("../final3/thr2pwm.csv",1,0);
%  curr_testtorq = pt;
[r,c] = find(pt(:,10) == 0);

pt(r,:) = [];

% [r,c] = find(curr_testtorq(:,9) == 0);
% 
% curr_testtorq(r,:) = [];
% 
clear r c