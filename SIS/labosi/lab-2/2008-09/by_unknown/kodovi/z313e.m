t=[0:1/8000:1];
Z=x1+x2;
X=fft(Z);
A=abs(X);
N=length(X);
w=([1:N]-1)/N*8000;
plot(w, A);

