[img, map] = imread('saturn.tif');
imgGN = imnoise(img, 'gaussian');
imgSP = imnoise(img, 'salt & pepper');
figure, imshow(imgGN)
figure, imshow(imgSP)
maska = ones(5);
maska = maska / sum(maska(:));
imgGNN= double(imgGN);
imgSPP = double(imgSP);
imgSF = conv2(imgGNN, maska, 'same');
imgSF2 = conv2(imgSPP, maska, 'same');
figure, imshow(imgSF)
figure, imshow(imgSF2)
imgMF = medfilt2(imgGN, [5 5]);
imgMF2 = medfilt2(imgSP, [5 5]);
figure, imshow(imgMF)
figure, imshow(imgMF2)