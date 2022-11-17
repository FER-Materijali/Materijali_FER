clc;
clear;



%ucitavanje podataka
podatci=dlmread('su-2011-dz2-zad5-podatci.txt');
X = podatci(:, 1:2);
y = podatci(:, 3);



%rad sa podskupom X5, racunanje srednje vrijednosti i kov_matrice
X5 = X(y==5, :);
mi5 = mean(X5);
kov_matrica5 = zeros(2,2);
for i=1:size(X5,1),
    kov_matrica5 = kov_matrica5 + (X5(i,:)-mi5)'*(X5(i,:)-mi5);
end
kov_matrica5 = kov_matrica5/size(X5,1);

%rad sa podskupom X6, racunanje srednje vrijednosti i kov_matrice
X6 = X(y==6, :);
mi6 = mean(X6);
kov_matrica6 = zeros(2,2);
for i=1:size(X6,1),
    kov_matrica6 = kov_matrica6 + (X6(i,:)-mi6)'*(X6(i,:)-mi6);
end
kov_matrica6 = kov_matrica6/size(X6,1);

%racunanje P(C5) i P(C6)
P5 = size(X5,1)/(size(X5,1)+size(X6,1));
P6 = size(X6,1)/(size(X5,1)+size(X6,1));

%za modele 2 i 3
dijeljena_matrica = P5*kov_matrica5 + P6*kov_matrica6;
izotropni_sigma = (dijeljena_matrica(1,1)+dijeljena_matrica(2,2))/2;



%podjela skupova
X = [X5 5*ones(size(X5,1),1); X6 6*ones(size(X6,1),1)];
m = size(X,1);
permutacije = randperm(m);
X = X(permutacije,:);

XUcenje = X(1:floor(3*m/5),1:2);
yUcenje = X(1:floor(3*m/5),3);

XProvjera = X(ceil(3*m/5):floor(4*m/5),1:2);
yProvjera = X(ceil(3*m/5):floor(4*m/5),3);

XIspit = X(ceil(4*m/5):end,1:2);
yIspit = X(ceil(4*m/5):end,3);



%maknuti iz komentara ukoliko se zeli pokrenuti
%%crtanje
%figure;
%plot(X5(:,1),X5(:,2),'bo');
%hold on;
%plot(X6(:,1),X6(:,2),'r+');
%ezplot(@(x,y)granica_model1([x y],kov_matrica5,mi5,P5,kov_matrica6,mi6,P6),[-10 20 -20 10]); %za h1 P(C1|x)-P(C2|x)
%hold off;
%xlabel('x');
%ylabel('y');
%title('Model sa razlièitim kovarijacijskim matricama');
%print -deps Model1.eps
%print -djpeg Model1.jpeg

%figure;
%plot(X5(:,1),X5(:,2),'bo');
%hold on;
%plot(X6(:,1),X6(:,2),'r+');
%ezplot(@(x,y)granica_model2([x y],dijeljena_matrica,mi5,P5,mi6,P6),[-10 20 -20 10]); %za h2 P(C1|x)-P(C2|x)
%hold off;
%xlabel('x');
%ylabel('y');
%title('Model sa dijeljenom kovarijacijskom matricom');
%print -deps Model2.eps
%print -djpeg Model2.jpeg

%figure;
%plot(X5(:,1),X5(:,2),'bo');
%hold on;
%plot(X6(:,1),X6(:,2),'r+');
%ezplot(@(x,y)granica_model3([x y],izotropni_sigma,mi5,P5,mi6,P6), [-10 20 -20 10]); %za h3 P(C1|x)-P(C2|x)
%hold off;
%xlabel('x');
%ylabel('y');
%title('Model sa dijeljenom izotropnom kovarijacijskom matricom');
%print -deps Model3.eps
%print -djpeg Model3.jpeg



%nauci model na skupu za ucenje
X5U = XUcenje(yUcenje==5, :);
mi5 = mean(X5U);
kov_matrica5 = zeros(2,2);
for i=1:size(X5U,1),
    kov_matrica5 = kov_matrica5 + (X5U(i,:)-mi5)'*(X5U(i,:)-mi5);
end
kov_matrica5 = kov_matrica5/size(X5U,1);

X6U = XUcenje(yUcenje==6, :);
mi6 = mean(X6U);
kov_matrica6 = zeros(2,2);
for i=1:size(X6U,1),
    kov_matrica6 = kov_matrica6 + (X6U(i,:)-mi6)'*(X6U(i,:)-mi6);
end
kov_matrica6 = kov_matrica6/size(X6U,1);

P5 = size(X5U,1)/(size(X5U,1)+size(X6U,1));
P6 = size(X6U,1)/(size(X5U,1)+size(X6U,1));

