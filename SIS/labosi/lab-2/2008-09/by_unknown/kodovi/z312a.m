n=[1 1 1 1 1 1 1 1 1 1];
[H,w]=freqz(n,1,[-5*pi:0.1:5*pi]);
H=H.*exp(-j*w*0);
H=(abs(H).^2);
plot(w, H);
