%%Parametri
Uulv = -0.5;            % [V]
Uuln = -2.0;            % [V]
T1 = 0.5;               % [ms] - Trajanje visoke razine
T2 = 2.0;               % [ms] - Trajanje niske razine
R = 4.7;                % [k ohm]
C = 1;                  % [mikro F]
Tau = R*C;              % [ms]

%%Izrazi
a = 1 - exp(-T1/Tau);
b = 1 - exp(-T2/Tau);

%%Naponi
Uv = 1 / (a - a*b + b) * ((b-a*b)*Uuln + a*Uulv)       % Maksimalni napon na kondenzatoru
Un = (Uuln - Uv) * b + Uv                              % Minimalni napon na kondenzatoru
Urv = Un + Uulv                                        % Maksimalni napon na otporniku
Urn = Uuln - Uv                                        % Minimalni napon na otporniku