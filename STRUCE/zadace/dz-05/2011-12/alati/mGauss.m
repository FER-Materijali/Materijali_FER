function [ p_x ] = mGauss( x, MI, SIGMA )


p_x = exp(-0.5*(x-MI)*inv(SIGMA)*(x-MI)')/((2*pi)*sqrt(det(SIGMA)));

end