dijeljena_matrica = P5*kov_matrica5 + P6*kov_matrica6;
izotropni_sigma = (dijeljena_matrica(1,1)+dijeljena_matrica(2,2))/2;



%pogreske generalizacije na skupu za provjeru, model 1
Pogreska_model1 = 0;
for i=1:size(XProvjera,1),
    if model1(XProvjera(i,:),kov_matrica5,mi5,P5)>model1(XProvjera(i,:),kov_matrica6,mi6,P6),
        klasifikacija = 5;
    else
        klasifikacija = 6;
    end
    if klasifikacija~= yProvjera(i),
        Pogreska_model1=Pogreska_model1+1;
    end
end
Pogreska_model1 = Pogreska_model1/size(XProvjera,1)

%pogreske generalizacije na skupu za provjeru, model 2
Pogreska_model2 = 0;
for i=1:size(XProvjera,1),
    if model2(XProvjera(i,:),dijeljena_matrica,mi5,P5)>model2(XProvjera(i,:),dijeljena_matrica,mi6,P6),
        klasifikacija = 5;
    else
        klasifikacija = 6;
    end
    if klasifikacija~= yProvjera(i),
        Pogreska_model2=Pogreska_model2+1;
    end
end
Pogreska_model2 = Pogreska_model2/size(XProvjera,1)

%pogreske generalizacije na skupu za provjeru, model 3
Pogreska_model3 = 0;
for i=1:size(XProvjera,1),
    if model3(XProvjera(i,:),izotropni_sigma,mi5,P5)>model3(XProvjera(i,:),izotropni_sigma,mi6,P6),
        klasifikacija = 5;
    else
        klasifikacija = 6;
    end
    if klasifikacija~= yProvjera(i),
        Pogreska_model3=Pogreska_model2+1;
    end
end
Pogreska_model3 = Pogreska_model3/size(XProvjera,1)



%ucenje na skupu za ucenje i skupu za provjeru
Xskupno=X(1:floor(4*m/5),1:2);
yskupno=X(1:floor(4*m/5),3);
X5U = Xskupno(yskupno==5, :);
mi5 = mean(X5U);
kov_matrica5 = zeros(2,2);
for i=1:size(X5U,1),
    kov_matrica5 = kov_matrica5 + (X5U(i,:)-mi5)'*(X5U(i,:)-mi5);
end
kov_matrica5 = kov_matrica5/size(X5U,1);

X6U = Xskupno(yskupno==6, :);
mi6 = mean(X6U);
kov_matrica6 = zeros(2,2);
for i=1:size(X6U,1),
    kov_matrica6 = kov_matrica6 + (X6U(i,:)-mi6)'*(X6U(i,:)-mi6);
end
kov_matrica6 = kov_matrica6/size(X6U,1);

P5 = size(X5U,1)/(size(X5U,1)+size(X6U,1));
P6 = size(X6U,1)/(size(X5U,1)+size(X6U,1));

dijeljena_matrica = P5*kov_matrica5 + P6*kov_matrica6;
izotropni_sigma = (dijeljena_matrica(1,1)+dijeljena_matrica(2,2))/2;
%pogreska na ispitnom skupu
Pogreska2_model1 = 0;
for i=1:size(XIspit,1),
    if model1(XIspit(i,:),kov_matrica5,mi5,P5)>model1(XIspit(i,:),kov_matrica6,mi6,P6),
        klasifikacija = 5;
    else
        klasifikacija = 6;
    end
    if klasifikacija~= yIspit(i),
        Pogreska2_model1=Pogreska2_model1+1;
    end
end
Pogreska2_model1 = Pogreska2_model1/size(XIspit,1)

Pogreska2_model2 = 0;
for i=1:size(XIspit,1),
    if model2(XIspit(i,:),dijeljena_matrica,mi5,P5)>model2(XIspit(i,:),dijeljena_matrica,mi6,P6),
        klasifikacija = 5;
    else
        klasifikacija = 6;
    end
    if klasifikacija~= yIspit(i),
        Pogreska2_model2=Pogreska2_model2+1;
    end
end
Pogreska2_model2 = Pogreska2_model2/size(XIspit,1)

Pogreska2_model3 = 0;
for i=1:size(XIspit,1),
    if model3(XIspit(i,:),izotropni_sigma,mi5,P5)>model3(XIspit(i,:),izotropni_sigma,mi6,P6),
        klasifikacija = 5;
    else
        klasifikacija = 6;
    end
    if klasifikacija~= yIspit(i),
        Pogreska2_model3=Pogreska2_model2+1;
    end
end
Pogreska2_model3 = Pogreska2_model3/size(XIspit,1)