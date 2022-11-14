function y = imdct(x, n)
% IMDCT - Racunanje inverzne MDCT transformacije.
%   y = IMDCT(x) racuna IMDCT transformaciju signala x.
%
%   y = IMDCT(x, n) skracuje ili prosiruje x na n uzoraka. IMDCT
%   transformaciju racunamo uz N = n.

% OBRINF - Laboratorijske vjezbe - 27. 4. 2008.

% $Revizija: 1.0 $  $Datum: 2008/04/27 12:59:00 $
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

% Proširi ili skrati niz po potrebi.
m = size(x, 2);
if n > size(x, 1)
  X = zeros(n, m);
  X(1:size(x,1),:) = x;
else
  X = x(1:n, :);
end

% Izracunaj matricu IMDCT transformacije.
N = n;
k = repmat(0:N-1, 2*N, 1);
n = repmat((0:2*N-1)', 1, N);
IMDCT = 1/N*cos(pi/N*(n+1/2+N/2).*(k+1/2));

% Primijeni matircu na ulazni signal.
y = IMDCT * X;
