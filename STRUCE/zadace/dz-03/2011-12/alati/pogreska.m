function [J, grad] = pogreska(w, X, y, lambda)

X = [ones(size(X,1),1) X];

%funkcija pogreske
J = -y'*log(sigmoid(X*w)) - (1-y')*log(1-sigmoid(X*w));
J = J + lambda*(w'*w-w(1)^2)/2;

%gradijent funkcije pogreske
grad = X' * (sigmoid(X*w) - y) + lambda*w;
grad(1) = grad(1) - lambda*w(1);


end
