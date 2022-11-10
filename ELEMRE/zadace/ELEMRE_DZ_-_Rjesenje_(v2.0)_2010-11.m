%zadani podaci :

UA=10.5; %kV
UN=10; %nazivni napon
Z=0.3+0.32i; %om/km
l1=3; %km
l2=5; %km
S1=3+2i; %MVA
S2=1.5+1i; %MVA

R1=real(Z)*l1;
X1=imag(Z)*l1;

R2=real(Z)*l2;
X2=imag(Z)*l2;

%0. iteracija

 %1. korak

  %dionica 2
S2cc=S2;

P2cc=real(S2cc);
Q2cc=imag(S2cc);

dP2=(P2cc^2+Q2cc^2)*R2/UN^2;
dQ2=(P2cc^2+Q2cc^2)*X2/UN^2;

dS2=dP2+dQ2*i;
S2c=S2cc+dS2;

P2c=real(S2c);
Q2c=imag(S2c);


%dionica 1

S1cc=S1+S2c;

P1cc=real(S1cc);
Q1cc=imag(S1cc);

dP1=(P1cc^2+Q1cc^2)*R1/UN^2;
dQ1=(P1cc^2+Q1cc^2)*X1/UN^2;

dS1=dP1+dQ1*i;
S1c=S1cc+dS1;

P1c=real(S1c);
Q1c=imag(S1c);

 %2. korak

U1=sqrt((UA-(P1c*R1+Q1c*X1)/UA)^2+((P1c*X1-Q1c*R1)/UA)^2);
delta1=atand(((P1c*X1-Q1c*R1)/UA)/(UA-(P1c*R1+Q1c*X1)/UA));

U2=sqrt((U1-(P2c*R2+Q2c*X2)/U1)^2+((P2c*X2-Q2c*R2)/U1)^2);
delta2=atand(((P2c*X2-Q2c*R2)/U1)/(U1-(P2c*R2+Q2c*X2)/U1));

%1. iteracija

%1. korak

  %dionica 2
S2cc=S2;

P2cc=real(S2cc);
Q2cc=imag(S2cc);

dP2=(P2cc^2+Q2cc^2)*R2/U2^2;
dQ2=(P2cc^2+Q2cc^2)*X2/U2^2;

dS2=dP2+dQ2*i;
S2c=S2cc+dS2;

P2c=real(S2c);
Q2c=imag(S2c);


%dionica 1

S1cc=S1+S2c;

P1cc=real(S1cc);
Q1cc=imag(S1cc);

dP1=(P1cc^2+Q1cc^2)*R1/U1^2;
dQ1=(P1cc^2+Q1cc^2)*X1/U1^2;

dS1=dP1+dQ1*i;
S1c=S1cc+dS1;

P1c=real(S1c);
Q1c=imag(S1c);

 %2. korak

U1=sqrt((UA-(P1c*R1+Q1c*X1)/UA)^2+((P1c*X1-Q1c*R1)/UA)^2);
delta1=atand(((P1c*X1-Q1c*R1)/UA)/(UA-(P1c*R1+Q1c*X1)/UA));

U2=sqrt((U1-(P2c*R2+Q2c*X2)/U1)^2+((P2c*X2-Q2c*R2)/U1)^2);
delta2=atand(((P2c*X2-Q2c*R2)/U1)/(U1-(P2c*R2+Q2c*X2)/U1));


