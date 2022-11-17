D = [ -2, -1, 1, 3, 5, 7]
sig = 1
mi = 0

L = 1/(sqrt(2*pi)*sig) * exp(-(D-mi).^2/(2*sig^2));

L = prod(L)