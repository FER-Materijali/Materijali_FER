%Optimalni FIR
close all;
N=12;
wp=0.2;
ws=0.3;
f=[0 wp ws 0.5];
m=[1 1 0 0];
W=[4 1];
b = remez(N,2*f,m,W);
n =[0 : N]
stem(n,b), title('h(n)');
brt = 1024;
om = [0 : (brt-1)] / brt*0.5;
H= freqz(b,1,2*om*pi);
A=abs(H);
Adb=log(A);
figure
SUBPLOT(2,1,1), plot(om,A), title('|H|'), xlabel('om');
SUBPLOT(2,1,2), plot(om,Adb), title('log|H|'),xlabel('om'), ylabel('dB');

omp = [0 : (brt-1)] / brt *wp;
H= freqz(b,1,2*omp*pi);
AHp=abs(H)
figure
plot(omp,AHp), title('AHp');
mnAHp=min(AHp);
mxAHp=max(AHp);

oms = [0 : (brt-1)] / brt *(0.5-ws) +ws;
H= freqz(b,1,2*oms*pi);
AHs=abs(H)
figure
plot(oms,AHs), title('AHs');
mnAHs=min(AHs);
mxAHs=max(AHs);