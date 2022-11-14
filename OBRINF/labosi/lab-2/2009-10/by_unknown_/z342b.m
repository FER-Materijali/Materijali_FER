X = imread('angio0.tif'); % uèitavamo sliku
Y = imread('angio1.tif'); % uèitavamo sliku
razlika=X-Y;
figure;
imagesc(razlika);

X = imread('angio0.tif'); % uèitavamo sliku
Y = imread('angio1.tif'); % uèitavamo sliku
razlika2=Y-X;
figure;
imagesc(razlika2);