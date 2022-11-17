t=[0:1/8000:1];
x2=sin(2*pi*805*t);
X=fft(x2);
A=abs(X);
N=length(X);
w=([1:N]-1)/N*8000;
plot(w, A);