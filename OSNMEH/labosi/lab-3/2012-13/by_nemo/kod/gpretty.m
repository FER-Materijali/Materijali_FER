%%
hFig = figure(1);
set(hFig, 'Position', [1200 200 1024 1024]);
%%
%%opt
plot(n_opt(:,1), n_opt(:,2), 'r');
hold on;
plot(n_sim_opt(:,1), n_sim_opt(:,2), 'g');
%%
%%lab3 Beq 6x
plot(n1_ref(:,1), n1_ref(:,2), 'r');
hold all;
plot(n1_sim(:,1), n1_sim(:,2), 'g');
plot(n1_real(:,1), n1_real(:,2), 'c');
%%
%%lab3 Beq 5x
plot(n2_ref(:,1), n2_ref(:,2), 'r');
hold all;
plot(n2_sim(:,1), n2_sim(:,2), 'g');
plot(n2_real(:,1), n2_real(:,2), 'c');

%%
%%test Beq 12
plot(n_real(:,1), n_real(:,2), 'r');
hold all;
plot(n_sim(:,1), n_sim(:,2), 'g');
%%
%%test 4 V, Beq = 0.0015*6;
plot(n_real_test(:,1), n_real_test(:,2), 'r');
hold all;
plot(n_sim_test(:,1), n_sim_test(:,2), 'g');
%%
plot(NaponMotor(:,1), NaponMotor(:,2));
%%
plot(Tacho(:,1), Tacho(:,2));

%%
plot(EncoderCnt(:,1), EncoderCnt(:,2));

%%
plot(EncoderRPM1(:,1), EncoderRPM1(:,2));


%%
plot(Response(:,1), Response(:,2), 'b');
hold all;
plot(Response(:,1), Response(:,3), 'r');
%%
%%lab3 Beq 6x
plot(n1_ref(:,1), n1_ref(:,2), 'r');
hold all;
plot(n1_sim(:,1), n1_sim(:,2), 'g');
plot(n1_real(:,1), n1_real(:,2), 'b');
%%
plot(ulazna_f(:,1), ulazna_f(:,2), 'r');
%%
set(gca, 'Xlim', [1 1.15], 'Ylim', [-30 30]);
%set(gca, 'linewidth', 1);
set(get(gca, 'children'), 'linewidth', 1.5);

%%
hLegend = legend( ...
    'Referentni signal', 'Simulirani signal', ...
    'location', 'NorthEast');
%hTitle = title('Usporedba signala MultiQ-PCI kartice');
hXLabel = xlabel('Vrijeme (s)' , 'fontsize', 20);
hYLabel = ylabel('Brzina vrtnje (RPM)', 'fontsize', 20);

%% Ultra fancy stuff

set( gca                       , ...
    'FontName'   , 'Helvetica' );
set([hXLabel, hYLabel], ...
    'FontName'   , 'AvantGarde');
set( gca             , ...
    'FontSize'   , 14           );

set( hLegend             , ...
    'FontSize'   , 18           );
%set([hXLabel, hYLabel]  , ...
%    'FontSize'   , 12          );
%set( hTitle                    , ...
%    'FontSize'   , 14          , ...
%    'FontWeight' , 'bold'      );

set(gca, ...
  'Box'         , 'off'     , ...
  'TickDir'     , 'out'     , ...
  'TickLength'  , [.02 .02] , ...
  'XMinorTick'  , 'on'      , ...
  'YMinorTick'  , 'on'      , ...
  'YGrid'       , 'on'      , ...
  'XColor'      , [.3 .3 .3], ...
  'YColor'      , [.3 .3 .3], ...
  'YTick'       , -30:10:30, ...
  'LineWidth'   , 1         );
