function [kodna_rijec_crtica] = Kanal(kodna_rijec)

promjeni = 1 + randint(1, 1, length(kodna_rijec) - 1); %odabir jednog bita (na mjestu "promjeni")

kodna_rijec_crtica = kodna_rijec;

if (randint(1, 1, 2) == 1) kodna_rijec_crtica(1, promjeni) = mod(kodna_rijec(1, promjeni) + 1,2); %50:50 da ce se bit "promjeni" uistinu promjeniti
end