tiffany = rgb2gray(imread('tiffany.tiff'));
lena = rgb2gray(imread('lena.tiff'));
TIFFANY = fft2(double(tiffany));
LENA = fft2(double(lena));
prva = ifft2(abs(TIFFANY) .* exp(j*angle(LENA)));
max(imag(prva(:)))
figure, imagesc(real(prva))
colormap(gray)