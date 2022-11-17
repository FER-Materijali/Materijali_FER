function  [Pint Q S] = parametri_RST(w02, zeta2, Tb, Tms, zeta, w0, DB)

s = tf('s');
z = tf('z');

N = Tms*s*(1 + 2*zeta/w0*s + 1/w0^2*s^2);
Gw1 = (w02^-2*s^2 + 2*zeta2/w02*s + 1)/N ;

T =  1/w0;

Ga1d = c2d(Gw1/s, T, 'zoh');

Guk = minreal(Tb/T*(z-1)/z*Ga1d) 

NUM = cell2mat(Guk.num);
DEN = cell2mat(Guk.den);

DENint = conv(DEN, [1 -1]) ;

k = length(DENint) - 1 ;
l = length(NUM) - 1 ;

S = zeros(k+l, k+l) ;

A = fliplr(DENint) ;
B = fliplr(NUM) ;
for j=1:(k-1)
    for i=j:(j+k)
        Sab(i,j)=A(i-j+1);
    end
end

for j= k :(k+l)
    for i=(j-k+1):(j-k+1+l)
        Sab(i,j)=B(i-j+k);
    end
end


Te = 2*sqrt(2)*T;

if (DB==1)
    Ao = z^4 ;
else
    Ao = z^3*(z-exp(-T/(2*Te/3)));
end

Ams = 1 + Te*s + 0.5*Te^2*s^2 + 0.5^3*Te^3*s^3 + 0.5^6*Te^4*s^4;
Am = c2d(Ams, T, 'matched');
Az = Ao*Am;

DENm = cell2mat(Az.num) ;

K = inv(Sab)*(fliplr(DENm)') ; 

P = fliplr(K(1:4)') ;
Pint = conv(P, [1 -1]) ;

Q = fliplr(K(5:9)') ;


S = polyval(DENm, 1) / polyval(NUM, 1) / polyval(cell2mat(Ao.num), 1) * cell2mat(Ao.num) ;


end