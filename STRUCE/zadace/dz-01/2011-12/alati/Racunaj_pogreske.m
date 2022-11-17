function [ Eemp,  Egen] = Racunaj_pogreske( h, yU, yP, mUcenje, mProvjera)

N=size(mUcenje,1);
M=size(mProvjera,1);
X=[ones(N,1) mUcenje];
Y=[ones(M,1) mProvjera];
Eemp = transpose(X*h - yU)*(X*h - yU)/(2*N);
%Eemp = sum((X*h - y(1:N)).^2)/(2*N);
Egen = transpose(Y*h - yP)*(Y*h - yP)/(2*M);
%Egen = sum((Y*h - y(N+1:end)).^2)/(2*M);

end

