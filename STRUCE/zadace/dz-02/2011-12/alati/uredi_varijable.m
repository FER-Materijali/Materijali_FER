function [Data] = uredi_varijable(X)
%UREDI_VARIJABLE Diskretizira znacajke i permutira primjere
%   X - matrica znacajki + oznaka

Data = X;

%pomocna varijabla m - broj primjera
m = size(Data,1);

for i=1:4,
    Data = sortrows(Data, i);
    for j=1:m,
        if (j<=m/3)
            Data(j,i) = 0;
        elseif (j<=2*m/3)
                Data(j,i) = 1;
        else Data(j,i) = 2;
        end
    end
end

permutacije = randperm(m);
Data = Data(permutacije,:);

end

