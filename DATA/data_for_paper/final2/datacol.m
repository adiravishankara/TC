ramp_test = csvread("new_/ramp_test2.csv",1,0);

[r,c] = find(ramp_test(:,10) == 0);

ramp_test(r,:) = [];

