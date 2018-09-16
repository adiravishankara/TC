wind= csvread("last_tests/wind.csv",1,0);
%  curr_testtorq = pt;
[r,c] = find(wind(:,10) == 0);
wind(r,:) = [];

% [r,c] = find(curr_testtorq(:,9) == 0);
% 
% curr_testtorq(r,:) = [];
% 
clear r c