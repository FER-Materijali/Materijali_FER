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
mpg = X(:,1);
mpgA = A(:,1);


% prosirujemo X sa jedinicama zbog x0 parametra hiperravnine
X = [ones(size(X,1),1) X];
A = [ones(size(A,1),1) A];
S3 = A(:,[1,3,4,5,6,7,8]); % varijable sve osim proizvo?a?a
X3 = X(:,[1,3,4,5,6,7,8]);
k3 = regress(mpgA, S3);

mpgC = [mpgA
        mpg];
    
C = [S3
     X3];
r3 = C * k3;

sortrows([abs(r3-mpgC).*abs(r3-mpgC) C],1)

