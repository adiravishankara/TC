f = b*u^a + c = 1
G = f*u + udot*f - xold = u + udot - xold

xdot = G
y = x

%% Extended Kalman Filter Estimation
% Prediction update
xh_bar = Ad * xh_old;
P_bar = Ad * P_old * Ad' + R;
% Linearization
Ht = [xh_bar(1)/(sqrt(xh_bar(1)^2 + xh_bar(3)^2)),...
      0,...
      xh_bar(3)/(sqrt(xh_bar(1)^2 + xh_bar(3)^2))];
% Measurement model
h = sqrt(xh_bar(1)^2 + xh_bar(3)^2);
% Measurement update
K = P_bar * Ht' * inv(Ht * P_bar * Ht' + Q);
xh_new = xh_bar + K * (y - h);
P_new = (eye(3) - K * Ht) * P_bar;