clc;
clear;

%ucitavanje podataka
X = load ('iris.data');

%Diskretizacija i permutacija primjera
%Iris-setosa - 0
%Iris-versicolor - 1
%Iris-virginica - 2
[X] = uredi_varijable(X);

y = X(:,5);
X = X(:,1:4);

%podjela skupova
yUcenje = y(1:100);
yProvjera = y(101:150);
XUcenje = X(1:100,:);
XProvjera = X(101:150,:);

%ucenje bayesovog klasifikatora sa ML procjenom, i racunanje pogreski
Bayes_parametri = NauciBayesa(XUcenje,yUcenje,0);
Empirijska_pogreska = sum((Bayes_klasifikator(Bayes_parametri,XUcenje) - yUcenje)~=0)/length(yUcenje)
Pogreska_generalizacije = sum((Bayes_klasifikator(Bayes_parametri,XProvjera) - yProvjera)~=0)/length(yProvjera)

%ucenje bayesovog klasifikatora sa Laplaceovim zagladjivanjem, i racunanje pogreski
Bayes_parametri_LP = NauciBayesa(XUcenje,yUcenje,1);
Empirijska_pogreska_LP = sum((Bayes_klasifikator(Bayes_parametri_LP,XUcenje) - yUcenje)~=0)/length(yUcenje)
Pogreska_generalizacije_LP = sum((Bayes_klasifikator(Bayes_parametri_LP,XProvjera) - yProvjera)~=0)/length(yProvjera)