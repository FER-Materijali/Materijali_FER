function y = z331a(g,a,b)
% z331a - 
% poziv funkcije :---> z331a(N,X)
%Za zadani N i signal x raèuna koeficijente rastava X{i} i
% rekonstrukciju y

error(nargchk(3,3,nargin));


N=a;

x=b;

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
y = zeros(numel(X{1}(:,1))*N, 1);
for i = 1 : g
    y=y+filter(F{i},1,upsample(X{i},N));
end
