function [ h ] = model1( x, kov_matrica, mi, P )
%MODEL1 model s razlicitim kovarijacijskim matricama
%   x - primjeri, vektor redak, na kojem odredujemo iznos modela
%   kov_matrica - kovarijacijska matrica klase Cj
%   mi - srednja vrijednost klase Cj
%   P - apriorna vjerojatnost klase Cj

h = -0.5*log(det(kov_matrica)) - 0.5*(x-mi)*kov_matrica^-1*(x-mi)' + log(P);

end

