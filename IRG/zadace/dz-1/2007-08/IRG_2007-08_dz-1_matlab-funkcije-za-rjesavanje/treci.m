function treci(v1,v2,v3,t1,t2)
%funkcija treci(v1,v2,v3,t1,t2) za dane vrhove trokuta v1,v2,v3 ispisuje
%odnos toèaka t1 i t2 u odnosu na trokut (jesu li unutar ili izvan trokuta)
%
%NAPOMENA: svi vrhovi i toèke moraju biti zadani kao vektori, tj. u obliku
%[x0;y0;z0]
%(funkcija prima matrice dimenzija (3,1) )

s1 = v2-v1;
s2 = v3-v2;
s3 = v1-v3;

p1 = t1-v1;
p2 = t1-v2;
p3 = t1-v3;

r1 = t2-v1;
r2 = t2-v2;
r3 = t2-v3;

n1 = deter(s1,p1);
n2 = deter(s2,p2);
n3 = deter(s3,p3);

if( (sum(sign(n1) ~= sign(n2)) == 0) && (sum(sign(n1) ~= sign(n3)) == 0))
    disp ('Tocka t1 je unutar trokuta!');
else
    disp ('Tocka t1 je izvan trokuta!');
end

n1 = deter(s1,r1);
n2 = deter(s2,r2);
n3 = deter(s3,r3);

if( (sum(sign(n1) ~= sign(n2)) == 0) && (sum(sign(n1) ~= sign(n3)) == 0))
    disp ('Tocka t2 je unutar trokuta!');
else
    disp ('Tocka t2 je izvan trokuta!');
end