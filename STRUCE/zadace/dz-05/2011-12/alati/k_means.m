function [ MI J] = k_means( X, K, maxIter )
%K_MEANS Prima skup primjera, broj u koliko grupa mora grupirati primjere i
%maksimalan broj iteracija, a vraæa centroide u matrici MI i vrijednost
%kriterijske funkcije J
%   X - skup primjera
%   K - broj grupa
%   maxIter - maksimalan broj iteracija
%   MI - matrica centroida
%   J - kriterijska funkcija

X=X(randperm(500),:);
MI = X(1:K,:);
iter = 0;

while 1
    iter=iter+1;
    disp (iter);
    MI_stari = MI;
    b = zeros(size(X,1),K);
    J = 0;
    
    for i = 1:size(X,1)
        udaljenost = zeros(K,1);
        for k = 1:K
            udaljenost(k)= sqrt((X(i,:)-MI(k,:))*(X(i,:)-MI(k,:))');
        end
        [vrijednost k]=min(udaljenost);
        J = J + vrijednost^2;
        b(i,k)=1;
    end
    
   
    for k = 1:K
        MI(k,:) = b(:,k)'*X/sum(b(:,k));
    end

    
    if MI == MI_stari
        break
    end
    
    if  iter == maxIter
        break
    end
end

fprintf('Broj iteracija = %d\n',iter);
fprintf('Kriterijska funkcija = %f\n',J);

%figure;hold;grid;
%[c grupe] = max (b,[],2);
%scatter (X(:,1),X(:,2),20*ones(500,1),grupe,'filled');
%xlabel('x1');ylabel('x2');title('Zadatak 3, k-means');

end

