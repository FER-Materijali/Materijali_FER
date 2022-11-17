% Ucitaj podatke u jedan string.
url = 'file:///Users/kreso/Dropbox/FER/SU/dz1/zad5/input.txt'; % prebacio sam u lokalni fajl radi brzine
tekst_podatci = urlread(url);
tmp = textscan(tekst_podatci,'%f %f %f %f %f %f %f %f %*q','TreatAsEmpty','?', ...
'CollectOutput',1); % Trazena matrica
m = tmp{1};
redak_ima_nan = isnan(m(:,4));
m(redak_ima_nan,4) = mean(m(~redak_ima_nan,4));
%disp(m) %debug

X = m;
% podjeli skup primjera na 2 skupa
[m, n] = size(X);
A = [];
mpgA = [];
for i=1:249
     index = random('unid', m);
     A(i,:) = X(index,:);
     X(index,:) = []; % izbrisi red
     m = m-1; 
end
mpgX = X(:,1);
mpgA = A(:,1);


% prosirujemo X sa jedinicama zbog x0 parametra hiperravnine
X = [ones(size(X,1),1) X];
A = [ones(size(A,1),1) A];
S1 = A(:,[1,5,6]); % varijable snaga, tezina, indeksi pomaknuti za 1 zbog ones-a
S2 = A(:,[1,5,6,7]); % varijable snaga, tezina, akceleracija
S3 = A(:,[1,3,4,5,6,7,8]); % varijable sve osim proizvo?a?a
X1 = X(:,[1,5,6]); % testni skupovi
X2 = X(:,[1,5,6,7]);
X3 = X(:,[1,3,4,5,6,7,8]);

% izracunaj koeficijente linearne regresije
k1 = regress(mpgA, S1);
k2 = regress(mpgA, S2);
k3 = regress(mpgA, S3);
% predvidanje modela:
r1 = S1 * k1;
r2 = S2 * k2;
r3 = S3 * k3;
test1 = X1 * k1;
test2 = X2 * k2;
test3 = X3 * k3;

[size_mpgA size2] = size(mpgA);
[size_mpg size3] = size(mpg);
[sum(abs(   r1-mpgA).*abs(   r1-mpgA))/(2*size_mpgA) % empirijska pogreska h1
 sum(abs(test1-mpg ).*abs(test1-mpg ))/(2*size_mpg )] % pogreska generalizacije h1

[sum(abs(   r2-mpgA).*abs(   r2-mpgA))/(2*size_mpgA) % empirijska pogreska h2
 sum(abs(test2-mpg ).*abs(test2-mpg ))/(2*size_mpg )] % pogreska generalizacije h2

[sum(abs(   r3-mpgA).*abs(   r3-mpgA))/(2*size_mpgA) % empirijska pogreska h3
 sum(abs(test3-mpg ).*abs(test3-mpg ))/(2*size_mpg )] % pogreska generalizacije h3

%% vizualiziraj
%subplot(2,1,1);
%plot(mpgA);
%subplot(2,1,2);
%plot(r1)
