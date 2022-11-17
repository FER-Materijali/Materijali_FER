P = [0.2, 0.05; 0.05, 0.3; 0.3, 0.1];
Px = [0.55, 0.45];
Py = [0.25, 0.35, 0.4];

I = 0;
for i=1:3
    for j=1:2
        I = I + P(i, j)*log(P(i,j)/(Px(j)*Py(i)));
    end
end

disp('I = ')
disp(I)