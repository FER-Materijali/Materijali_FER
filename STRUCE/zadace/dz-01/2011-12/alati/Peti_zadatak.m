clc; 
url = 'http://archive.ics.uci.edu/ml/machine-learning-databases/auto-mpg/auto-mpg.data';
m = Ucitaj_podatke(url);
 
[mUcenje, mProvjera] = Podijeli_primjere(m);

% h1, ulazi: snaga i tezina
h1 = Nauci_hipotezu (mUcenje(:,[4,5]),mUcenje(:,1));
% h2, ulazi: snaga, tezina i ubrzanje
h2 = Nauci_hipotezu (mUcenje(:,[4,5,6]),mUcenje(:,1));
% h3, ulazi: broj cilindara, zapremina motora, snaga, tezina,ubrzanje i godina modela
h3 = Nauci_hipotezu (mUcenje(:,[2,3,4,5,6,7]),mUcenje(:,1));

[Eemp, Egen] = Racunaj_pogreske(h1,mUcenje(:,1), mProvjera(:,1),mUcenje(:,[4,5]),mProvjera(:,[4,5]));
fprintf('Empirijska pogreska od h1: %f\nPogreska generalizacije od h1: %f\n',Eemp,Egen);
[Eemp, Egen] = Racunaj_pogreske(h2,mUcenje(:,1), mProvjera(:,1),mUcenje(:,[4,5,6]),mProvjera(:,[4,5,6]));
fprintf('Empirijska pogreska od h2: %f\nPogreska generalizacije od h2: %f\n',Eemp,Egen);
[Eemp, Egen] = Racunaj_pogreske(h3,mUcenje(:,1), mProvjera(:,1),mUcenje(:,[2,3,4,5,6,7]),mProvjera(:,[2,3,4,5,6,7]));
fprintf('Empirijska pogreska od h3: %f\nPogreska generalizacije od h3: %f\n',Eemp,Egen);

[ameri, neameri] = Podijeli_amere(m);
h1a = Nauci_hipotezu (ameri(:,[4,5]),ameri(:,1));
h2a = Nauci_hipotezu (ameri(:,[4,5,6]),ameri(:,1));
h3a = Nauci_hipotezu (ameri(:,[2,3,4,5,6,7]),ameri(:,1));

disp(' ');
[Eemp, Egen] = Racunaj_pogreske(h1a,ameri(:,1), neameri(:,1),ameri(:,[4,5]),neameri(:,[4,5]));
fprintf('Empirijska pogreska od h1a: %f\nPogreska generalizacije od h1a: %f\n',Eemp,Egen);
[Eemp, Egen] = Racunaj_pogreske(h2a,ameri(:,1), neameri(:,1),ameri(:,[4,5,6]),neameri(:,[4,5,6]));
fprintf('Empirijska pogreska od h2a: %f\nPogreska generalizacije od h2a: %f\n',Eemp,Egen);
[Eemp, Egen] = Racunaj_pogreske(h3a,ameri(:,1), neameri(:,1),ameri(:,[2,3,4,5,6,7]),neameri(:,[2,3,4,5,6,7]));
fprintf('Empirijska pogreska od h3a: %f\nPogreska generalizacije od h3a: %f\n',Eemp,Egen);

h1kv = Nauci_hipotezu (Dodaj_kvadrate(mUcenje(:,[4,5])),mUcenje(:,1));
h2kv = Nauci_hipotezu (Dodaj_kvadrate(mUcenje(:,[4,5,6])),mUcenje(:,1));
h3kv = Nauci_hipotezu (Dodaj_kvadrate(mUcenje(:,[2,3,4,5,6,7])),mUcenje(:,1));

disp(' ');
[Eemp, Egen] = Racunaj_pogreske(h1kv,mUcenje(:,1), mProvjera(:,1),Dodaj_kvadrate(mUcenje(:,[4,5])),Dodaj_kvadrate(mProvjera(:,[4,5])));
fprintf('Empirijska pogreska od h1kv: %f\nPogreska generalizacije od h1kv: %f\n',Eemp,Egen);
[Eemp, Egen] = Racunaj_pogreske(h2kv,mUcenje(:,1), mProvjera(:,1),Dodaj_kvadrate(mUcenje(:,[4,5,6])),Dodaj_kvadrate(mProvjera(:,[4,5,6])));
fprintf('Empirijska pogreska od h2kv: %f\nPogreska generalizacije od h2kv: %f\n',Eemp,Egen);
[Eemp, Egen] = Racunaj_pogreske(h3kv,mUcenje(:,1), mProvjera(:,1),Dodaj_kvadrate(mUcenje(:,[2,3,4,5,6,7])),Dodaj_kvadrate(mProvjera(:,[2,3,4,5,6,7])));
fprintf('Empirijska pogreska od h3kv: %f\nPogreska generalizacije od h3kv: %f\n',Eemp,Egen);