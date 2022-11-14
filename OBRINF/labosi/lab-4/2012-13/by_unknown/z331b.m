[img, map]= imread('auto.tif');
img = ind2gray(img, map);
imgEQ = histeq(img);
figure, imshow(img)
figure, imshow(imgEQ)
