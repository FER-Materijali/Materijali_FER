function [ids, cs, bs, zadnja_iteracija] = kmeans(X, K)

N = size(X, 1);
%y = zeros(N, 1);

% Neka su sva početna središta prvo jednaka srednjoj vrijednosti svih primjera.
cs = zeros(K, size(X, 2)) + ones(1, K)' * mean(X);

najmanji = min(X);
najveci = max(X);

% Modificiraj sva središta slučajnim vrijednostima iz jednakog raspona.
for i = 1:K, cs(i,:) += unifrnd(najmanji, najveci); end

%save k4starter.mat cs;

max_iteracija = 100; % Ne želimo previše iteracija.

ids = zeros(N, 1);

for i = 1:max_iteracija,
  bs = zeros(N, K); % Kojem je središtu dodijeljen koji primjer?
  for j = 1:N,
    diffs = zeros(K, 1);
    for k = 1:K, diffs(k,:) = sqrt((X(j,:) - cs(k,:)) * (X(j,:) - cs(k,:))'); end
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

%if zadnja_iteracija == 100,
%  fprintf("Algoritam zaustavljen nakon stote iteracije.\n");
%else
%  fprintf("Uzorci obilježeni nakon %d iteracija.\n", zadnja_iteracija);
%end

%fprintf("Pogreška grupiranja je %f.\n", kriterijska(X, cs, bs));

end
