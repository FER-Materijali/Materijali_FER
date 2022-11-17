function [izglednost, best_coef, best_cent, best_sigm, iteracija] = em(D, K)

  N = size(D, 1);
  n = size(D, 2) - 1;

  % Pomiješamo primjere skupa.
  D = D(randperm(N),:);

  X = D(:,1:n);
  Y = D(:,n+1);

  % Koeficijenti mješavine su u početku svi isti.
  coef = ones(K, 1) / K;

  % Srednje vrijednosti su nasumični primjeri (zbog ranije permutacije).
  cent = X(1:K,:);

  % Početnu kovarijacijsku matricu procjenjujemo.
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

  for iteracija = 1:max_iteracija,

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

    if izglednost > 0,
      saw_pos = 1;
    endif

    if (saw_pos == 1) && (izglednost < stara_izglednost),
      fprintf("    * peaked\n\n");
      izglednost = stara_izglednost;
      break;
    else
      best_cent = cent;
      best_sigm = sigm;
      best_coef = coef;
      stara_izglednost = izglednost; % Onwards! To glory!
    endif
  end
end
