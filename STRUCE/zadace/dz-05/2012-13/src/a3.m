X = load('primjeri.txt');

# Uzimamo samo pet značajki.
X = X(:,[2 6 9 11 15]);
N = size(X, 1);

K = 4;
load k4centroids.mat;

max_iteracija = 100; % Ne želimo previše iteracija.

ids = zeros(N, 1);

for i = 1:max_iteracija,
  bs = zeros(N, K); % Kojem je središtu dodijeljen koji primjer?
  for j = 1:N,
    diffs = zeros(K, 1);

    for k = 1:K,
      diffs(k,:) = sqrt((X(j,:) - cs(k,:)) * (X(j,:) - cs(k,:))');
    end

    [donotwant, ind] = min(diffs);
    bs(j, ind) = 1;
    ids(j) = ind;
  end

  % Mičemo središta na nove vrijednosti.
  cs_new = cs;
  for k = 1:K,
    pripadajucih = sum(bs(:,k));
    if pripadajucih != 0,
      cs_new(k,:) = (bs(:,k)' * X) ./ pripadajucih;
    end
  end

  % Ako se središta nisu promijenila, zaustavljamo algoritam.
  if cs_new == cs
     break;
  end

  % Radimo s novim središtima.
  cs = cs_new;
  zadnja_iteracija = i;

  fprintf("  inner_i=%d, J=%f\n", i, kriterijska(X, cs, bs));
end

ids
