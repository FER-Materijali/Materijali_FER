function [y] = z332a(g,a,b)
% z332a - 
% poziv funkcije :---> z3312(N,X)
%Za zadani N i signal x raèuna koeficijente rastava X{i} i
% rekonstrukciju y

error(nargchk(3,3,nargin));

N=a;
x=b;


% Prvo raèunamo vremenski otvor w koji se koristi za Vorbis.
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
y = zeros(numel(X{1}(:,1))*N, 1);
for i = 1 : g
    y=y + filter(F{i},1,upsample(X{i},N));
end
