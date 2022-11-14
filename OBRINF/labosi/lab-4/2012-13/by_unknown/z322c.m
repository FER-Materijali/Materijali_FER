img = imread('cameraman.tif');
img = double(img);
IMG = fft2(img);
IMG = fftshift(IMG);
figure, imagesc(20*log10(abs(IMG)));
figure, imagesc(angle(IMG));
A = [cosd(27) -sind(27) 0; sind(27) cosd(27) 0; 0 0 1]
T = maketform('affine', A);
imgT = imtransform(img, T);
figure, imshow(img);
figure, imshow(imgT);
imgT = double(imgT);
IMGT = fft2(imgT);
IMGT = fftshift(IMGT);
figure, imagesc(20*log10(abs(IMGT)));
figure, imagesc(angle(IMGT));