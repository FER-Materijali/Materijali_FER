function [ g ] = calcG(x, W)
N=length(x);
g=zeros(1,N);
k=length(W);
for i=1:N
    for j=0:k-1
        g(i)=g(i)+W(j+1)*(x(i)^j);
    end
end
end

