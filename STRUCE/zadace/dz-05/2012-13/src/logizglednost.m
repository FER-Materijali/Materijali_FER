function L = logizglednost(X, coef, cent, sigm)
  N = size(X, 1);
  K = size(coef);

  L = 0;
  for i = 1:N,
    inner_sum = 0; % ARGH prenewbie sam za divnu matričnu formu. Onwards!
    for k = 1:K,
      inner_sum += coef(k) * multigauss(X(i,:), cent(k), sigm(:,:,k));
    end
    L += log(inner_sum);
  end
end
