x = random('norm',1,9,90,90);
figure, imshow(x);
imwrite(x, 'proba.tif');
y = imread('proba.tif');
figure, imshow(y);