t=[0:1/8000:1];
x1=sin(2*pi*800*t);
X=fft(x1);
A=abs(X);
N=length(X);
w=([1:N]-1)/N*8000;
plot(w, A);