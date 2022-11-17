warning ("off", "Octave:broadcast");

D = load('ulaz-za-em.txt');

# Uzimamo samo pet značajki.
X = D(:,[2 6 9 11 15]);

n = size(D, 2)-1;
Y = D(:,n+1);
[X middles spans] = normaliziraj(X);
D = [X Y];

K = 4;
fprintf("Započinjem grupiranje za k = %d.\n\n", K);

N = size(D, 1);
n = size(D, 2) - 1;

D = D(randperm(N),:);
X = D(:,1:n);
Y = D(:,n+1);

% Učitavamo središta iz datoteke, od ranije.
load k4em.txt;
cent = b_cent;
%coef = b_coef;
%sigm = b_sigm;

% Ostale parametre procjenjujemo, kao i obično.
coef = ones(K, 1) / K;
sigm = zeros(n, n, K);
for k = 1:K,
  for i = 1:N,
    diff = X(i,:) - cent(k,:);
    diff = diff' * diff;
    sigm(:,:,k) += diff;
  end
  sigm(:,:,k) ./= N;
end

saw_pos = 0;
stara_izglednost = -1;

max_iteracija = 20;

for iteracija = 1:2,
  % E-KORAK:
  % Za svaki primjer i komponentu računamo odgovornost.
  h = zeros(N, K);

  for i = 1:N,
    for k = 1:K,
      summed = 0;
      for j = 1:K,
        summed += multigauss(X(i,:), cent(j,:), sigm(:,:,j)) * coef(j);
      end

      h(i,k) = multigauss(X(i,:), cent(k,:), sigm(:,:,k)) * coef(k) / summed;
    end
  end

  % M-KORAK:
  % Računamo procjene parametara temeljem trenutnih odgovornosti.
  h_summed = sum(h);
  sigm = zeros(n, n, K);

  for k = 1:K,
    % Procjena središta cent(k,:).
    cent(k,:) = sum(h(:,k).*X) / h_summed(k);

    % Procjena kov. matrice sigm(:,:,k).
    summation = zeros(n, n);
    for i = 1:N,
      diff = X(i,:) - cent(k,:);
      sigm(:,:,k) .+= (h(i,k) * (diff'*diff));
    end
    sigm(:,:,k) ./= h_summed(k);

    % Procjena koeficijenta mješavine coef(k).
    coef(k) = h_summed(k) / N;
  end

  izglednost = logizglednost(X, coef, cent, sigm);
  fprintf("    iter %d\tL = %f\n", iteracija, izglednost);

  stara_izglednost = izglednost;
end

prikazvj(h, Y)
