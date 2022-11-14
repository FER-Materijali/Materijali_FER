function Z = imfeat2(slika, blok, znacajka);
% IMFEAT2 - Odreduje znacajke slike. 
%   Z = IMFEAT2(I, [M N], znacajka) odreduje zadanu znacajku
%   slike I na blokovima velicine M sa N. Znacajka moze biti
%     'mean' za aritmeticku sredinu bloka MxN
%     'stddev' za standardnu devijaciju bloka MxN
%     'min' za minimum bloka MxN
%     'max' za maksimum bloka MxN
%     'entropy' za entropiju bloka MxN
%     'energy' za energiju bloka MxN
%
%   Rezultat je matrica u kojoj pojedini element odgovara
%   trazenoj znacajki bloka velicine M sa N u ulaznoj slici.

% DOSl - Laboratorijske vjezbe - 18. 2. 2004.

% $Revizija: 1.0 $  $Datum: 2004/02/18 13:43:31 $
% $Autor(i): Tomislav Petkovic $

if 3 ~= nargin
   error('Svi parametri moraju biti zadani.');	
end

% provjeri zadanu znacajku
switch znacajka
case 'min'
   btip = 1;
case 'max'
   btip = 2;
case 'mean'
   btip = 3;
case 'stddev'
   btip = 4;
case 'entropy'
   btip = 5;
case 'energy'
   btip = 6;
otherwise
   error(['Znacajke su ''min'', ''max'',''mean'',''stddev'','...
      ' ''entropy'' ili ''energy''']);
end

% odredi velicinu bloka i inicijaliziraj izlaznu matricu znacajki
m = blok(1);
n = blok(2);
[maxx, maxy] = size(slika);
Z = zeros(maxx-m, maxy-n);

% procesiranje po blokovima izravnom metodom pomocu for petlji
% u MATALB-u je izrazito sporo, stoga za jednostavne statisticke
% znacajke kopiramo zadane blokove ulazne slike u novu matricu u
% kojoj je svaki takav blok preslikan u jedan stupac
% takva metoda moze biti memorijski dosta zahtjevnija, ali je
% takoder i visestruko brza
% za racunanje energije i entropije potreban nam je histogram
% prvog reda te opet mozemo preslikati blokove u stupce, no
% prije toga skaliramo sliku na interval [0,1]
if btip < 3
   % za maksimum i minimum tip moze ostati uint8
   pomocna = im2col(slika, [m n], 'sliding');
elseif btip < 5
   % za srednju vrijednsot i varijancu moramo imati dobule tip
   pomocna = im2col(double(slika), [m n], 'sliding');      
else
   % za energiju i entropiju nam treba double tip, no jos cemo
   % izvrsiti skaliranje na interval [0,1]
   pomocna = im2col(imscale(slika,[0 1]), [m n], 'sliding');
end

switch btip
case 1
   Z = reshape(min(pomocna), maxx-m+1, maxy-n+1);
case 2
   Z = reshape(max(pomocna), maxx-m+1, maxy-n+1);
case 3
   Z = reshape(mean(pomocna), maxx-m+1, maxy-n+1);
case 4
   Z = reshape(std(pomocna), maxx-m+1, maxy-n+1);
case 5
   % entropija je estimacija ocekivanja negativnog
   % logaritma po bazi 2 histograma prvog reda p
   % odlucili smo se za 16 razreda u histogramu
   p = hist(pomocna, 16);
   p = p / (m*n);
   pomocna = p;
   pomocna(find(0 == p)) = 1;
   Z = reshape(-sum(p.*log2(pomocna)), maxx-m+1, maxy-n+1);
case 6
   % racunamo kvadrat histograma
   % odlucili smo se za 16 razreda u histogramu   
   p = hist(pomocna, 16);
   p = sum(p.*p) / (m*m*n*n);
   Z = reshape(p, maxx-m+1, maxy-n+1);
end
