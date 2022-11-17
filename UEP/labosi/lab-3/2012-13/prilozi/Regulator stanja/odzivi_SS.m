clear
clc
close all

r = 5 ;
parametri ;

D = [0.5, 0.5, 0.5, 0.5] ;

[Ti, Kw1, Kw2, Kda] = parametri_reg(Tm1, Tm2, d, c, Tei, T, Tb, D)


%%
sim('reg_SS.mdl') ;

plot(odziv_w(:, 1), odziv_w(:, 3), 'r','LineWidth',2) ;
hold on
plot(odziv_w(:, 1), odziv_w(:, 4), 'b','LineWidth',2) ;
grid on
title('r = 0.2') 
xlabel('t [s]')
ylabel('\omega [rad/s]')
legend('\omega_{1}', '\omega_{2}')

figure
plot(odziv_m(:, 1), odziv_m(:, 2), 'Color', [0.4, 0.8, 0.6],'LineWidth',2) ;
hold on
plot(odziv_m(:, 1), odziv_m(:, 3), 'Color', [0.8, 0, 0.5],'LineWidth',2) ;
grid on
title('r = 0.2')
xlabel('t [s]')
ylabel('m [Nm]')
legend('m_{1R}', 'm_{1}')
