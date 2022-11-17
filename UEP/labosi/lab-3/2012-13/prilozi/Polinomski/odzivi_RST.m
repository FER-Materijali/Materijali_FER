clear
clc
close all

% Upisi r=0.2, 1 ili 5 ; prema tom izboru ucitavaju se ostali parametri
r  = 0.2;   

parametri ;

% promjenom zadnjeg parametra u pozivu funkcije parametri_RST bira se: 
% dead beat (zadnji parametar 1) ili bez dead beata (zadnji parametar 0)
[p q s] = parametri_RST(w02, zeta2, Tb, Tms, zeta, w0, 0) 

%%
% pokretanje simulacije
sim('reg_RST.mdl') ;

% crtanje odziva
plot(w(:, 1), w(:, 3), 'b','LineWidth',2) ;
hold on
plot(w(:, 1), w(:, 4), 'r','LineWidth',2) ;
grid on
title('r =0.2 , bez dead beat') % promijeni title grafa ovisno o proslom odabiru
xlabel('t [s]') ;
ylabel('w [rad/s]') ;
legend('w_1', 'w_2') ;

figure
plot(m(:, 1), m(:, 2), 'Color', [0.4, 0.8, 0.6],'LineWidth',2) ;
hold on
plot(m(:, 1), m(:, 3), 'Color', [0.8, 0, 0.5],'LineWidth',2) ;
grid on
title('r = 0.2 , bez dead beat') % promijeni title grafa ovisno o proslom odabiru
xlabel('t [s]') ;
ylabel('m [Nm]') ;
legend('m_{1R}', 'm') ;


