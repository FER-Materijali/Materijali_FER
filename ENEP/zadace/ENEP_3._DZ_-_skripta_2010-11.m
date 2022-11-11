%tip zadatka 1

%Polumjer je dvokrakog rotora polijevala trave, slika, r = 0.13 m, a ploština izlaznih sapnica As = 31 mm2. Protjeèe li kroz polijevalo trave konstantan protok od Q = 0.0018 m3/s, koliki je moment vode i atmosfere (okolnog zraka tlaka 1 bar) na rotor polijevala trave ako se rotor ne okreæe. (Primjerice, rukom sprjeèavamo okretanje rotora polijevala.)
%? = 32o, g = 9,81 m/s2, a ?vode = 1000 kg/m3.
%Rezultat izraziti u Nm. 

r_zad1 = 0.2;
A_zad1 = 38; %unos u mm^2
Q_zad1 = 0.0013;
alpha_zad1 = 42;
g = 9.81;
rho = 1000;

c_zad1 = Q_zad1/(2*A_zad1*10^-6);
m_zad1 = Q_zad1*1000;
'Moment vode i atmosfere:'
M=r_zad1*c_zad1*m_zad1*cosd(alpha_zad1)

%tip zadatka 2

%Polumjer je rotora Peltonove turbine 1.9 m. Ukoliko je broj okretaja rotora 178 u minuti, protok 19 m3/s, 
%izlazni kut lopatice 16o, a brzina vode na izlazu iz sapnice 75 m/s, kolika je snaga turbine? 
%g = 9,81 m/s2, a ?vode = 1000 kg/m3.
%Rezultat izraziti u MW. 

r_zad2 = 1.4;
omega = 198; %unesi kako je zadano o/min
Q_zad2 = 8; % u m^3/s
alpha_izl = 29;
c_zad2 = 83; % u m/s

'Snaga pelton turbine (u MW):'

P=rho*Q_zad2*r_zad2*2*pi*omega/60*(c_zad2-r_zad2*2*pi*omega/60)*(1+cosd(alpha_izl))/10^6 

%tip zadatka 3

%Mlaz vode brzine cf = 4.5 m/s, presjeka 0.029 m2, slika, struji preko lopatice koja se giba vodoravno brzinom od cl = 1.1 m/s. Kut ? = 122o. Pretpostavljajuæi stacionarno i jednodimenzionalno strujanje, te da je voda idealna kapljevina, odredite ukupnu silu po apsolutnom iznosu kojom lopatica djeluje na mlaz vode. 
%Djelovanje sile teže zanemarite, a Zemlju smatrajte inercijskim prostorom. g = 9,81 m/s2, a ?vode = 1000 kg/m3.
%Rezultat izraziti u N. 

cf = 4.9; % u m/s
A_zad3 = 0.014; %u m^2
cl = 1.1;
alpha_zad3 = 122;

cr = cf-cl;
Fx = rho*A_zad3*cr^2*(cosd(180-alpha_zad3)+1);
Fy = rho*A_zad3*cr^2*sind(180-alpha_zad3);

'ukupnu silu po apsolutnom iznosu kojom lopatica djeluje na mlaz vode:'

F = sqrt(Fx^2+Fy^2)

%tip zadatka 4

%Okrugla cijev, prema slici, skreæe vodoravno strujanje vode za 90o uvis. Odredite velièinu sile koja spreèava pomicanje cijevi. 
%Strujanje vode smatrajte stacionarnim i jednodimenzionalnim, vodu idealnom kapljevinom, a težinu cijevi i vode u cijevi zanemarite. Iz cijevi voda struji u okolicu. Maseni je protok vode 24 kg/s, promjer cijevi 0.18 m, visina h = 0.43 m.
%g = 9,81 m/s2, a ?vode = 1000 kg/m3.

m_prot = 23; % u kg/s
D = 0.18; % promjer
h = 0.23;

Acij=(D/2)^2*pi;
c_cij = m_prot/(rho*Acij);
p1 = rho*g*h;

Fx1 = -m_prot*c_cij - p1*Acij;
Fy1 = m_prot*c_cij;

'velièinu sile koja spreèava pomicanje cijevi:'

F_ukup = sqrt(Fx1^2+Fy1^2)

%tip zadatka 5

%Odredite velièinu sile kojom voda, što stacionarno i jednodimenzionalno struji prema slici, djeluje na vodoravno položenu „t-cijev“. 
%Gubitke energije i djelovanje sile teže zanemarite. ?vode = 1000kg/m3, a g = 9,81 m/s2. Izmjereni tlak u cijevi u presjeku 1 je 500 kN/m2.
%Q1 = 0.45 m3/s
%Q2 = Q3
%d1 = 0.46 m
%d2 = 0.33 m
%d3 = 0.20 m
%Rezultat izrazite u kN.

Q1 = 0.35;
Q2 = Q1/2;
Q3 = Q1/2;
d1 = 0.52;
d2 = 0.26;
d3 = 0.16;

p1 = 500; %unos u kN

A1 = d1^2*pi/4;
A2 = d2^2*pi/4;
A3 = d3^2*pi/4;

c1 = Q1/A1;
c2 = Q2/A2;
c3 = Q3/A3;

p2 = p1*1000 + rho/2*(c1^2-c2^2);
p3 = p2 + rho/2*(c1^2-c3^2);

Fx = (p1*A1*1000 + rho*c1*Q1)/1000;
Fy = (-p2*A2 + p3*A3 - rho*c2*Q2 + rho*c3*Q3)/1000;

'velièinu sile kojom voda djeluje na vodoravno položenu „t-cijev“ (u kN):'

F_uk_cijev = sqrt(Fx^2+Fy^2)

