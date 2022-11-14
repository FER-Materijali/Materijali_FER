%%
Ra=2.6;
Ke=0.0076776;
Km=0.007683;
Jeq = 2e-3;
Beq=4e-3;
Kg = 70;
Eff_G =0.9;
Eff_M =0.69;

%%
K = Eff_G*Eff_M*Km*Kg /(Beq*Ra + Eff_G*Eff_M*Ke*Km*Kg^2)
T = Jeq*Ra/(Eff_G*Eff_M*Km*Kg) * K

%%
omega = 43.4098
zeta = 0.6901

%%
Kv = (2*zeta*omega*T-1)/K
Kp = omega^2*T/K