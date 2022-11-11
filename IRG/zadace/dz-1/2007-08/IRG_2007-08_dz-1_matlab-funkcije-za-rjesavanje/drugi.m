function out=drugi(v1,v2,v3)
%funkcija drugi(v1,v2,v3) za dana tri vrha trokuta raèuna njegovu površinu
%(povratna vrijednost)
%NAPOMENA: zadati tocke u obliku vektora,tj. vi = [a;b;c];
%(funkcija prima matrice dimenzija (3,1) )

s1 = v2 - v1;
s2 = v3 - v1;

n(1) = s1(2)*s2(3) - s1(3)*s2(2);
n(2) = -( s1(1)*s2(3) - s1(3)*s2(1) );
n(3) = s1(1)*s2(2) - s1(2)*s2(1);

P = sqrt( n(1)^2 + n(2)^2 + n(3)^2 )/2;

out = P;