n=[1 1 1 1 1];
[H,w]=freqz(n,1,[-5*pi:0.1:5*pi]);
H=H.*exp(-j*w*2);
subplot(211), plot(w,abs(H)), title('amplitudni dio');
subplot(212), plot(w,phase(H)), title('fazni dio');