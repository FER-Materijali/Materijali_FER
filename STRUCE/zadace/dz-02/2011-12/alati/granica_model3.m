function [ output ] = granica_model3( x, sigma, mi5, P5, mi6, P6 )
%GRANICA_MODEL3 Za crtanje granice treceg modela


output = model3(x, sigma, mi5, P5) - model3( x, sigma, mi6, P6);


end

