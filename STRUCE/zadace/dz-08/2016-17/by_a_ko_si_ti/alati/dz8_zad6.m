clear;clc
%6a
disp('6. a)')
mi = [5.483, -0.183, -0.733];
x = [9.5, -0.7, -2.8;
    8.8, -0.8, -3.2; 
    6.5, -0.2, -0.8; 
    2.3, 0.3, 1.2;
    2.2, 0, 0; 
    3.6,0.3,1.2];

N = length(x);
kov = zeros(3);
for i = 1:N
    kov = kov + 1/N * (x(i,:) - mi)'*(x(i,:)-mi);
end

disp('Procjena kovarijacijske matrice =')
disp(kov)


%6b
pause
disp('6. b)')
disp('Inverz procjene kovarijacijske matrice:')
disp(inv(kov))


%6c
pause
disp('6. c)')
primjer = [-2, 1];
x_c = x(:, 1:2); % odbacujemo x3
mi_c = mi(1:2);  % odbacujemo x3
kov_c = kov(1:2, 1:2);  % odbacujemo x3
n = length(mi_c); % n - broj znacajki (2 u ovom slucaju)

p_x = 1 / ((2*pi)^(n/2)* sqrt(det(kov_c))) * exp(-1/2 * (primjer-mi_c)*inv(kov_c)*(primjer-mi_c)');

disp('Gustoca vjerojatnosti:')
disp(p_x)






