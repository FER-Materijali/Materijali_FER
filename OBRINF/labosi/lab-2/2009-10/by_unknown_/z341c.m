X = random('norm',1,9,90,90); % kreiramo sliku
imwrite(X, 'proba.tif'); % snimamo je
Y = imread('proba.tif'); % uèitavamo sliku
figure, imagesc(X);
figure, imagesc(Y); % jesu li slike iste?