%H = visina na koji je postavljena kamera [m]
%hmin = visina donje granice vidnog polja kamere [m]
%hc = visina gornje granice vidnog polja kamere [m]
%L = udaljenost donje granice vidnog polja od kamere [m]
%D = udaljenost gornje granice vidnog polja od kamere [m]
%wd = širina horizontalne projekcije vidnog polja na donjoj visinskoj granici [m] 
%W = širina horizontalne projekcije vidnog polja na gornjoj visinskoj granici [m] 
%alfa = horizontalni kut vidnog polja
%beta = vertikalni kut vidnog polja
%fi = nagib kamere u odnosu na horizontalu (tlo)
%f = žarišna duljina objekta

%==========================================================================
%Odaberi sluèaj "1" ili "2"
%ako je poznato "f" - sluèaj "1"
%ako je poznata "W" - sluèaj "2"
SLUCAJ=input('SLUCAJ = ');
%==========================================================================

%ODABRAN SLUCAJ 1
if SLUCAJ==1
    f=input('f = ');

%ODABRAN SLUCAJ 2
elseif SLUCAJ==2
    W=input('W = ');

%ODABRAN NEMOGUÆI SLUÈAJ
else 
error('Odabran nemoguæi SLUCAJ!!');
end

%==========================================================================
H=input('H = ');
D=input('D = ');
S=input('S[x/y"] = ');
         if S == 1/4''
             a=0.0036;
             b=0.0027;
         elseif S == 1/3''
             a=0.0048;
             b=0.0036;
         elseif S == 1/2''
             a=0.0064;
             b=0.0048;
         elseif S == 2/3''
             a=0.0088;
             b=0.0066; 
         else error('SENZOR POGREŠNO ODABRAN!!');
         end 
hc=input('hc = ');
hmin=input('hmin = ');

%==========================================================================
if SLUCAJ==1
     A= 2*atan(a/(2*f));             %alfa u radijanima
     B= 2*atan(b/(2*f));             %beta u radijanima
     alfa= 2*atan(a/(2*f))*180/pi    %alfa u stupnjevima
     beta= 2*atan(b/(2*f))*180/pi    %beta u stupnjevima
     X=atan((H-hc)/D);               
     fi=(X+(B/2))*180/pi             %fi u stupnjevima
     Y=90-(X*180/pi);
     gama=90-Y+beta;
     G=gama*pi/180;
     L=(H-hmin)/tan(G)               %L u metrima
     W=a*D/f                         %W u metrima
     wd=a*L/f                        %wd u metrima

elseif SLUCAJ==2
     f=a*D/W                         %f u metrima
     A= 2*atan(a/(2*f));             %alfa u radijanima
     B= 2*atan(b/(2*f));             %beta u radijanima
     alfa= 2*atan(a/(2*f))*180/pi    %alfa u stupnjevima
     beta= 2*atan(b/(2*f))*180/pi    %beta u stupnjevima
     X=atan((H-hc)/D);               
     fi=(X+(B/2))*180/pi             %fi u stupnjevima
     Y=90-(X*180/pi);
     gama=90-Y+beta;
     G=gama*pi/180;
     L=(H-hmin)/tan(G)               %L u metrima
     wd=a*L/f                        %wd u metrima

end
%//////////////////////////////////////////////////////////////////////////




