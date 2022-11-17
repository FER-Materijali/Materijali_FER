clear; clc; close all
x = [-20:0.1:20];

norm1 = normpdf(x, -5, 5);
norm2 = normpdf(x, 0, 1);
norm3 = normpdf(x, 5, 10);
plot(x, norm1)
hold on
plot(x, norm2)
plot(x, norm3)
legend('y=1', 'y=2', 'y=3', 'location', 'best')
title('p(x|y)')

figure
joint1 = norm1 * 0.3;
joint2 = norm2 * 0.2;
joint3 = norm3 * 0.5;
plot(x, joint1)
hold on
plot(x, joint2)
plot(x, joint3)
legend('y=1', 'y=2', 'y=3', 'location', 'best')
title('p(x, y)')

figure
px = joint1 + joint2 + joint3;
plot(x, px)
title('p(x)')

figure
p_y1_x = joint1 ./ px;
p_y2_x = joint2 ./ px;
p_y3_x = joint3 ./ px;
plot(x, p_y1_x)
hold on
plot(x, p_y2_x)
plot(x, p_y3_x)
legend('y=1', 'y=2', 'y=3', 'location', 'best')
title('p(y|x)')
