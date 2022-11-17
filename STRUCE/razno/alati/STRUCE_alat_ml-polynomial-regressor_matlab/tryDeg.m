function [ err1, err1r, err2, err2r, y] = tryDeg(tData, vData, x, deg)
W=getW(deg,tData);
g1=calcG(tData(:,1), W);
g2=calcG(vData(:,1), W);
err1=mean((tData(:,2)'-g1).^2);
err1r=((tData(:,2)'-g1).^2/(tData(:,2)'-mean(tData(:,2))).^2);
err2=mean((vData(:,2)'-g2).^2);
err2r=((vData(:,2)'-g2).^2/(vData(:,2)'-mean(vData(:,2))).^2);
y=calcG(x,W);
end

