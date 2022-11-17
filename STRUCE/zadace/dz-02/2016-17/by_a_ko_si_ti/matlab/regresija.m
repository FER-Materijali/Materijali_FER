clc;clear all; close all;
Phi = [1 -3 1; 1 -3 3; 1 1 2; 1 2 1; 1 1 -2; 1 2 -3]
y1 = [1 1 0 0 0 0]'
y2 = [0 0 1 1 0 0]'
y3 = [0 0 0 0 1 1]'

%I = eye(3);
%I(1,1) = 0
w1 = inv(Phi'*Phi)*Phi'*y1
w2 = inv(Phi'*Phi)*Phi'*y2
w3 = inv(Phi'*Phi)*Phi'*y3

x11 = [-5:0.1:5];
x12 = (w1(1)+w1(2)*x11)/w1(3);

x21 = [-5:0.1:5];
x22 = (w2(1)+w2(2)*x21)/w2(3);

x31 = [-5:0.1:5];
x32 = (w3(1)+w3(2)*x31)/w3(3);


ws = w1 - w2
h12 = (ws(1)+ws(2)*x11)/ws(3);

ws = w2 - w3
h23 = (ws(1)+ws(2)*x11)/ws(3);

ws = w1 - w3
h13 = (ws(1)+ws(2)*x11)/ws(3);

plot(x11, x12, 'b')
hold on
plot(x21, x22, 'b')
plot(x31, x32, 'b')

plot(x11, h12)
hold on
plot(x21, h23)
plot(x31, h13)
ylim([-10,10])
legend('h12','h23','h13')
plot(-3, 1, 'bx')
plot(-3, 3, 'bx')
plot(1, 2, 'rx')
plot(2, 1, 'rx')
plot(1, -2, 'yx')
plot(2, -3, 'yx')

%plot(-1, 3, 'x')
