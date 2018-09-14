function xest  = kalman_model(u, y)
persistent P xh
if isempty(P)
    P = eye(2);
    xh = zeros(2,2);
end
% A = [0 1; -4 -3];
% B = [0; 4];
% C = [1 0];

Ad = [0.9998  0.009851; -0.0394    0.9702];
Bd = [0.000198; 0.0394];
Cd = [1 0];

Q = 1;
R = diag([5,5]);

% Model information
xh_bar = Ad * xh + Bd * u;
P_bar = Ad * P * Ad' + R;

% Measurement update
K = P_bar * Cd' * (Cd * P_bar * Cd' + Q)^-1;
xh = xh_bar + K * (y - Cd * xh_bar);
P = (1 - K * Cd) * P_bar;

xest = xh;