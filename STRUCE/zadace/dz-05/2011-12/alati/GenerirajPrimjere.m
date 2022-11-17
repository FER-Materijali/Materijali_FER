function [ ] = GenerirajPrimjere( )
%GENERIRAJPRIMJERE Generira 5 izvora, iz svakog izvora po 100 primjera po
%gaussovoj razdiobi, primjere sprema u primjeri.txt

izvori = 100*rand(5,2);
sigma = 30*rand(5,1) + 10;
X = zeros(500,3);
for i = 1:5
	x1 = normrnd(izvori(i,1),sigma(i),[100,1]);
	x2 = normrnd(izvori(i,2),sigma(i),[100,1]);
	X((i-1)*100+1:i*100,:) = [x1,x2,i*ones(100,1)];
end

dlmwrite('primjeri.txt',X);
figure; hold; grid;

scatter (X(1:100,1),X(1:100,2),20*ones(100,1),X(1:100,3),'filled');
scatter (X(101:200,1),X(101:200,2),20*ones(100,1),X(101:200,3),'filled');
scatter (X(201:300,1),X(201:300,2),20*ones(100,1),X(201:300,3),'filled');
scatter (X(301:400,1),X(301:400,2),20*ones(100,1),X(301:400,3),'filled');
scatter (X(401:500,1),X(401:500,2),20*ones(100,1),X(401:500,3),'filled');

legend('Izvor 1','Izvor 2','Izvor 3','Izvor 4','Izvor 5')
xlabel('x1');ylabel('x2');title('Zadatak 3, primjeri');

end

