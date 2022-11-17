function [izlaz] = Hamm_dekoder(kodna_rijec_crtica)
%kodna_rijec_crtica je duljine 7
c1_izracun = mod (kodna_rijec_crtica(1,1) + kodna_rijec_crtica(1,3) + kodna_rijec_crtica(1,5) + kodna_rijec_crtica(1,7), 2);
c2_izracun = mod (kodna_rijec_crtica(1,2) + kodna_rijec_crtica(1,3) + kodna_rijec_crtica(1,6) + kodna_rijec_crtica(1,7), 2);
c3_izracun = mod (kodna_rijec_crtica(1,4) + kodna_rijec_crtica(1,5) + kodna_rijec_crtica(1,6) + kodna_rijec_crtica(1,7), 2);

promjenjen = c3_izracun*4 + c2_izracun*2 + c1_izracun; %buduci da je mozda promjenjen jedan bit, izracuna se na kojem mjestu je promjenjen

kodna_rijec = kodna_rijec_crtica;

if (promjenjen > 0) %ako je promjenjen jedan bit, "promjenjen" ce biti veci od 0
   kodna_rijec(1, promjenjen) = mod(kodna_rijec(1, promjenjen) + 1, 2);
end

izlaz = [kodna_rijec(1,3), kodna_rijec(1,5), kodna_rijec(1,6), kodna_rijec(1,7)];