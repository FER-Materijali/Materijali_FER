podaci = dlmread('podaci.txt');
X = podaci(:, 1:2);
Y = podaci(:, 3);
Y3 = [];

X1 = X(Y == 3, :);
X2 = X(Y == 7, :);

% racunamo parametre po formulama


e1 = [0 0
      0 0];
e2 = [0 0
      0 0];
  
size_x = size(X);
size_x = size_x(1);
size_x1 = size(X1);
size_x1 = size_x1(1);
size_x2 = size(X2);
size_x2 = size_x2(1);

for i=1:size_x1
    xx = transpose(X1(i)-mi_1)*(X1(i)-mi_1);
    e1 = e1 + xx;
end
mi_1 = mean(X1)
e1 = e1 / size_x1
P1 = size_x1 / size_x
for i=1:size_x2
    xx = transpose(X2(i)-mi_2)*(X2(i)-mi_2);
    e2 = e2 + xx;
end
mi_2 = mean(X2)
e2 = e2 / size_x2
P2 = size_x2 / size_x


for i=1:size_x1
   Y3(i) = 3; 
end
for i=size_x1:size_x1 + size_x2
   Y3(i) = 7;
end
Y3 = transpose(Y3);

X3 = vertcat(X1, X2);

size(Y3);
% fino smo joinali skup za u?enje i Y

SKUP = horzcat(X3,Y3); % joinamo ih da se mogu randomizirati

SKUP(randperm(size(SKUP,1)),:);



% crtanje
model1 = @(x,5) 0.5*log(det(e1)) - 0.5 * (([x y])*inv(e1)*traspose([x y]));
model2 = @(x) 0;
model = @(x) model2(x) - model1(x)

plot(X(Y==3,1),X(Y==3,2),'o');
hold on;
plot(X(Y==7,1),X(Y==7,2),'+');
ezplot(model,[-10 10 -10 10]);
hold off;
xlabel('x');
ylabel('y');
print -deps slika.eps
 