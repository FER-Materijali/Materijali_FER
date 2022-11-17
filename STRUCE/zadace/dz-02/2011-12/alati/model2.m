function [ h ] = model2( x, kov_matrica, mi, P )
%MODEL2 model s dijeljenom kovarijacijskom matricom
%   x - primjeri, vektor redak, na kojem odredujemo iznos modela
%   kov_matrica - dijeljena kovarijacijska matrica
%   mi - srednja vrijednost klase Cj
%   P - apriorna vjerojatnost klase Cj

h = x * kov_matrica^-1 * mi' - 0.5 * mi * kov_matrica^-1 * mi' + log(P);

end

