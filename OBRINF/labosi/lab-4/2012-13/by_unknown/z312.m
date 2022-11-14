img1 = imread('angio0.tif');
img2 = imread('angio1.tif');
img21 = img2 -img1;
figure, imshow(img21);
img12 = img1 - img2;
figure, imshow(img12);