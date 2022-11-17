clc;
clear;

load X_train.txt
load y_train.txt


%----- izracunaj i spremi tezine u w_a.txt ------%
%eta = 0.007; lambda = 0; iter = 1500;
%w = gradijentni_spust(X_train,y_train,eta,lambda,iter);
%save -ascii w_a.txt w;


%----- kolika je pogreska kad se ne koristi regularizacija ------%
%load w_a.txt;
%[E, ~] = pogreska(w_a,X_train,y_train,0)


load X_validate.txt;
load y_validate.txt;


%------- onih 20 lambdi -----%
%eta = 0.00005; iter = 2500;
%for lambda = [0 0.00003 0.0001 0.0003 0.001 0.003 0.01 0.03 0.1 0.3 1 3 10 30 100 300 1000 3000 10000 30000],
%    
%    w = gradijentni_spust(X_train,y_train,eta,lambda,iter);
%   greska = sum(abs(y_validate - klasificiraj(X_validate,w)));
%   fprintf ('lambda = %f postotak = %f eta = %f iter = %d\n',lambda, greska/length(y_validate), eta, iter);
%  
%end

load X_test.txt;
load y_test.txt;

%------- d) podzadatak --------%
X_unija = [X_train; X_validate];
y_unija = [y_train; y_validate];

eta = 0.00005;  lambda = 100; iter = 2500;
w = gradijentni_spust(X_unija,y_unija,eta,lambda,iter);
%save -ascii w_d.txt w;

greska_d = sum(abs(y_test - klasificiraj(X_test,w)))/length(y_test)
load w_a.txt
greska_a = sum(abs(y_test - klasificiraj(X_test,w_a)))/length(y_test)