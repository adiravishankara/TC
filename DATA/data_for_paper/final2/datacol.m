curr= csvread("new_/ramp_new.csv",1,0);
% dist_testtorq = dist_test;
[r,c] = find(curr(:,10) == 0);

curr(r,:) = [];

% [r,c] = find(dist_testtorq(:,9) == 0);
% 
% dist_testtorq(r,:) = [];
% 
