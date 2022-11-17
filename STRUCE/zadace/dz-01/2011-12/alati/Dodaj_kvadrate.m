function [ M ] = Dodaj_kvadrate( m )

N = size(m,2);
M = m;

for i = 1:N,
    for j = i:N
        M = [M m(:,i).*m(:,j)];
    end
end

end

