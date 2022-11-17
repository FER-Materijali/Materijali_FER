 function y=x1(t)
 for i = 1 : numel(t)
 % Vrijednost funkcije je nula za sve zadane t.
 y(i) = 0;
 % Osim na dva intervala, prvom [0,1] i drugom [3,4].
 if (0 <= t(i)) & (t(i) <= 1)
 y(i) = 1;
 end
 if (3 <= t(i)) & (t(i) <= 4)
 y(i) = 1;
 end
 end