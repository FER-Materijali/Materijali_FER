function [ W ] = getW(deg, data)
N=size(data,1);
fiMat=ones(deg,N);
for i=2:deg
    for j=1:N
        fiMat(i,j)=data(j,1)^(i-1);
    end
end
R=data(:,2);
W=R'*pinv(fiMat);
end