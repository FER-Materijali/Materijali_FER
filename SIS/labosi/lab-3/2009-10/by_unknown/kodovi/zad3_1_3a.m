t = [0:1/8000:1]; 
 x = sin(2*pi*400*t); 
 X = fft(x); 
 plot(abs(X)) 
