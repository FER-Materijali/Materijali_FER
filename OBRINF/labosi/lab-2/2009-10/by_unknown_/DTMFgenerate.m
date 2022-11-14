function y = DTMFgenerate(x)
% DTMFCODE - Generiranje DTMF signal za zadani znak.
%   y = DTMFCODE(x) generira DTMF signal duljine 640 uzoraka otipkan
%   frekvencijom 8000 Hz za ulazni simbol x.
%
%   y = DTMFCODE(x, fs, N) generira DTMF signal temeljem znakovnog
%   niza x otipkan frekvencijom fs gdje je svaki znak iz x
%   zamijenjen DTMF tonom trajanja N uzoraka.

% OBRINF - Laboratorijske vjezbe - 24. 4. 2008.

% $Revizija: 1.0 $  $Datum: 2008/04/24 16:39:00 $
% $Autor(i): Tomislav Petkovic $

% Znak mora biti zadan.
error(nargchk(1,3,nargin));

if 1 == nargin
    fs = 8000;
    N = 640;
elseif 2 == nargin
    N = 80E-3 / fs;
end

% Raèunamo DTMF ton u trenutcima t.
N = ceil(N);
t = [0:N-1] / fs;

% Svaki znak se predstavlja kao linearna kombinacija dvije frekvencije.
fa1 = 697;
fa2 = 770;
fa3 = 852;
fa4 = 941;

fb1 = 1209;
fb2 = 1336;
fb3 = 1477;
fb4 = 1633;

y = [];
for i = 1 : numel(x);
    if ischar(x(i))
        switch x(i)
            case {'1'}
                f1 = fa1; f2 = fb1;
            case {'2'}
                f1 = fa1; f2 = fb2;
            case {'3'}
                f1 = fa1; f2 = fb3;
            case {'a', 'A'}
                f1 = fa1; f2 = fb4;

            case {'4'}
                f1 = fa2; f2 = fb1;
            case {'5'}
                f1 = fa2; f2 = fb2;
            case {'6'}
                f1 = fa2; f2 = fb3;
            case {'b', 'B'}
                f1 = fa2; f2 = fb4;

            case {'7'}
                f1 = fa3; f2 = fb1;
            case {'8'}
                f1 = fa3; f2 = fb2;
            case {'9'}
                f1 = fa3; f2 = fb3;
            case {'c', 'C'}
                f1 = fa3; f2 = fb4;

            case {'*'}
                f1 = fa4; f2 = fb1;
            case {'0'}
                f1 = fa4; f2 = fb2;
            case {'#'}
                f1 = fa4; f2 = fb3;
            case {'d', 'D'}
                f1 = fa4; f2 = fb4;

            otherwise
                f1 = 0; f2 = 0;
        end
        
        % Izraèunaj i vrati DTMF signal.
        y = [y  sin(2*pi*t*f1) + sin(2*pi*t*f2)];
    else
        error('Ulazni argument mora biti znakovni niz!');
    end
end
