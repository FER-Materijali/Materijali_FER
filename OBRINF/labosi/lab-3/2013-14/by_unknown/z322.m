x = wavread('samo.wav');

N = 32;

n = 0 : 2*N - 1;
w1 = 1/sqrt(2);
w2 = sin((2*n+1)*pi/(4*N));
w3 = sin(pi/2*sin(pi/2/N*(n+1/2)).^2);

C = mdct(eye(2*N));

for i = 1 : N
    H{i} = w1 .* C(i,2*N:-1:1);
end

IC = imdct(eye(N));

for i = 1 : N
    F{i} = 2 * w1.' .* IC(:,i);
end

for i = 1 : N
    X{i} = downsample(filter(H{i}, 1, x), N, N-1);
end

for j = 4:4:N
    y = zeros(numel(X{1})*N, 1);
    for i = 1 : j
        y = y + filter(F{i}, 1, upsample(X{i}, N));
    end

    Psig = 0;
    Psum = 0;

    for i = 1 : (length(y)-40)
        Psig = Psig + x(i)^2;
        Psum = Psum + (y(i+32)-x(i))^2;
    end

    SNR(j/4) = Psig/Psum;
end;

k = [4 8 12 16 20 24 28 32];
plot(k, SNR);
soundsc(y);