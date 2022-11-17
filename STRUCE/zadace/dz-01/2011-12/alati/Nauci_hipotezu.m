function [ k ] = Nauci_model( m, y )

% izracunaj koeficijente linearne regresije
k = regress(y, [ones(size(m,1),1) m]);

end

