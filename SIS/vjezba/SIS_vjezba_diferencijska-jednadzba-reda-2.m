clear;
n_max=30;
% vremenska os
n=[0:n_max];

% Odziv mirnog sustava vlastitim frekvencijama
ym_vlast=sqrt(3)/9*(2.^(-n)).*cos(pi/3*n+5*pi/6);

% Odziv nepobudjenog sustava vlastitim frekvencijama
y0=(2.^(1-n)).*cos(pi/3*n+2*pi/3);

% Pocetna faza ukupnog titranja vlastitim frekvencijama
an=atan2(19*sqrt(3)/36,-7/12);

% Ukupno titranje vlastitim frekvencijama
y_prir=sqrt(127/3)/6*(2.^(1-n)).*cos(pi/3*n+an);

% pokazi da je y_prir jednak sumi ym_vlast i y0
disp(max(abs(y_prir-(y0+ym_vlast))))

% partikularno rjesenje ... titranje frekvencijama pobude
y_par=4*sqrt(3)/9*cos(2*pi/3*n+pi/6);

% totalni odziv (suma titranja vlastitim frekvencijama i
% prisilnog odziva)
ytot=y_prir+y_par;

% Ukupni odziv mirnog sustava
y_mir=ym_vlast+y_par;

% Pobuda sustava
u=1*cos(2*pi/3*n+pi/3);

% Inicijaliziraj vektor odziva za metodu korak po korak
y=0*u;

% Odredi odziv metodom korak po korak
y_nm_2=8;     % pocetna vrijednost y(n-2) za n=0 ... y(-2)
y_nm_1=2;     % pocetna vrijednost y(n-1) za n=0 ... y(-1)

% koeficijenti jedn. dif. uz y(n-1) i y(n-2)
a1=-1/2;
a2=1/4;

% koef. jedn. dif. uz u(n)
b0=1;

for nn=0:n_max,
   % Zbog Matlaba koji ne pozna indekse polja koji su manji od
   % jedan ... vremenski indeks n=0 pretvaramo u indeks polja 1
   nM=nn+1;
   % Jednadzba diferencije ...
   ykk(nM)= -a1*y_nm_1 -a2*y_nm_2 +b0*u(nM);
   
   % za novi prolaz petlje (n+1)
   y_nm_2=y_nm_1;     % y((n+1)-2) = y(n-1)
   y_nm_1=ykk(nM);    % y((n+1)-1) = y(n)
   
end;

% Usporedi analiticko rjesenje i ono dobiveno metodom korak po korak
disp(max(abs(ykk-ytot)))

figure(1);
stem(n,u)
title('Pobuda sustava');
grid;

figure(2);
stem(n,y0)
title('Odziv nepobudjenog sustava');
grid;

figure(3);
stem(n,ym_vlast)
title('Odziv mirnog sustava vlastitim frekvencijama');
grid;

figure(4);
stem(n,y_par)
title('Prisilni odziv sustava');
grid;

figure(5);
stem(n,y_prir)
title('Prirodni odziv sustava');
grid;

figure(6);
stem(n,y_mir)
title('Ukupni odziv mirnog sustava');
grid;

figure(7);
stem(n,ytot)
title('Ukupni odziv sustava - analiticko rjesenje');
grid;

figure(8);
stem(n,ykk)
title('Ukupni odziv sustava - korak po korak');
grid;

