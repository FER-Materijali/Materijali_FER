m=[ -1.28 -1.51 -1.65 -2.29
    -1.83 -0.99 -2.51 -0.72
     3.24  0.11  2.15 -1.67
    -2.47 -1.95 -0.65 -2.61
    -1.07  0.15 -0.40 -2.31
    -1.58  0.06  0.26 -0.55
    -1.00 -0.95 -0.63 -2.12
    -0.53 -0.67 -1.40 -1.65
     0.50 -0.91  1.31 -1.80
     0.70  0.11 -2.04 -1.83];

% procjena parametara distribucije
x = sum(m)/10

xx= [x
     x
     x
     x
     x
     x
     x
     x
     x
     x];
 
m2 = m-xx;
suma = 0;
for i=1:10
    element = transpose(m2(i,:))*m2(i,:);
    suma = suma + element;
end
% procjena kovarijacijske matrice
suma = suma / 10

mcov = suma;
invmcov = inv(mcov);

a=[1 1 1 1] - [1 1 -1 -1];

dist = sqrt(a * invmcov * transpose(a))
edist = sqrt(a * transpose(a))
