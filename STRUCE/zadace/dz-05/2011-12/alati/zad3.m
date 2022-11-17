clc;
clear;

%GenerirajPrimjere();

load 'primjeri.txt'

%[MI J]= k_means(primjeri(:,1:2),5,100);

%%Akainu
%J = zeros(10,1);
%for i = 1:10
%    [MI J(i)] = k_means(primjeri(:,1:2),i,100);
%end

%[ MI, SIGMA, PI, LOG_IZGL ] = EM_algoritam(primjeri(:,1:2),5,100);

%Randov indeks, za k-means
K=5
nazivnik = 500*499/2;
Rkm=zeros(10,1);
for iter = 1:10
    %k-means algoritam
    [MI J] = k_means(primjeri(:,1:2),K,100);
    %trebamo odrediti grupe
    h = zeros(size(primjeri,1),K);
    for i = 1:size(primjeri,1)
        udaljenost = zeros(K,1);
        for k = 1:K
            udaljenost(k)= sqrt((primjeri(i,1:2)-MI(k,:))*(primjeri(i,1:2)-MI(k,:))');
        end
        [vrijednost k]=min(udaljenost);
        J = J + vrijednost^2;
        h(i,k)=1;
    end
    
    
    a=0;
    b=0;
    for i=1:499
        for j = i+1:500
            if h(i,:)==h(j,:)
                if primjeri(i,3) == primjeri(j,3)
                    a= a+1;
                end
            else
                if primjeri(i,3)~=primjeri(j,3)
                    b=b+1;
                end
            end
        end
    end
    disp(a)
    disp(b)
    Rkm(iter)=(a+b)/nazivnik;
end
%Randov indeks za EM
Rem=zeros(10,1);
for iter = 1:10
    %k-means algoritam
    [ MI, SIGMA, PI, LOG_IZGL ] = EM_algoritam(primjeri(:,1:2),5,100);
    %trebamo odrediti grupe
    h = zeros(size(primjeri,1),K);
    for i = 1:size(primjeri,1)
        p_x = 0;
        for k = 1:K
            p_x = p_x + mGauss(primjeri(i,1:2),MI(k,:),[SIGMA(k,:,1); SIGMA(k,:,2)]) * PI(k);
        end
        for k = 1:K
            h(i,k) = mGauss(primjeri(i,1:2),MI(k,:),[SIGMA(k,:,1); SIGMA(k,:,2)]) * PI(k)/p_x;
            if isnan(h(i,k))
                h(i,k)=0;
            end
        end
    end
    
    a=0;
    b=0;
    for i=1:499
        [maxvali maxindi] = max(h(i,:));
        for j = i+1:500
            [maxvalj maxindj] = max(h(j,:));
            if maxindi==maxindj
                if primjeri(i,3) == primjeri(j,3)
                    a= a+1;
                end
            else
                if primjeri(i,3)~=primjeri(j,3)
                    b=b+1;
                end
            end
        end
    end
    disp(a)
    disp(b)
    Rem(iter)=(a+b)/nazivnik;
end