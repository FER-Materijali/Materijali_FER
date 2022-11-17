% Machine Learning, FER-Zagreb, 2009.
% Author: Zeljan Juretic

clear;
clc;

% User-defined constants
polyOrder = 5;      % Order of polynom
numSamples = 20;    % Number of samples for training
numFits = 5;        % Number of iterations


numDots = 100;

x = linspace(0, 5, numDots);
fx = 2*sin(1.5.*x);

figure;
plot(x, fx, 'LineWidth', 2);
set(gca, 'YTick', -5:5:5);
set(gca, 'XTick', 0:1:5);
ylim([-5 5]);
hold on;

average = zeros(1, numDots);

for i=1:numFits
    
    sampleX = 5*rand(numSamples, 1);
    sampleY = 2*sin(1.5.*sampleX);

    % let's make some noise
    noise = 0 + 1.*randn(numSamples, 1);
    sampleY = sampleY + noise;
    handle = plot(sampleX, sampleY, 'rx', 'LineWidth', 2, 'MarkerSize', 10);
    waitforbuttonpress;
    
    p = polyfit(sampleX, sampleY, polyOrder);
    f = polyval(p, x);
    h = plot(x, f, 'k', 'LineWidth', 1);
    average = average + f;
    
    waitforbuttonpress;
    delete(handle);
end

average = average / numFits;
plot(x, average, 'r--', 'LineWidth', 2);

