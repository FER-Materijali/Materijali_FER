%%
close all;
clear all;

%uRx
fs=200e6;
tmax=50e-6;
t=(0:1/fs:tmax);
t=t(:);
fRF=50e6;
BRF=2e6;
fIF=5e6;
B=500e3;

uRX=sinc(8*pi*BRF*(t-tmax/4)).*square(2*pi*fRF*t);
figure;
plot(t,uRX);

N=length(t);
w=blackman(N);
suma=sum(w);
URX=fftshift(fft(uRX.*w,2*N))/suma;
f=fos(2*N,fs);

figure;
plot(f,20*log10(abs(URX))); %crtanje spektra signala na ulazu u prijemnik

%% Filtri
fosc=fRF-fIF;
uosc=cos(fosc*2*pi*t); %oscilator

fd=49e6;
fg=51e6;
fsH=20e6;

[z,p,k]=cheby1(4,0.5,[fd fg]*2*pi,'s'); %projektiranje RF filtra
HRF=zpk(z,p,k);
hrf=impulse(HRF,t);
brojnik=real(k*poly(z));
naz=real(poly(p));
HRF=freqs(brojnik,naz,2*pi*f);

fg2=fsH/2;
[z,p,k]=ellip(6,0.5,80,fg2*2*pi,'s'); %projektiranje IF filtra
HIF=zpk(z,p,k);
hif=impulse(HIF,t);
brojnik=real(k*poly(z));
naz=real(poly(p));
HIF=freqs(brojnik,naz,2*pi*f);

figure;
plot(f,20*log10(abs(HRF)),'r',f,20*log10(abs(HIF)),'g');

%%
yrf=conv(uRX,hrf)/fs;
yrf=yrf(1:N);
yrf=10*yrf; % konvolucija signala sa RF filtrom i pojacanje*10

YRF=fftshift(fft(yrf.*w,2*N))/suma; %spektar signala na izlazu iz RF filtra

y2=yrf.*uosc; %mnozenje signala sa oscilatorom

yif=conv(y2,hif)/fs;
yif=yif(1:N);
yif=10*yif; %konvolucija signala nakon miješala za IF filtrom

YIF=fftshift(fft(yif.*w,2*N))/suma; %spektar


figure;
plot(f,20*log10(abs(YRF)),'r',f,20*log10(abs(YIF)),'g',f,20*log10(abs(URX)),'b'); %prikaz spektara izlaznih signala iz RF i IF filtra te pocetnog signala

%% AD pretvornik
D=fs/fsH;

tH=t(1:D:end); %uzimamo svaki D-ti uzorak
N2=length(tH);
fH=fos(2*N2,fsH);
yad=yif(1:fs/fsH:end); %uzimamo svaki D-ti uzorak, izlaz iz AD-a
yad=yad(1:N2);

w2=blackman(N2);
suma2=sum(w2);
Yad=fftshift(fft(yad.*w2,2*N2))/suma2;
figure;
plot(fH,20*log10(abs(Yad))); %spektar izlaza iz AD-a

%% Mnozenje sa kompleksnom eksponencijalom
wNCO=fIF*2*pi/fsH; % uzimamo fIH jer nam treba tocno taj kanal koji se nalazi na toj frekvenciji,
%a dijelimo sa fsH jer prelazimo u digitalnu domenu 
%(imali smo AD sa frek.uzorkovanja fsH)

n=tH.*fsH; 

yulc=yad.*exp(j*wNCO*n); %mnozenje sa exp

Yulc=fftshift(fft(yulc.*w2,2*N2))/suma2;
figure;
plot(fH,20*log10(abs(Yulc))); 


%% CIC decimator

fsL=2e6; %zeljena frekvencija uzorkovanja na izlazu
R=fsH/fsL; %faktor decimacije R
tL=tH(1:R:end); % sada moramo uzeti svaki R-ti uzorak od nase tH jer smo smanjili frekvenciju uzorkovanja za R
N3=length(tL); %novi broj uzoraka
fL=fos(2*N3,fsL); %nova frek.os

Ncic=6; %red decimator koji je potreban da se priguse aliasi
hcic=1;
hcic1=(1/R).*ones(1,R);
for i=1:Ncic
    hcic=conv(hcic,hcic1); %racunamo impulsni odziv decimatora N-tog reda
end

w=fH/(fsH/2)*pi;
HCICH=freqz(hcic,1,w); % frekvencijska karakteristika decimatora "prije" tj. na samom ulazu u decimator jer jos uvijek imamo fsH
HCICL=freqz(hcic,1,w/R); %frekvencijska karakteristika nakon decimatora, tj, ona koju vide sklopovi nakon decimatora

figure;
plot(fH,20*log10(abs(HCICH)));
axis([-fsH/2 fsH/2 -140 0])

figure;
plot(w/pi*fsL/2,20*log10(abs(HCICL)));
axis([-fsL/2 fsL/2 -140 0])
    
%%

ycic=conv(yulc,hcic); % racunamo izlaz iz CIC decimatora

ycic=ycic(1:R:end);
ycic=ycic(1:N3);

w3=blackman(N3);
suma3=sum(w3);
Ycic=fftshift(fft(ycic.*w3,2*N3))/suma3;
figure;
plot(fL,20*log10(abs(Ycic)));


%% CIC kompenzator
Apass=0.1;
Astop=40;

Ap=1-10^(-Apass/2/20);
As=10^(-Astop/20);

wg=B/fsL/2; %granicna frekvencija
hCICK=firceqrip(60,wg,[Ap As],'invsinc',[1/2, Ncic],'passedge'); %impulsni odziv CIC kompenzatora
HCICK = freqz(hCICK,1,w);
figure;
plot(w/pi*fsL/2, 20*log10(abs(HCICK)));
axis([-fsL/2 fsL/2 -10 15])
%%
ycick=conv(ycic,hCICK); % izlaz iz CIC kompenzatora
ycick=ycick(1:N3);
Ycick=fftshift(fft(ycick.*w3,2*N3))/suma3;
figure;
plot(fL,20*log10(abs(Ycick)));

%% Selektor kanala
delta=0.05*B;
hch=cfirpm(409,[-fsL/2 0-delta 0 B delta+B fsL/2]/(fsL/2),[0 0 2 2 0 0]); %kompleksni fir filtar 410.reda jer tad nam je gusenje vece od 80dB
Hch=freqz(hch,1,w);
figure;
plot(w, 20*log10(abs(Hch)));
%% Racunanje realnog i imaginarnog dijela USB-AM signala
%imali smo komplekan filtar i kompleksan signal pa treba racunati posebno
%realan sa realnim dijelom i imaginarni sa imaginarnim
hchr=real(hch);
hchi=imag(hch);

ycickr=real(ycick);
ycicki=imag(ycick);

yusbr= conv(ycickr,hchr,'same'); %same ide jer nisu iste velicine
yusbi= conv(ycicki,hchi,'same');

%% demodulator
yusb=yusbr+yusbi; % zbrojimo izlaze 

Yusb=fftshift(fft(yusb.*w3,2*N3))/suma3;
figure;
plot(fL,20*log10(abs(Yusb))); %spektar USB-AM signala

%% DA pretvornik
yiz=interp(yusb,R); % trebamo ga vratiti na fH pa zato interpolacijom na R uzoraka
yiz=yiz(1:end-R+1);

figure;
plot(tL,yusb,'r',tH,yiz,'b');

Yiz=fftshift(fft(yiz.*w2,2*N2))/suma2;
figure;
plot(fH,20*log10(abs(Yiz)));



