function [kodna_rijec] = Hamm_koder(poruka)
%poruka je duljine 4
%kodna_rijec je duljine 7
c1 = mod (poruka(1,1) + poruka(1,2) + poruka(1,4), 2);
c2 = mod (poruka(1,1) + poruka(1,3) + poruka(1,4), 2);
c3 = mod (poruka(1,2) + poruka(1,3) + poruka(1,4), 2);

kodna_rijec = [c1, c2, poruka(1,1), c3, poruka(1,2), poruka(1,3), poruka(1,4)];
