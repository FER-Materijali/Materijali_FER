function out=cetvrti(G1,G2)
%funkcija cetvrti(G1,G2) za zadane pravce G1 i G2 vraæa koordinate toèke
%sjecišta tih dvaju pravaca u obliku [x0 y0 z0 h0]
%
%NAPOMENA: zadati matrice u bliku Gi = [a,b,c,d; x0, y0, z0, h0];
%(funkcija prima matrice dimenzija (2,4) )
%
%NAPOMENA DRUGA: u slucaju greske, možete pretpostaviti da su pravci
%paralelni/mimosmjerni, ali ne uzimajte me za rijeè

G1 = G1./G1(2,4);
G2 = G2./G2(2,4);

A = [G1(1,1), -G2(1,1); G1(1,2), -G2(1,2)];
B = [G2(2,1)-G1(2,1); G2(2,2)-G1(2,2)];

X = linsolve(A,B);


v1 = [X(1) 1]*G1;
v2 = [X(2) 1]*G2;
if(v1 == v2)
    out = v1;
else
    A = [G1(1,1), -G2(1,1); G1(1,3), -G2(1,3)];
    B = [G2(2,1)-G1(2,1); G2(2,3)-G1(2,3)];

    X = linsolve(A,B);
    
    v1 = [X(1) 1]*G1;
    v2 = [X(2) 1]*G2;
    
    if(v1 == v2)
        out = v1;
    end
end
