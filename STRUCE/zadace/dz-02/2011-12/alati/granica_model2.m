function [ output ] = granica_model2(  x, dijeljena_matrica, mi5, P5, mi6, P6 )
%GRANICA_MODEL2 Za crtanje granice drugog modela

output = model2(x, dijeljena_matrica, mi5, P5) - model2( x, dijeljena_matrica, mi6, P6);

end

