function J = kriterijska(X, cs, bs)

N = size(X, 1);
K = size(bs, 2);

J = 0;

for i = 1:N,
  for k = 1:K,
    J += bs(i, k) * ((X(i,:) - cs(k,:)) * (X(i,:) - cs(k,:))');
  end
end

end
