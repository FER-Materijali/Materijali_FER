t = [0:1/8000:1]; 
 x = sin(2*pi*405*t); 
 X = fft(x); 
A = abs(X); 
 N = length(X); 
 w = ([1:N]-1)/N*100; 
 plot(w, A)

