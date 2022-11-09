function [ ] = ispis( matrica, dimenzija)
%napravite praznu matricu u wordu i u desnom djelu okvira
%je crni trokut, kliknite i odaberite linear, zatim unutar
%oblih zagrada zamjenite ono što je upisano (&-ovi i @-ovi)
%sa retkom koji ispiše ovaj kod
fprintf('Kopirajte red ispod u Word matricu \n')
M=matrica;
dim=dimenzija;
format short;
R=real(M);
I=imag(M);
for i=1:dim;
    for j=1:dim;
        format short;
        if R(i,j)<0
            fprintf('-')
        end
        fprintf(1, '%.6g', abs(R(i,j)))
        if I(i,j)~=0
        if I(i,j)<0
            fprintf('-')            
        end
        if I(i,j)>0
            fprintf('+')
        end
        fprintf(1, '%.6gi', abs(I(i,j)))
        end
        if j~=dim        
       fprintf('&')
       end
    end
    if i~=dim
    fprintf('@')
    end
end
fprintf('\n')
end

