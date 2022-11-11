function prvi(r1,r2)
%funkcija prvi(r1, r2) za dane dvije ravnine vraæa parametre pravca u kojem
%se sijeku u obliku lam*[A,B,C]' + [X0,Y0,Z0]' (lam predstavlja parametar
%lambda)
%NAPOMENA: parametre ravnina treba zadati u obliku vektora, tj. [a;b;c;d]
%(funkcija prima matrice dimenzija (4,1) )

d = zeros(3,1);     %vektor smjera pravca p
d(1) = r1(2)*r2(3) - r1(3)*r2(2);
d(2) = -( r1(1)*r2(3) - r1(3)*r2(1) );
d(3) = r1(1)*r2(2) - r1(2)*r2(1);

if(d == 0)
    disp('Ravnine su paralelne!');
end

A = [r1(1) r1(2); r2(1) r2(2)];
B = -[r1(4); r2(4)];

X0 = [linsolve(A,B); 0];

syms p lam X Y Z

p= lam*d + X0;

pretty([X;Y;Z]);
disp(' = ');
pretty(p);