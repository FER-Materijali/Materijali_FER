%% LABOS 3
% Zadatak 2.3

% impulsni odzivi
h1 = [-16, -19, -22, -24, -25, 230, -25, -24, -22, -19, -16];
h1 = h1 / 256;

h2 = [16, 19, 22, 24, 25, 26, 25, 24, 22, 19, 16];
h2 = h2 / 256;

subplot(2,1,1), plot(h1, 'g');
subplot(2,1,2), plot(h2, 'r');

% generiranje suma
n1 = rand(11,1);
n2 = randn(11,1);

%% USREDNJENI PERIODOGRAM H1*N1
N = 11;
H1 = fft(h1, N);
N1 = fft(n1, N);

X1 = H1' .* N1;

% snaga
for i=1:N
    tmp1 = fft(X1(i));
    tmp2 = abs(tmp1);
    Pxx1(i) = 1/i * tmp2 * tmp2;
end

% procjena spektralna gustoca snage
Sxx1 = zeros(N,1);
for i=1:N
    Sxx1(i) = Sxx1(i) + Pxx1(i);
end

plot(Sxx1);

%% USREDNJENI PERIODOGRAM H1*N2
N = 11;
H1 = fft(h1, N);
N2 = fft(n2, N);

X2 = H1' .* N2;

% snaga
for i=1:N
    tmp1 = fft(X2(i));
    tmp2 = abs(tmp1);
    Pxx2(i) = 1/i * tmp2 * tmp2;
end

% procjena spektralna gustoca snage
Sxx2 = zeros(N,1);
for i=1:N
    Sxx2(i) = Sxx2(i) + Pxx2(i);
end

plot(Sxx2);

%% USREDNJENI PERIODOGRAM H2*N1
N = 11;
H2 = fft(h2, N);
N1 = fft(n1, N);

X3 = H2' .* N1;

% snaga
for i=1:N
    tmp1 = fft(X3(i));
    tmp2 = abs(tmp1);
    Pxx3(i) = 1/i * tmp2 * tmp2;
end

% procjena spektralna gustoca snage
Sxx3 = zeros(N,1);
for i=1:N
    Sxx3(i) = Sxx3(i) + Pxx3(i);
end

plot(Sxx3);

%% USREDNJENI PERIODOGRAM H2*N2
N = 11;
H2 = fft(h2, N);
N2 = fft(n2, N);

X4 = H2' .* N2;

% snaga
for i=1:N
    tmp1 = fft(X4(i));
    tmp2 = abs(tmp1);
    Pxx4(i) = 1/i * tmp2 * tmp2;
end

% procjena spektralna gustoca snage
Sxx4 = zeros(N,1);
for i=1:N
    Sxx4(i) = Sxx4(i) + Pxx4(i);
end

plot(Sxx4);

%% Zadatak 3.3
% signal
M = 200;
for i=1:M
    x(i) = sin(pi*i/100);
end

h = -x;

% prilagodeni filtar
Rhh = xcorr(h);
plot(Rhh); title('Autokorelacijska funkcija');

% gaussov bijeli sum
n = randn(2000,1);
N = fft(n,M);

% sum + signal
xn = n;

for i=501:700
    xn(i) = xn(i) + x(i-500);
end

% filtriranje signala
y = conv(h, xn);
plot(y);

%% Zadatak 3.5

% import glasova
[x1, fs1, nbits1]=wavread('a05.wav');
[x2, fs2, nbits2]=wavread('u05.wav');

% skracivanje glasova
a = x1(1:2000);
u = x2(1:2000);

    % generiranje gaussovog bijelog suma
N = 1 + 2.*randn(20000,1);

x = N

for i=1:2000
    x(i+2000) = x(i+2000) + a(i);
end
for i=1:2000
    x(i+10000) = x(i+10000) + u(i);
end

subplot(3,1,1), plot(a);
subplot(3,1,2), plot(u);
subplot(3,1,3), plot(x);

% za posluhnuti...
soundsc(x,fs1);

%% Zadatak 3.6

% impulsni odzivi glasova
ha = -a;
Rha = xcorr(ha);

hu = -u;
Rhu = xcorr(hu);

figure
subplot(2,1,1), plot(Rha);
title('Autokorelacija');
subplot(2,1,2), plot(Rhu);

% kroskorelacija
Rau = xcorr(a, -u);
Rua = xcorr(-a, u);

figure
subplot(2,1,1), plot(Rau);
title('Kroskorelacija');
subplot(2,1,2), plot(Rua);

%% Zadatak 3.7

[x1, fs1, nbits1]=wavread('a05.wav');
[x2, fs2, nbits2]=wavread('u05.wav');

% skracivanje glasova
a = x1(1:2000);
u = x2(1:2000);

    % generiranje gaussovog bijelog suma
N = 1 + 2.*randn(20000,1);
x = N
for i=1:2000
    x(i+2000) = x(i+2000) + a(i);
end
for i=1:2000
    x(i+10000) = x(i+10000) + u(i);
end

aa = conv(x,-a);
figure
subplot(3,1,1), plot(a);
subplot(3,1,2), plot(x);
subplot(3,1,3), plot(aa);

uu = conv(x,-u);
figure
subplot(3,1,1), plot(u);
subplot(3,1,2), plot(x);
subplot(3,1,3), plot(uu);

figure
subplot(2,1,1), plot(aa);
subplot(2,1,2), plot(uu);

%% Zadatak 4.11

% signal
h1 = [-16, -19, -22, -24, -25, 230, -25, -24, -22, -19, -16];
h1 = h1 / 256;

% obojeni sum nn
for i=1:12
    n = randn(8001 + 22, 1);
    pom = conv(n, h1');
    pom = wkeep(pom, 8001);
    % obojeni sum
    nn(:,i) = pom;
end

%% Zadatak 4.12

N = 12;

for i=1:N
    pom_a = sprintf('a%02d.wav',i);
    pom_u = sprintf('u%02d.wav',i);
    
    [ya, fsa, nbitsa] = wavread(pom_a);
    [yu, fsa, nbitsa] = wavread(pom_u);
    
    A(:,i) = ya;
    U(:,i) = yu;

    yya = wkeep(ya, 8001);
    yyu = wkeep(yu, 8001);
    
    out_a(:,i) = yya + 50*nn(:,i);
    out_u(:,i) = yyu + 50*nn(:,i);
end

%% Zadatak 4.13

% spektar procesa A i U preko autokorelacijske funkcije

Ra = akf_sa(A);
Ru = akf_sa(U, 12000);

Sa = sgs(Ra);
Su = sgs(Ru);













