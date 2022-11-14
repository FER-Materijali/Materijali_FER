img = imread('cameraman.tif');
h = fspecial('average', 25);
img = double(img);
tic; img3 = conv2(img, h); toc
figure, imagesc(img3)

tic; img4 = ifft2(fft2(img) .* fft2(img)); toc
figure, imagesc(img4)

tic; IMG = fft2(img, 280, 280);
H = fft2(h, 280, 280);
Y = IMG .* H;
y = ifft2(Y); toc
figure, imagesc(y)