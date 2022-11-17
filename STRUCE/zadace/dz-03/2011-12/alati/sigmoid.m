function g = sigmoid(z)

%sigmoidalna funkcija od z
g = (1+exp(-z)).^-1;

end