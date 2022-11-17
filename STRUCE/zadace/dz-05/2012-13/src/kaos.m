warning ("off", "Octave:broadcast");

D = load('ulaz-za-em.txt');

# Uzimamo samo pet značajki.
X = D(:,[2 6 9 11 15]);

n = size(D, 2)-1;
Y = D(:,n+1);
[X middles spans] = normaliziraj(X);
D = [X Y];

for k = 4:4,
  fprintf("Započinjem grupiranje za k = %d.\n\n", k);

  % Prvo ponavljanje automatski je i najbolje, for now.
  [b_L, b_coef, b_cent, b_sigm, b_iter] = em(D, k);

  for ponavljanje = 2:10,
    [L, coef, cent, sigm, iter] = em(D, k);
    if L > b_L,
      save last_best.mat b_L b_coef b_cent b_sigm b_iter;
      b_L = L;
      b_coef = coef;
      b_cent = cent;
      b_sigm = sigm;
      b_iter = iter;
    endif
  end

  fprintf("Grupiranje za k = %d gotovo!\n", k);
  fprintf("* iteracija = %d, L = %f\n\n", b_iter, b_L);

  if k == 4,
    save k4em.txt b_coef b_cent b_sigm;
    fprintf("Zapisao središta za K=4 u datoteku k4em.txt.\n");
  endif
end
