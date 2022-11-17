function [ Bayes_parametri ] = NauciBayesa( X,y,lambda )
%NAUCIBAYESA Nauci sve potrebne parametre za naivni Bayesov klasifikator iz
%danih podataka
%   X - znacajke primjera
%   y - oznake primjera
%   lambda - koristimo li ML-procjenitelj '0', ili Laplaceov procjenitelj '1'

%ukupan broj primjera
m=size(X,1);
%broj primjera y1 y2 y3
my=[sum(y==0) sum(y==1) sum(y==2)];

%prva tri parametra, P(y1), P(y2), P(y3)
Bayes_parametri = my/m;

%procjene vjerojatnosti za P(xk | Cj)
for k=1:4,      %idemo po svim znacajkama
    for i=0:2,      %idemo po svim vrijednostima znacajki
        pomocni_redak = [];
        for j=0:2,       %idemo po svim klasama
            pomocni_redak = [pomocni_redak (sum((y==j).*(X(:,k)==i)) + lambda)/(my(j+1)+lambda*3)];
        end
        Bayes_parametri = [Bayes_parametri; pomocni_redak];
    end
end


end

