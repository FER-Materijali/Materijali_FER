

x=wavread ('samogl.wav');

N=32;

n = 0 : 2*N - 1;
w = sin(pi/2*sin(pi/2/N*(n + 1/2)).^2);

% Impulsni odzivi analizirajuæih filtara su spremljeni u H{i}
C = mdct(eye(2*N));
for i = 1 : N
H{i} = w .* C(i,2*N:-1:1);
end

% Impulsni odzivi rekonstrukcijskih filtara su spremljeni u F{i}
IC = imdct(eye(N));
for i = 1 : N
F{i} = 2 * w.' .* IC(:,i);
end

% Analizirajuæi dio DCT sloga.
for i = 1 : N
X{i} = downsample(filter(H{i}, 1, x), N, N-1);
end

% Rekonstrukcijski dio DCT sloga.
y3 = zeros(numel(X{1})*N, 1);
for i = 1 : N
y3=y3 + filter(F{i},1,upsample(X{i},N));
end

y4 = zeros(numel(X{1})*N, 1);
for i = 1 : 5
y4=y4 + filter(F{i},1,upsample(X{i},N));
end


