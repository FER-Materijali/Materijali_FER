
% FILTER 1
f1=0;
f2=1470;
fs=44100;

N=32;

N2=floor(N/2);
w1=((2*pi)*f1)/fs;
w2=((2*pi)*f2)/fs;
i=0;
h1(i+1)=(1/pi)*(1/(N2-i))*(sin(w2*(N2-i))-(sin(w1*(N2-i))));
for i=1:1:(N2-1)
    h1(i+1)=(1/pi)*(1/(N2-i))*(sin(w2*(N2-i))-(sin(w1*(N2-i))));
end
for i=N2:N2:N2
    h1(i+1)=(1/pi)*(w2-w1);
end
for i=(N2+1):1:(N-1)
    h1(i+1)=(1/pi)*(1/(i-N2))*(sin(w2*(i-N2))-(sin(w1*(i-N2))));
end

figure;
freqz(h1);

% FILTER 2

f1=1470;
f2=4410;
fs=44100;



N2=floor(N/2);
w1=((2*pi)*f1)/fs;
w2=((2*pi)*f2)/fs;
i=0;
h2(i+1)=(1/pi)*(1/(N2-i))*(sin(w2*(N2-i))-(sin(w1*(N2-i))));
for i=1:1:(N2-1)
    h2(i+1)=(1/pi)*(1/(N2-i))*(sin(w2*(N2-i))-(sin(w1*(N2-i))));
end
for i=N2:N2:N2
    h2(i+1)=(1/pi)*(w2-w1);
end
for i=(N2+1):1:(N-1)
    h2(i+1)=(1/pi)*(1/(i-N2))*(sin(w2*(i-N2))-(sin(w1*(i-N2))));
end

figure;
freqz(h2);

% FILTER 3

f1=4410;
f2=10290;
fs=44100;



N2=floor(N/2);
w1=((2*pi)*f1)/fs;
w2=((2*pi)*f2)/fs;
i=0;
h3(i+1)=(1/pi)*(1/(N2-i))*(sin(w2*(N2-i))-(sin(w1*(N2-i))));
for i=1:1:(N2-1)
    h3(i+1)=(1/pi)*(1/(N2-i))*(sin(w2*(N2-i))-(sin(w1*(N2-i))));
end
for i=N2:N2:N2
    h3(i+1)=(1/pi)*(w2-w1);
end
for i=(N2+1):1:(N-1)
    h3(i+1)=(1/pi)*(1/(i-N2))*(sin(w2*(i-N2))-(sin(w1*(i-N2))));
end

figure;
freqz(h3);

%FILTAR 4

f1=10290;
f2=22050;
fs=44100;



N2=floor(N/2);
w1=((2*pi)*f1)/fs;
w2=((2*pi)*f2)/fs;
i=0;
h4(i+1)=(1/pi)*(1/(N2-i))*(sin(w2*(N2-i))-(sin(w1*(N2-i))));
for i=1:1:(N2-1)
    h4(i+1)=(1/pi)*(1/(N2-i))*(sin(w2*(N2-i))-(sin(w1*(N2-i))));
end
for i=N2:N2:N2
    h4(i+1)=(1/pi)*(w2-w1);
end
for i=(N2+1):1:(N-1)
    h4(i+1)=(1/pi)*(1/(i-N2))*(sin(w2*(i-N2))-(sin(w1*(i-N2))));
end

figure;
freqz(h4);

%---------------------------------
for i=1:1:N
    spoj(i)=h1(i)+h2(i)+h3(i)+h4(i);
end
figure;
freqz(spoj);

