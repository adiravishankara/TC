prop_faultT= csvread("../final3/paper_data/prop_fault.csv",1,0);
%  curr_testtorq = pt;
[r,c] = find(prop_faultT(:,10) == 0);
prop_faultT(r,:) = [];

% [r,c] = find(curr_testtorq(:,9) == 0);
% 
% curr_testtorq(r,:) = [];
% 
clear r c