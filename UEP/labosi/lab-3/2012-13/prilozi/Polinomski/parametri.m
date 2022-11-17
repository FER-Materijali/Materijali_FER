
if (r == 0.2)
    Tm1 = 0.1;
    Tm2 = 0.02 ;
    d = 0.05 ;
    c = 15 ;
    Tb = 1 ;
end

if (r == 1 )
    Tm1 = 0.1 ;
    Tm2 = 0.1 ;
    d = 0.05 ;
    c = 45 ;
    Tb = 1 ;
end

if (r == 5)
    Tm1 = 0.1 ;
    Tm2 = 0.5 ;
    d = 0.05 ;
    c = 75 ;
    Tb = 1 ;
end

Tms = Tm1 + Tm2 ;
w0 = sqrt(c/Tb*(1/Tm1+1/Tm2)) ;
zeta = Tb*d/c*w0/2 ;
w01 = sqrt(c/Tb/Tm1) ;
w02 = sqrt(c/Tb/Tm2) ;
zeta1 = Tb*d/c*w01/2 ;
zeta2 = Tb*d/c*w02/2 ;

T = 1/w0 ;
Te = 2*sqrt(2)*T ;
Tei = 2e-3 ;