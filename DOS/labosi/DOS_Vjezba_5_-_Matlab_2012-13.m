close all;
wp = 0.2;  
ws = 0.3;
Rp = 0.1;
Rs = 60;
[N,wc]=ellipord(wp, ws, Rp, Rs);
[b,a]=ellip(N,Rp,Rs,wc);
brt = 1024;
om = [0 : (brt-1)] / brt*pi;
B=input('unesi broj bita za kvantizaciju:  ');
amax=max(a);                                 %dio za kvantizaciju
bmax=max(b);
as=a/amax;
bs=b/bmax;
k=bmax/amax;
ak=round(as*2^(B-1))/2^(B-1);
bk=round(bs*2^(B-1))/2^(B-1);
kk=round(k*2^(B-1))/2^(B-1);
Hk = freqz((bk*kk),ak,om);                      %IIR filtar s kvantiziranim koef.
AdBk=20*log(abs(Hk));
fiHk=angle(Hk);

figure
impz(b,a,150); title('h(n)_150');           %prvih 150 uzoraka impulsnog odziva dobivenog IIR filtra

H = freqz(b,a,om);
AdB=20*log(abs(H));
fiH=angle(H);
om=om/pi;                                   %zato da frekvencijske karakteristike na x osi imaju vrijednost od 0 do 1
figure
subplot(3,1,1), plot(om,[AdB' AdBk']), title('|H|'), ylabel('dB'), xlabel('om');
subplot(3,1,2), plot(om,[fiH' fiHk']), title('fi(H)'), ylabel('rad'), xlabel('om');
subplot(3,1,3), grpdelay(b,a), title('tg'), xlabel('om');
figure
zplane(b,a), title('nekvantizirani');
figure
zplane(bk*kk,ak), title('kvantizirani');


s=ones(1,brt);
x=[1:80];
y=filter(b,a,s);
yk=filter(bk*kk,ak,s);
figure
subplot(2,1,1), plot(x,y(1:80)), title('g(n)');
subplot(2,1,2), plot(x,yk(1:80)), title('gk(n)');
