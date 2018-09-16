pwm_reduc_compT= csvread("friday_night/pwm_r_comparison.csv",1,0);
%  curr_testtorq = pt;
[r,c] = find(pwm_reduc_compT(:,10) == 0);
pwm_reduc_compT(r,:) = [];

% [r,c] = find(curr_testtorq(:,9) == 0);
% 
% curr_testtorq(r,:) = [];
% 
clear r c