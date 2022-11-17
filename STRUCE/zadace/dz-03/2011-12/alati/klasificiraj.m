function [ h ] = klasificiraj( X,w )

 h = sigmoid([ones(size(X,1),1) X]*w) > 0.5;

end

