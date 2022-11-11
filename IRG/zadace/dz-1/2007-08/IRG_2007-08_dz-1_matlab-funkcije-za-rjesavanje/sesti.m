function out=sesti(v1,v2,v3,t)
%funkcija sesti(v1,v2,v3,t) za trokut zadan vrhovima v1,v2,v3, u smjeru
%L(v1,v2,v3) vraca parametre pravaca na kojima leže bridovi trokuta, u
%obliku
%[a b c]
%[a b c]
%[a b c]
%pri èemu je u svakom RETKU matrice opisan po jedan pravac.
%Takoðer za danu toèku t ispisuje njen odnos prema svakome bridu.
%
%NAPOMENA: koordinate vrhova kao i toèke t zadajete kao vektor, tj. [x;y];
%primjer:
%>>sesti([2;-8],[-7,-6],[-1,1],[8,-3])
%Tocka je ispod brida b1!
%Tocka je ispod brida b2!
%Tocka je iznad brida b3!
%ans =
%    -2    -9   -68
%    -7     6   -13
%     9     3     6



s1 = v2-v1;
s2 = v3-v2;
s3 = v1-v3;

%vektori normale:
n1 = [-s1(2);s1(1)];
n2 = [-s2(2);s2(1)];
n3 = [-s3(2);s3(1)];

b1=zeros(3,1);
c1 = -n1(1)*v1(1)-n1(2)*v1(2);
b1 = [n1;c1];

b2=zeros(3,1);
c2 = -n2(1)*v2(1)-n2(2)*v2(2);
b2 = [n2;c2];

b3=zeros(3,1);
c3 = -n3(1)*v3(1)-n3(2)*v3(2);
b3 = [n3;c3];

out = [b1'; b2'; b3'];

t = [t; 1];

if( t'*b1 > 0 )
    disp('Tocka je iznad brida b1!');
else
    disp('Tocka je ispod brida b1!');
end
    
if( t'*b2 > 0 )
    disp('Tocka je iznad brida b2!');
else
    disp('Tocka je ispod brida b2!');
end

if( t'*b3 > 0 )
    disp('Tocka je iznad brida b3!');
else
    disp('Tocka je ispod brida b3!');
end