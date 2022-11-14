[img, map] = imread('blood1.tif');
figure, imhist(img)
figure, grayslice(imscale(img), 120/255)
figure, grayslice(imscale(img), 120/255 - 0.2)
figure, grayslice(imscale(img), 120/255 + 0.2)
figure, grayslice(imscale(img), [50 120]/255)