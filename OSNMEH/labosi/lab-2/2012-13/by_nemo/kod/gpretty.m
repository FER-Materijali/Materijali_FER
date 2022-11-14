%%
plot(AnalogIn_38Hz(:,1), AnalogIn_38Hz(:,2));
hold;
stairs(AnalogOut_38Hz(:,1), AnalogOut_38Hz(:,2), 'r');
%%
plot(NaponMotor(:,1), NaponMotor(:,2));
%%
%%
plot(Tacho(:,1), Tacho(:,2));

%%
plot(EncoderCnt(:,1), EncoderCnt(:,2));

%%
plot(EncoderRPM1(:,1), EncoderRPM1(:,2));

%%
hFig = figure(1);
set(hFig, 'Position', [1200 200 1024 1024]);
%%
plot(Response(:,1), Response(:,2), 'b');
hold all;
plot(Response(:,1), Response(:,3), 'r');
%%
set(gca, 'Xlim', [0 0.25], 'Ylim', [-10 350]);
%set(gca, 'linewidth', 1);
set(get(gca, 'children'), 'linewidth', 1.5);

%%
hLegend = legend( ...
    'Step', 'Odziv', ...
    'location', 'NorthWest');
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
  'YTick'       , -10:60:350, ...
  'LineWidth'   , 1         );
