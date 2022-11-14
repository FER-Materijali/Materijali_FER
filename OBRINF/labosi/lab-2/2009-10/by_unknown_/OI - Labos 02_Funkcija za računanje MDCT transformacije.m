function y = mdct(x, n)
% MDCT - Racunanje MDCT transformacije.
%   y = MDCT(x) racuna MDCT transformaciju signala x. Ako duljina signala
%   nije visekratnik broja dva signal ce biti prosiren nulama.
%
%   y = MDCT(x, n) skracuje ili prosiruje x na n uzoraka. MDCT
%   transformaciju racunamo uz N = n/2.

% OBRINF - Laboratorijske vjezbe - 27. 4. 2008.

% $Revizija: 1.0 $  $Datum: 2008/04/27 12:49:00 $
% $Autor(i): Tomislav Petkovic $

if nargin == 0,
	error('Signal mora biti zadan.');
end

if 1 == size(x, 1)
    x = x(:);
end

if 1 == nargin
    n = size(x, 1);
end

% Za racunanje MDCT-a duljina signala mora biti parna.
if 0 ~= mod(n, 2)
    warning('Duljina nije visekratnik broja dva!');
    n = n + 1;
end

% Prosiri ili skrati niz po potrebi.
m = size(x, 2);
if n > size(x, 1)
  X = zeros(n, m);
  X(1:size(x,1),:) = x;
else
  X = x(1:n, :);
end

% Izracunaj matricu MDCT transformacije.
N = n / 2;
n = repmat(0:2*N-1, N, 1);
k = repmat((0:N-1).', 1, 2*N);
MDCT = cos(pi/N*(n+1/2+N/2).*(k+1/2));

% Primijeni matircu na ulazni signal.
y = MDCT * X;
