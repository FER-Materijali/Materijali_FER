function [ h ] = model3( x, sigma, mi, P )
%MODEL3 model s dijeljenom izotropnom kovarijacijskom matricom
%   x - primjeri, vektor redak, na kojem odredujemo iznos modela
%   sigma - prosjecna varijanca svih varijabli
%   mi - srednja vrijednost klase Cj
%   P - apriorna vjerojatnost klase Cj

h = -1/(2*sigma)*(x-mi)*(x-mi)' + log(P);

end
