[y, fs] = wavread('samo.wav');
plot(y);
t = ginput(12);
t = round(t);

in = [t(1:2:12)' t(2:2:12)'];

x = y(in(2,1):in(2,2));     % odabir glasa
N = length(x);              % duzina vektora x
x = x/max(abs(x));          % normalizacija
%H = 5;    
% izlazna entropija
snrx_rez=zeros(1,30);
H_vek=zeros(1,30);
j=1;

for lj=0.5:0.5:15

H=lj;


Ndct = 8;                   % duljina bloka
nb = floor(N/Ndct);         % broj cijelih blokova
                            % u signalu
x = x(1:nb*Ndct);           % odstrani visak uzoraka
xm = zeros(Ndct,nb);        % pripremi polje za blokove signala
xm(:) = x;                  % napuni stupce polja blokovima

tr = dctm(Ndct);            
ym = tr*xm;


[hX,sig2_x,SQNR0x] = MT04_diff_entr(x,0);
Dx = 2^(hX-H);              % korak kvantizacije za x

hy = zeros(Ndct,1);
sig2_y = zeros(Ndct,1);
SQNR0y = zeros(Ndct,1);

for i = 1:Ndct
    [hY(i),sig2_y(i),SQNR0y(i)] = MT04_diff_entr(ym(i,:),0);
end

mhY = mean(hY);
Dy = 2^(mhY-H);             % korak kvantizacije za y

xi = round(x/Dx);           % izlazni indeksi kvantizatora
xq = Dx*xi;                 % kvantizirani signal
erx = x-xq;                 % pogreška kvantizatora
Ex_er = mean(erx.^2);       % oèekivanje kvadrata pogreške
SNRx = 10*log10(sig2_x/Ex_er);  % stvarni odnos dignal sum [dB]

snrx_rez(j)=SNRx;

kodx = [min(xi):max(xi)];        % svi kodovi od min do max
pdfx = hist(xi,kodx)/length(x);  % pdf indeksa

kod_postoji = find(pdfx>0);      % kodovi koji se koriste
% Entropija
HIx=-pdfx(kod_postoji)*log2(pdfx(kod_postoji))';
H_vek(j) = HIx;

j=j+1;

yi = round(ym/Dy);          % izlazni indeksi kvantizatora
yq = Dy*yi;                 % kvantizirani signal
ery = ym-yq;                % pogreska kvantizacije
Ey_eri = mean((ery').^2);   % ocekivanje kvadrata pogreske po koef.

Ey_er = mean(Ey_eri);               % ukupno srednje izoblicenje
Eyi = mean((ym').^2);               % ocekivanje kvadrata koef.
Ey = mean(Eyi);                     % srednja energija svih koef.
SNRyi = 10*log10(Eyi'./Ey_eri');    % stvarni odnos signal sum po koef. [dB]
SNRy = 10*log10(Ey/Ey_er);          % stvarni odonos signal sum [dB]

HIy = zeros(Ndct,1);
for i = 1:Ndct
    kody = [min(yi(i,:)):max(yi(i,:))];     % svi kodovi od min do max
    pdfy = hist(yi(i,:),kody)/nb;           % pdf indeksa
    kod_postoji = find(pdfy>0);
    HIy(i) = -pdfy(kod_postoji)*log2(pdfy(kod_postoji))';
end

kod = [min(yi(3,:)):max(yi(3,:))];      % svi kodovi od min do max
pdf = hist(yi(3,:),kod)/nb;             % pdf indeksa
[e, al, m] = MT02_huffman(kod, pdf);    % kodna tablica i entropije
str = MT02_huff_enc(yi(3,:),m,1);       % huffman kodiranje
ydekod = MT02_huff_dec(str,m);          % huffman dekodiranje
raz1 = sum(abs(ydekod-yi(3,:)));        % razlika

xr = tr'*yq;
xr = xr(:);

xrk = zeros(Ndct, length(xr));
for i = 1:Ndct
    izdvoji = zeros(Ndct);
    izdvoji(i,i) = 1;
    yqk = izdvoji*yq;
    xrk_matr = tr'*yqk;
    xrk(i,:) = xrk_matr(:);
end

end

plot(H_vek,snrx_rez); %drugi