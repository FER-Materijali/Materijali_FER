[img, map]=imread('forest.tif');
img = ind2gray(img, map);
imgEQ = histeq(img);
figure, imshow(img)
figure, imshow(imgEQ)

img2 =imread('tiffany.tiff');
img2 = rgb2gray(img2);
img2EQ = histeq(img2);
figure, imshow(img2)
figure, imshow(img2EQ)