function [Ti, Kw1, Kw2, Kda] = parametri_reg(Tm1, Tm2, d, c, Tei, T, Tb, D)

D2 = D(1);
D3 = D(2);
D4 = D(3);
D5 = D(4);

Ts = Tei + T;
Tms = Tm1 + Tm2;

w0 = sqrt(c/Tb*(1/Tm1+1/Tm2));
zeta = Tb*d/(2*c)*w0;
w01 = sqrt(c/Tb/Tm1);
w02 = sqrt(c/Tb/Tm2);
zeta1 = Tb*d/(2*c)*w01;
zeta2 = Tb*d/(2*c)*w02;

Te = Ts/(D5*D4*D3*D2*(1+2*zeta*w0*Ts));
Ti = Te - 2*zeta2/w02;
Kw1 = Tms*w02^2/w0*((2*zeta*w0*Ts+1)/(D4*D3*D2*Te*w0) - Ts*w0 - 2*zeta);
Kw2 = Ti*Tms*(1+2*zeta*w0*Ts)/(D4*D3^2*D2^3*Te^4*w0^2)-Kw1;
Kda = (D2*Te^2*w02^2 - (Kw1 + Kw2)^-1*Ti*Tms*w02^2-2*zeta2*Ti*w02)/((Kw1+Kw2)^-1*Ti);

end