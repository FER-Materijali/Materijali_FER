function y = dtmfdecode(x)
% DTMFDECODE - Dekodira DTMF signal otipkan frekvencijom 8000Hz.
%   y = DTMFDECODE(x) vraæa znakovni niz koji sadri dekodirane znakove za
%   ulazni zvuèni signal x za svaki nepreklapajuæi blok duljine 205
%   uzoraka. Signal x mora biti otipkan frekvencijom od 8000Hz.

% OBRINF - Laboratorijske vjezbe - 24. 4. 2008.

% $Revizija: 1.0 $  $Datum: 2008/04/24 16:39:00 $
% $Autor(i): Tomislav Petkovic $

% Signal mora biti zadan.
error(nargchk(1,1,nargin));

% Obradu radimo u preklapajuæim blokovima duljine 205 uzoraka.
n = numel(x);
step = 205;
m = floor(n / 205 - 1);

% Zanimaju nas frekvencije samo za 8 èlanova spektra.
k = [18 20 22 24 31 34 38 42] + 1;

% Za svaki blok odredi spketar i pripadni znak.
y = [];
limit = 8100;
for i = 0 : m
    blok = x([1:205] + i * 205);

    spektar = fft(blok);
    val = abs(spektar(k));

    if val(1) * val(5) > limit
        y = [y '1'];
    elseif val(1) * val(6) > limit
        y = [y '2'];
    elseif val(1) * val(7) > limit
        y = [y '3'];
    elseif val(1) * val(8) > limit
        y = [y 'A'];
    elseif val(2) * val(5) > limit
        y = [y '4'];
    elseif val(2) * val(6) > limit
        y = [y '5'];
    elseif val(2) * val(7) > limit
        y = [y '6'];
    elseif val(2) * val(8) > limit
        y = [y 'B'];
    elseif val(3) * val(5) > limit
        y = [y '7'];
    elseif val(3) * val(6) > limit
        y = [y '8'];
    elseif val(3) * val(7) > limit
        y = [y '9'];
    elseif val(3) * val(8) > limit
        y = [y 'C'];
    elseif val(4) * val(5) > limit
        y = [y '*'];
    elseif val(4) * val(6) > limit
        y = [y '0'];
    elseif val(4) * val(7) > limit
        y = [y '#'];
    elseif val(4) * val(8) > limit
        y = [y 'D'];
    else
        y = [y ' '];
    end
end