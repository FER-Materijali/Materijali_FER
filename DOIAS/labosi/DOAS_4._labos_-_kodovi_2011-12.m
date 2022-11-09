%% 6.1. Histogram prvog reda
close all;
clear all;

[img,map] = imread('detalj.png');
figure, imhist(img,map)

img = imread('salona.png');
figure, imhist(img)

%% 6.2. Izjednaèavanje histograma
close all; 
clear all;

[img1,map1] = imread('uskoci1.png');
img = rgb2gray(img1);
figure, imhist(img)
imgEQ = histeq(img);
figure, imhist(imgEQ)

[img2, map2] = imread('salona.png');
figure, imhist(img2);
imgEQ = histeq(img2);
figure, imhist(imgEQ)
figure, imshow(imgEQ)
figure, imshow(img2);


%% 6.3. Modeliranje histograma

% 1. zadatak
close all;
clear all;

img=imread('salona.png');
imgMEQ = histeq(img);

figure, imhist(imgMEQ)


% 2. zadatak
close all;
clear all;

img=imread('auto.tif');
imgMEQ = histeq(img);

figure, imshow(imgMEQ)


%% 6.4. Usrednjavanje i median filtar
close all;
clear all;

[img, map] = imread('3.2.25.tiff');

imgGN = imnoise(img,'gaussian');
imgSP = imnoise(img,'salt & pepper');

maska = ones(5);
maska = (1/25)*maska;

imgMF1 = medfilt2(imgSP,[5 5]);
imgMF2 = medfilt2(imgGN,[5 5]);

imgSF1 = conv2(double(imgSP),maska,'same');
imgSF2 = conv2(double(imgGN),maska,'same');

figure, imshow(imgMF1), title('Median filtar, s&p noise');
figure, imshow(imgMF2), title('Median filtar, gauss noise');
figure, imshow(uint8(imgSF1)), title('Usrednjavanje, s&p noise');
figure, imshow(uint8(imgSF2)), title('Usrednjavanje, gauss noise');


%% 6.5. Uklanjanje neoštrine

% 1. zadatak
close all;
clear all;

img = imread('blood1.tif');
maska = ones(3);

maska = maska/sum(maska(:));
imgZ = conv2(img,maska,'same');

lap = fspecial('laplacian',0.2);

imgS = conv2(imgZ,lap,'same');

figure, imshow(uint8(2*imgS+imgZ));
figure, imshow(uint8(imgS-imgZ));


% 2. zadatak
close all;
clear all;

img = imread('medalja_dubrovnik.png');

maska = ones(3);

maska = maska/sum(maska(:));
imgZ = conv2(img,maska,'same');

figure, imshow(3*img-uint8(imgZ));

% 3. zadatak
close all;
clear all;

img = imread('medalja_dubrovnik.png');

maska = ones(3);

maska = maska/sum(maska(:));
imgZ = conv2(img,maska,'same');

sob = fspecial('sobel');

imgS = conv2(imgZ,sob,'same');

figure, imshow(uint8(imgZ+2*imgS));

% 4. zadatak
close all;
clear all;

img = imread('5.1.09.tiff');
maska = ones(3);
maska = maska/sum(maska(:));
imgZ = conv2(img,maska,'same');

lap = fspecial('laplacian',0.2);
sob = fspecial('sobel');

imgL = conv2(imgZ,lap,'same');
imgS = conv2(imgZ,sob,'same');

figure, imshow(uint8(imgZ-2*imgL)), title('Laplace');
figure, imshow(uint8(imgZ+2*imgS)), title('Sobel');

% 5. zadatak
close all;
clear all;

img = imread('5.1.09.tiff');
maska = ones(3);
maska = maska/sum(maska(:));
imgZ = conv2(img,maska,'same');

lap1 = -fspecial('laplacian',0);
lap2 = 3*fspecial('laplacian',0.5);
lap2(2,2) = -lap2(2,2);

imgL1 = conv2(imgZ,lap1,'same');
imgL2 = conv2(imgZ,lap2,'same');

figure, imshow(uint8(imgZ+2*imgL1));
figure, imshow(uint8(imgZ+2*imgL2));


% 6. zadatak
close all;
clear all;

img1 = imread('4.1.06.tiff');
img2 = imread('4.2.05.tiff');
img3 = imread('4.2.06.tiff');

img1 = rgb2gray(img1);
img2 = rgb2gray(img2);
img3 = rgb2gray(img3);

maska = ones(3);
maska = maska/sum(maska(:));

img1Z = conv2(img1,maska,'same');
img2Z = conv2(img2,maska,'same');
img3Z = conv2(img3,maska,'same');

lap = fspecial('laplacian',0.2);
sob = fspecial('sobel');

img1L = conv2(img1Z,lap,'same');
img1S = conv2(img1Z,sob,'same');
img2L = conv2(img2Z,lap,'same');
img2S = conv2(img2Z,sob,'same');
img3L = conv2(img3Z,lap,'same');
img3S = conv2(img3Z,sob,'same');

figure, imshow(uint8(img1Z-2*img1L)), title('Laplace');
figure, imshow(uint8(img1Z+2*img1S)), title('Sobel');
figure, imshow(uint8(img2Z-2*img2L)), title('Laplace');
figure, imshow(uint8(img2Z+2*img2S)), title('Sobel');
figure, imshow(uint8(img3Z-2*img3L)), title('Laplace');
figure, imshow(uint8(img3Z+2*img3S)), title('Sobel');
