img = imread('brodatz.tiff');
img = double(img);
IMG = fft2(img);
IMG = fftshift(IMG);
figure, imagesc(20*log10(abs(IMG)));
figure, imagesc(angle(IMG));