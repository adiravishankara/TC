function [outputArg1] = RMS(inputArg1,col)
%UNTITLED2 Summary of this function goes here
%   Detailed explanation goes here
sum = 0;
for i =1:9
    sum = sum + inputArg1(i,col)^2;
end

outputArg1 = sqrt(sum);

end
