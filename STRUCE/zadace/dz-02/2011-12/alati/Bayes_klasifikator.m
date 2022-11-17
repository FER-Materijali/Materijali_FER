function [ y ] = Bayes_klasifikator( Bayes_parametri, X )
%BAYES_KLASIFIKATOR prima parametre naucene iz funkcije "NauciBayesa" i
%klasificira primjere X pomocu danih parametara
%   Bayes_parametri - parametri(vjerojatnosti) Bayesovog klasifikatora

m = size(X,1);
y = zeros(m,1);

for i=1:m,  %po primjerima
    max = [0 0];
    for j=0:2,  %po klasama
        vjerojatnost = Bayes_parametri(1,j+1)*Bayes_parametri(2+X(i,1),j+1)*Bayes_parametri(5+X(i,2),j+1)*Bayes_parametri(8+X(i,3),j+1)*Bayes_parametri(11+X(i,4),j+1);
        if (max(2) < vjerojatnost)
            max = [j vjerojatnost];
        end
    end
    y(i) = max(1);
end

end

