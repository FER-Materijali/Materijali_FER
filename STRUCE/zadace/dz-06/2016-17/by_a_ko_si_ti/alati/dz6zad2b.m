clear; clc;close all;
mi1 = [0,0]
mi2 = [-3, 3]
sig1 = 1
sig2 = 1

phi = @(x, mi, sig) exp(-(norm(x-mi))^2/(2*sig))

primjeri = [-1,-1; 0,0; 3,-3; -2, 1; -4,2]
Phi1 = zeros(size(primjeri, 1))
Phi1 = Phi1(1,:)


for i=1:length(primjeri)
    x_temp = primjeri(i,:)
    Phi1(i) = phi(x_temp, mi1, sig1)
    Phi2(i) = phi(x_temp, mi2, sig2)
end
plot(Phi1(1:2), Phi2(1:2), 'xr')
hold on
plot(Phi1(3:5), Phi2(3:5), 'ob')

xlim([-0.5, 1])
ylim([-0.5, 1])