% Machine Learning, FER-Zagreb, 2009.
% Author: Zeljan Juretic

clear;
clc;

% User-defined constants
numOrders = 10;     % Highest order of polynom
numSamples = 15;    % Number of samples for training


numDots = 100;
yHeight = 10;
deletion = 1;

x = linspace(0, 5, numDots);
fx = 2*sin(1.5.*x);

figure;
axes1 = subplot(2,1,1);
h = plot(x, fx, 'LineWidth', 2);
set(axes1, 'YTick', -5:5:5);
set(axes1, 'XTick', 0:0.5:5);
ylim([-5 5]);
xlim([0 5]);

hold on;

sampleTrainX = 5*rand(numSamples, 1);
sampleTrainY = 2*sin(1.5.*sampleTrainX);

% let's make some noise
noise = 0 + 1.*randn(numSamples, 1);
sampleTrainY = sampleTrainY + noise;
plot(sampleTrainX, sampleTrainY, 'rx', 'LineWidth', 2, 'MarkerSize', 10);


sampleValidX = 5*rand(numSamples, 1);
sampleValidY = 2*sin(1.5.*sampleValidX);

% let's make some noise
noise = 0 + 1.*randn(numSamples, 1);
sampleValidY = sampleValidY + noise;
plot(sampleValidX, sampleValidY, 'gx', 'LineWidth', 2, 'MarkerSize', 10);
legend('f(x)=2sin(1.5x)', 'Training set', 'Validation set');


errTrain = zeros(numOrders, 1);
errValid = zeros(numOrders, 1);

axes2 = subplot(2,1,2);
hTrain = plot(axes2, 1:1:numOrders, errTrain, 'r', 'LineWidth', 2);
hold on;
hValid = plot(axes2, 1:1:numOrders, errValid, 'g', 'LineWidth', 2);
xlim([1 numOrders]);
set(axes2, 'XTick', 0:1:numOrders);
ylim([0 yHeight]);
set(axes2, 'YTick', 0:1:numOrders);
legend('Training set', 'Validation set');


waitforbuttonpress;
delete(h);
legend('Training set', 'Validation set');
waitforbuttonpress;

for polyOrder=1:numOrders 
    p = polyfit(sampleTrainX, sampleTrainY, polyOrder);
    f = polyval(p, x);
    handle = plot(axes1, x, f, 'k', 'LineWidth', 2);
    if deletion == 1
        title(axes1, strcat('Order: ', num2str(polyOrder)));
    end
    
    errTrain(polyOrder, 1) = (1/numSamples)*sum((( polyval(p, sampleTrainX) - 2*sin(1.5.*sampleTrainX) ).^2));
    errValid(polyOrder, 1) = (1/numSamples)*sum((( polyval(p, sampleValidX) - 2*sin(1.5.*sampleValidX) ).^2));
    
    delete(hTrain);
    hTrain = plot(axes2, 1:1:numOrders, errTrain, 'r', 'LineWidth', 2);
    hold on;
    delete(hValid);
    hValid = plot(axes2, 1:1:numOrders, errValid, 'g', 'LineWidth', 2);
  
    waitforbuttonpress;
    if deletion == 1
        delete(handle)
    end
end

subplot(2,1,1);
h = plot(x, fx, 'LineWidth', 2);
title(axes1, '');

avg = errTrain + errValid;
[minimum, minInd] = min(avg);
p = polyfit(sampleTrainX, sampleTrainY, minInd);
f = polyval(p, x);
plot(axes1, x, f, 'k', 'LineWidth', 2);
legend(axes1, 'Training set', 'Validation set','f(x)=2sin(1.5x)', strcat('Optimal order:', num2str(minInd)));

plot(axes2, minInd*ones(numOrders+1, 1), 0:1:numOrders, 'm--', 'LineWidth', 2);
legend(axes2, 'Training set', 'Validation set', 'Optimal order');