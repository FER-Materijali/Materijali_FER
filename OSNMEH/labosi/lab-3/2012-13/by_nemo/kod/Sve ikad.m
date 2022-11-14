%%
Ra = 2.6;
Ke = 0.0076776;
Km = 0.007683;
Jm = 33.87e-7;
%Jeq = 9.785e-5;
Jeq = 2e-3;
Beq = 0.0015*6; %modificirano za real stuff
Kg = 70;
Eff_G = 0.9;
Eff_M = 0.69;
%%
Kp = 165.5; %%160 za Beq 5x
%%
Kp = 41.5;
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
[Gm,Pm,Wgm,Wpm]= margin(gs*intg*komp*Kp)
%%
margin(gs*intg*komp*Kp)