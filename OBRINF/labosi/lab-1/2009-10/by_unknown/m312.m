s=tf(1,[1 -.98 .91],1);
impulse(s);                      % crtamo impulsni odziv sustava
step(s);                         % crtamo odziv na jedinièni skok
pzmap(s);                        % crtamo korijene karakteristiène jednadžbe
ss(s);                           % tražimo reprezentaciju u prostoru stanja
freqz(s.num{1}, s.den{1});       % crtamo frekvencijsku karakteristiku
grpdelay(s.num{1}, s.den{1});    % crtamo grupno vrijeme kašnjenja

s=tf(1,[1 -1 1],1);
impulse(s);                      % crtamo impulsni odziv sustava
step(s);                         % crtamo odziv na jedinièni skok
pzmap(s);                        % crtamo korijene karakteristiène jednadžbe
ss(s);                           % tražimo reprezentaciju u prostoru stanja
freqz(s.num{1}, s.den{1});       % crtamo frekvencijsku karakteristiku
grpdelay(s.num{1}, s.den{1});    % crtamo grupno vrijeme kašnjenja

s=tf(1,[1 -2 1],1);
impulse(s);                      % crtamo impulsni odziv sustava
step(s);                         % crtamo odziv na jedinièni skok
pzmap(s);                        % crtamo korijene karakteristiène jednadžbe
ss(s);                           % tražimo reprezentaciju u prostoru stanja
freqz(s.num{1}, s.den{1});       % crtamo frekvencijsku karakteristiku
grpdelay(s.num{1}, s.den{1});    % crtamo grupno vrijeme kašnjenja

s=tf(1,[1 -1.38 1.42],1);
impulse(s);                      % crtamo impulsni odziv sustava
step(s);                         % crtamo odziv na jedinièni skok
pzmap(s);                        % crtamo korijene karakteristiène jednadžbe
ss(s);                           % tražimo reprezentaciju u prostoru stanja
freqz(s.num{1}, s.den{1});       % crtamo frekvencijsku karakteristiku
grpdelay(s.num{1}, s.den{1});    % crtamo grupno vrijeme kašnjenja