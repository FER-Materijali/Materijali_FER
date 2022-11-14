%%
Ra = 2.6;
Ke = 0.0076776;
Km = 0.007683;
Jm = 33.87e-7;
Jeq = 9.785e-5;
Beq = 0.0015;
Kg = 14;
Eff_G = 0.9;
Eff_M = 0.69;
%%
Kp = 41.55;
%%
num = (Eff_G*Eff_M*Km*Kg);
den = [Jeq*Ra (Beq*Ra+Eff_G*Eff_M*Ke*Km*Kg*Kg)];
gs = tf (num, den);
%%
intg = tf ([0 1], [1 0]);
%% alpha
a = tand(51.5) + sqrt((tand(51.5))^2+1);
%% kompenzator
num_k = [1*a 100];
den_k = [1 100*a];
komp = tf (num_k, den_k);

%%
margin(komp)

%%
hFig = figure(1);
set(hFig, 'Position', [1200 200 1024 768]);
%%
margin(Kp*gs*intg*komp);
%%
margin(Kp*gs*intg*komp)
grid on