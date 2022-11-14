x = wavread('samo.wav');

N = 32;

C = dct(eye(N));
for i = 1 : N
    H{i} = C(i, N:-1:1);
end

CT = idct(eye(N));
for i = 1 : N
    F{i} = CT(:, i);
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

    for i = 1 : length(y)
        Psig = Psig + x(i)^2;
        Psum = Psum + (y(i)-x(i))^2;
    end

    SNR(j/4) = Psig/Psum;
end;

k = [4 8 12 16 20 24 28 32];
plot(k, SNR);
soundsc(y);