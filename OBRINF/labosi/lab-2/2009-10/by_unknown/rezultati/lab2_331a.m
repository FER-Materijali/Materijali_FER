
N=32;
x=wavread('samogl.wav');


% Impulsni odzivi analizirajuæih filtara su spremljeni u H{i}
C = dct(eye(N));

for i = 1 : N
H{i} = C(i, N:-1:1);
end

% Impulsni odzivi rekonstrukcijskih filtara su spremljeni u F{i}
CT = idct(eye(N));


for i = 1 : N
F{i} = CT(:, i);
end

% Analizirajuæi dio DCT sloga.
for i = 1 : N
X{i} = downsample(filter(H{i}, 1, x), N, N-1);
end

% Rekonstrukcijski dio DCT sloga.
y1 = zeros(numel(X{1})*N, 1);
for i = 1 : N
y1 =y1 + filter(F{i},1,upsample(X{i},N));
end


y2 = zeros(numel(X{1})*N, 1);
for i = 1 : 5
y2 =y2 + filter(F{i},1,upsample(X{i},N));
end
