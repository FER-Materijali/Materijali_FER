function prikazvj(H, Y)
  v = zeros(size(Y));
  N = size(Y);
  K = size(H, 2);

  for k = 1:K,
    fprintf("Grupa %d:\n", k-1);
    disp(-sortrows(-[H(:,k) Y]));
  end
end
