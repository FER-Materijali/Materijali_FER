X = load('primjeri.txt');

# Uzimamo samo pet značajki.
X = X(:,[2 6 9 11 15]);

for k=2:8,
  [idsBest, csBest, bsBest, itersBest] = kmeans(X, k);
  iBest = 1;
  JBest = kriterijska(X, csBest, bsBest);
  fprintf("For i=1, J=%f.\n", JBest);

  fprintf("Did iter 1.\n");

  for i=2:10,
    [ids, cs, bs, iters] = kmeans(X, k);
    J = kriterijska(X, cs, bs);
    fprintf("For i=%d, J=%f.\n", i, J);
    if J < JBest,
      JBest = J;
      iBest = i;
      idsBest = ids;
      csBest = cs;
      bsBest = bs;
      itersBest = iters;
    endif

    fprintf("Did iter %d.\n", i);
  end

  fprintf("Za k=%d, greška je %f i broj iteracija %d.\n", k, JBest, itersBest);

  if k == 4,
    fprintf("Centroidi za k=4 spremljeni u datoteku.\n");
    save k4centroids.txt csBest;
  endif
end
