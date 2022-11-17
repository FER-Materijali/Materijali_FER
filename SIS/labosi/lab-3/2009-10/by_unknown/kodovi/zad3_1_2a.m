n=[1 1 1 ]; 
pomak=1; 
[H,w]=freqz(n,1,[-5*pi:0.1:5*pi]);
H=H.*exp(-j*w*pomak);
plot(w,abs(H)+abs(H));
H=abs(H).*abs(H)
E=sum(H)