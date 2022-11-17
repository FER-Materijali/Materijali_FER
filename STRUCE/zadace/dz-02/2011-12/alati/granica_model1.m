function [ output ] = granica_model1(  x, kov_matrica5, mi5, P5, kov_matrica6, mi6, P6)
%GRANICA_MODEL1 Za crtanje granice prvog modela

output = model1(x, kov_matrica5, mi5, P5) - model1( x, kov_matrica6, mi6, P6);

end

