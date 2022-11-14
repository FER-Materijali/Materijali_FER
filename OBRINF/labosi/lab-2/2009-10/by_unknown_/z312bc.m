broj=dtmfcode('1 2 3 4 5 6 7 8 9 0 * #');
N=128;
fs=8000;
figure;
specgram(broj,N,fs,rectwin(N));
title('Spektrogram 128 uzoraka');

N=205;
fs=8000;
figure;
specgram(broj,N,fs,rectwin(N));
title('Spektrogram 205 uzoraka');


N=256;
fs=8000;
figure;
specgram(broj,N,fs,rectwin(N));
title('Spektrogram 256 uzoraka');

N=512;
fs=8000;
figure;
specgram(broj,N,fs,rectwin(N));
title('Spektrogram 512 uzoraka');

N=1024;
fs=8000;
figure;
specgram(broj,N,fs,rectwin(N));
title('Spektrogram 1024 uzoraka');
