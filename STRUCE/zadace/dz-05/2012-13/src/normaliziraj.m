function [X, middles, spans] = normaliziraj(X)
  N = size(X, 1);
  n = size(X, 2);

  middles = zeros(n, 1);
  spans = zeros(n, 1);

  for j = 1:n,
    smallest = min(X(:,j));
    largest = max(X(:,j));
    spans(j) = (largest - smallest)/2;
    middles(j) = sum(X(:,j))/N;
    X(:,j) -= middles(j);
    X(:,j) /= spans(j);
    fprintf("Normalizing feature %d: (feat-%f)/%f.\n", j, middles(j), spans(j));
  end
end
