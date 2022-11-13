clear all
clc

%parametri kontaktne mreže 25kV, 50 Hz
%dvokolosjeèna s 4 povratne traènice
%kontaktni vodiè
Rk = 0.1759; %[ohm/km]
rk = 0.006; %[m]
Sk = 100; %[mm2]
%nosivo uže ECu 120
Ru = 0.153; %[ohm/km]
ru = 0.00635; %[m]
Su = 120; %[mm2]
%traènica 60E1 (UIC 60)
O = 68.5; %[cm]
rot = 0.22; %[ohm*mm2/m]
ut = 250; %[permeabilnost]
%meðusobne udaljenosti elemenata
S = 1.4; %[m]
A = 60; %[m]
Dk = 4; %[m]
Dt = 1.507; %[m]
h = 5.5; %[m]
%okolno zemljište
ro = 300; %[ohm*m]
Y = 1.3; %[S/km]


%proraèun
%impedancija petlje kontaktni vodiè - zemlja
Zk = Rk+0.0493+0.1446i*(2.08-log10(rk)+0.5*log10(ro))
[Theta, Apsolutno] = cart2pol(real(Zk), imag(Zk));
Theta = radtodeg(Theta)
Apsolutno


%impedancija petlje nosivo uže - zemlja
Zu = Ru+0.0493+0.1446i*(2.08-log10(ru)+0.5*log10(ro))
[Theta, Apsolutno] = cart2pol(real(Zu), imag(Zu));
Theta = radtodeg(Theta)
Apsolutno


%meðusobna impedancija kontaktni vodiè - nosivo uže
F = 1.95*10^(-4)*A^2
Dku = S - (2/3)*F
Zku = 0.0493+0.1446i*(1.97-log10(Dku)+0.5*log10(ro))
[Theta, Apsolutno] = cart2pol(real(Zku), imag(Zku));
Theta = radtodeg(Theta)
Apsolutno



%impedancija voznog voda
Zv = (Zk*Zu-Zku^2)/(Zk+Zu-2*Zku)
[Theta, Apsolutno] = cart2pol(real(Zv), imag(Zv));
Theta = radtodeg(Theta)
Apsolutno



%meðusobna impedancija voznih vodova dva kolosjeka
Za = 0.0493+0.1446i*(1.97-log10(Dk)+0.5*log10(ro))
[Theta, Apsolutno] = cart2pol(real(Za), imag(Za));
Theta = radtodeg(Theta)
Apsolutno



%impedancija povratnog voda
Rt = (0.28/O)*sqrt(rot*50*ut)
rt = O*10^(-2)/(2*pi)
Zp = 0.25*Rt+0.0493+0.1446i*(1.97+1.3*Rt-0.25*log10(rt)-0.25*log10(Dt)-0.5*log10(Dk)+0.5*log10(ro))
[Theta, Apsolutno] = cart2pol(real(Zp), imag(Zp));
Theta = radtodeg(Theta)
Apsolutno




%meðusobna impedancija vozni vod - povratni vod
Hekv = h+0.5*S-(1/3)*F
bv1=sqrt((Dt/2)^2+Hekv^2)
bv2=bv1
bv3=sqrt(Hekv^2+(Dk-(Dt/2))^2)
bv4=sqrt(Hekv^2+(Dk+(Dt/2))^2)
b=nthroot(bv1*bv2*bv3*bv4, 4)
Zvp = 0.0493+0.1446i*(1.97-log10(b)+0.5*log10(ro))
[Theta, Apsolutno] = cart2pol(real(Zvp), imag(Zvp));
Theta = radtodeg(Theta)
Apsolutno




%impedancija kontaktne mreže
%optereæenje u blizini elektrovuène podstanice (kp*l-->0)
Zkm1 = Zv+Zp-2*Zvp
[Theta, Apsolutno] = cart2pol(real(Zkm1), imag(Zkm1));
Theta = radtodeg(Theta)
Apsolutno

%znaèajno udaljeno optereæenje od elektrovuène podstanice (kp*l-->INF)
Zkm2 = Zv-(Zvp^2/Zp)
[Theta, Apsolutno] = cart2pol(real(Zkm2), imag(Zkm2));
Theta = radtodeg(Theta)
Apsolutno

%srednja vrijednost impedancije kontaktne mreže
Zkm = (Zkm1+Zkm2)/2
[Theta, Apsolutno] = cart2pol(real(Zkm), imag(Zkm));
Theta = radtodeg(Theta)
Apsolutno



















