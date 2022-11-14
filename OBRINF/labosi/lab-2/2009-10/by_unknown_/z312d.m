broj=dtmfcode('1 2 3 4 5 6 7 8 9 0 * #');

N=128;
fs=8000;
figure;
specgram(broj,N,fs,blackman(N));
title('Spektrogram 128 uzoraka');

A=205;
fs=8000;
figure;
specgram(broj,A,fs,blackman(A));
title('Spektrogram 205 uzoraka');

B=256;
fs=8000;
figure;
specgram(broj,B,fs,blackman(B));
title('Spektrogram 256 uzoraka');

C=512;
fs=8000;
figure;
specgram(broj,C,fs,blackman(C));
title('Spektrogram 512 uzoraka');

D=1024;
fs=8000;
figure;
specgram(broj,D,fs,blackman(D));
title('Spektrogram 1024 uzoraka');
