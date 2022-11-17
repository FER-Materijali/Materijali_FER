function [ MI, SIGMA, PI, LOG_IZGL ] = EM_algoritam( X,K,maxIter )
%EM_ALGORITAM Prima skup primjera, broj grupa, vraæa parametre i
%log-izglednost

X=X(randperm(500),:);
MI = k_means(X,K,maxIter);
SIGMA = zeros(K,2,2);
for k = 1:K
    SIGMA(k,:,:) = eye(2);
end
PI = ones(K,1)/K;
LOG_IZGL = 0;
iter = 0;


while 1
    LOG_IZGL_stara = LOG_IZGL;
    PI_stara = PI;
    MI_stara = MI;
    SIGMA_stara = SIGMA;
    iter = iter + 1;
    disp(iter);


    %E-korak
    h = zeros(size(X,1),K);
    for i = 1:size(X,1)
        p_x = 0;
        for k = 1:K
            p_x = p_x + mGauss(X(i,:),MI(k,:),[SIGMA(k,:,1); SIGMA(k,:,2)]) * PI(k);
        end
        for k = 1:K
            h(i,k) = mGauss(X(i,:),MI(k,:),[SIGMA(k,:,1); SIGMA(k,:,2)]) * PI(k)/p_x;
            if isnan(h(i,k))
                h(i,k)=0;
            end
        end
    end
    
    
    %M-korak
    for k = 1:K
        MI(k,:) = h(:,k)'*X/sum(h(:,k));
        suma = zeros(2,2);
        for i = 1:size(X,1)
                suma = suma + h(i,k) * (X(i,:)-MI(k,:))'*(X(i,:)-MI(k,:));
        end
        SIGMA(k,:,:) = suma/sum(h(:,k));
        PI(k) = sum(h(:,k))/size(X,1);
    end
    
    %log_izglednost
    LOG_IZGL = 0;
    for i = 1:size(X,1)
        suma = 0;
        for k=1:K
            suma = suma + mGauss(X(i,:),MI(k,:),[SIGMA(k,:,1); SIGMA(k,:,2)]) * PI(k);
        end
        LOG_IZGL = LOG_IZGL + log(suma);
    end
    
    
    
    %uvjeti konvergencije
    if PI == PI_stara
        if MI == MI_stara
            if SIGMA == SIGMA_stara
                fprintf('PARAMETRI_konvergencija\n');
                break
            end
        end
    end
    
    if LOG_IZGL == LOG_IZGL_stara
        fprintf('IZGLEDNOST_konvergencija\n');
        break
    end
    
    if iter > maxIter
        break
    end
end

fprintf('Broj iteracija = %d\n',iter);
fprintf('Log-izglednost = %f\n',LOG_IZGL);

end

