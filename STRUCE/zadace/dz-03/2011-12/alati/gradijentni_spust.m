function [ w ] = gradijentni_spust( X,y,eta,lambda, iter )

%racunanje tezinskih faktora w pomocu gradijentnog spusta
w = zeros(size(X,2)+1,1);
for i=1:iter,
   [~, deltaE] = pogreska(w,X,y,lambda);
   w = w - eta*deltaE;
end

end

