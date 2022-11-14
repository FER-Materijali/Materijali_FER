N=32;
A=1;

fa=1470;
fb=4410;
fc=10290;
fd=22050;
fs=44100;

fan=2*fa/fs;
fbn=2*fb/fs;
fcn=2*fc/fs;
fdn=2*fd/fs;

Ya=firls(N, [0 fan fan 1], [A A 0 0]);
Yb=firls(N, [0 fan fan fbn fbn 1], [0 0 A A 0 0]);
Yc=firls(N, [0 fbn fbn fcn fcn 1], [0 0 A A 0 0]);
Yd=firls(N, [0 fcn fcn fdn], [0 0 A A]);

figure;
freqz(Ya);
figure;
freqz(Yb);
figure;
freqz(Yc);
figure;
freqz(Yd);
figure;
freqz(Ya+Yb+Yc+Yd);
