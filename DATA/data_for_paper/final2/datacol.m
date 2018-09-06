wind= csvread("new_/wind.csv",1,0);
% dist_testtorq = dist_test;
[r,c] = find(wind(:,10) == 0);

wind(r,:) = [];

% [r,c] = find(dist_testtorq(:,9) == 0);
% 
% dist_testtorq(r,:) = [];
% 
