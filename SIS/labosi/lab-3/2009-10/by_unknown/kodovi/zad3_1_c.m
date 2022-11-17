 n = [1 1 1 1 1 1 1 1 1 1 1 1 1 ]; 
 [H, w] = freqz(n,1);
 H = H .* exp(j*w*0); 
subplot(211), plot(w, abs(H)); 
subplot(212), plot(w, phase(H));
