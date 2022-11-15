% Ulazne Varijable %
Un=220e3;   %nazivni napon%
U1=215e3;   %zadano pogonsko stanje%
S1a=212e6;   %prividna snaga%
cosfi=0.947; %faftor snage%
R=0.07;    %rezistencija%
X=0.359;    %reaktancija%
B=3.202e-6; %susceptancija%
L=113;       %duljina voda%

%=====Izraèun konstante prodiranja y i karakteristiène impedancije Zc=====%
Z=R+X*1i;
Y=1i*B;
y=sqrt(Z*Y);
Zc=sqrt(Z/Y);

%a)prilike na kraju voda i gubitci snage za zadano pogonsko stanje%
    %definiranje varijabli za prijenosne jednadžbe%
        x=L;
        V1=U1/sqrt(3);
        %raèunanje snage u kompleksnom obliku%
            P1=S1a*cosfi;
            S1=P1-sqrt(S1a^2-P1^2)*1i;  %opterecenje ind "+" kap "-"%
        I1=conj(S1/(3*V1));
    %prijenosne jednadžbe%
        V2=V1*cosh(y*x)-Zc*I1*sinh(y*x);
            %graf linijski napon%
            LIN=linspace(0,L,1000);
            U2p=abs((V1*cosh(y*LIN)-Zc*I1*sinh(y*LIN))*sqrt(3)*10^-3);
            subplot(321),plot(LIN,U2p),
                grid on,
                xlabel('Dužina voda [Km]','FontSize',9)
                ylabel('Napon u pogonskom stanju[KV]','FontSize',9);
        I2=I1*cosh(y*x)-(V1/Zc)*sinh(y*x);
            %graf struja%
            I2p=abs(I1*cosh(y*LIN)-(V1/Zc)*sinh(y*LIN));
            subplot(322), plot(LIN,I2p),
                grid on,
                xlabel('Dužina voda [Km]','FontSize',9)
                ylabel('Struja u pogonskom stanju [A]','FontSize',9);
    U2=V2*sqrt(3);
    %snaga na kraju voda%
        S2=3*V2*conj(I2);
    %gubitak snage%
    DS=S1-S2;
%ispis%
U1pog=abs(U1)*10^-3;
I1pog=abs(I1);
U2pog=abs(U2)*10^-3;
I2pog=abs(I2);
DSpog=abs(DS)*10^-6;

%b)prazni hod (pogonski napon na poèetku voda)%
    I2=0; %otvorene stezaljke%
    %prijenosne jednadžbe%
        I1=(V1*sinh(y*x))/(Zc*cosh(y*x)); %struja praznog hoda%
        V2=V1*cosh(y*x)-Zc*I1*sinh(y*x);
        %graf linijski napon%
            U2p=abs((V1*cosh(y*LIN)-Zc*I1*sinh(y*LIN))*sqrt(3)*10^-3);
            subplot(323),plot(LIN,U2p),
                grid on,
                xlabel('Dužina voda [Km]','FontSize',9)
                ylabel('Napon u PH [KV]','FontSize',9);
        I2=I1*cosh(y*x)-(V1/Zc)*sinh(y*x);
        %graf struja%
            I2p=abs(I1*cosh(y*LIN)-(V1/Zc)*sinh(y*LIN));
            subplot(324), plot(LIN,I2p),
                grid on,
                xlabel('Dužina voda [Km]','FontSize',9)
                ylabel('Struja u PH I2[A]','FontSize',9)
    %napon na kraju neoptereæenog voda poraste Ferantijev efekt%
        U2=V2*sqrt(3);
    %snaga na kraju voda je nula%
        S2=0;
    S1=3*V1*conj(I1);
    %gubitak snage%
    DS=S1-S2;
%ispis%
U1ph=abs(U1)*10^-3;
I1ph=abs(I1);
U2ph=abs(U2)*10^-3;
I2ph=abs(I2);
DSph=abs(DS)*10^-6;

%c) Vod sa zakljuèenom karakteristiènom impedancijom Zc%
    %prva prijenosna jednadžba%
        V2=V1*exp(-y*x);
        %graf linijski napon%
            U2p=abs(V1*exp(-y*LIN)*sqrt(3)*10^-3);
                subplot(325),plot(LIN,U2p),
                    grid on,
                    xlabel('Dužina voda [Km]','FontSize',9)
                    ylabel('Napon na zakljuèanom [KV]','FontSize',9);
    U2=V2*sqrt(3);
    %uvjeti na kraju voda%
        I2=V2/Zc;
    %druga prijenosna jednadžba%
        I1=I2*exp(y*x);
        %graf struja%
            I2p=abs(I1./(exp(y*LIN)));
            subplot(326), plot(LIN,I2p),
                grid on,
                xlabel('Dužina voda [Km]','FontSize',9)
                ylabel('Struja na zakljuèenom [A]','FontSize',9)
    %izraèun sanga%
        S1=3*V1*conj(I1);
        S2=3*V2*conj(I2);
    %gubitak snage%
    DS=S1-S2;
%ispis%
U1zak=abs(U1)*10^-3;
I1zak=abs(I1);
U2zak=abs(U2)*10^-3;
I2zak=abs(I2);
DSzak=abs(DS)*10^-6;

%d)Duljina voda za 5% veæi napon izlaza u PH%
X=abs(acosh(1.05)/y);




