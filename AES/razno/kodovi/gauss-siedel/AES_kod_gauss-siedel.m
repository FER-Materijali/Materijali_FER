%Prvo unesite sve potrebne podatke tamo gdje pise Unesite…..
 fprintf(' PRORACUN TOKOVA SNAGA: ')
%PRORACUN TOKOVA SNAGA
%Unesite bazni napon i snagu,br cvorova i grana i referentni cvor  
Ub=110e3;Sb=100e6;c=6;g=10;refcv=2;
 format short;
ZO=zeros(c,c);YO=zeros(c,c);YP=zeros(c,c);Y=zeros(c,c);
%Unesite impedancije grana
ZO(1,2)=(0.1600+0.4250i);
ZO(1,3)=(0.0600+0.2990i);
ZO(1,5)=(0.1940+0.4210i);
ZO(1,6)=(0.1200+0.4060i);
ZO(2,3)=(0.1200+0.4130i);
ZO(2,4)=(0.1600+0.4250i);
ZO(2,5)=(0.1940+0.4210i);
ZO(3,6)=(0.1200+0.4130i);
ZO(4,5)=(0.1200+0.4060i);
L=zeros(c,c);yuzd=zeros(c,c);
%Unesite poprecne admitancije
YO(1,3)=2.8000e-6i;
YO(1,4)=3.7900e-6i;
YO(1,5)=2.7100e-6i;
YO(1,6)=2.8100e-6i;
YO(2,3)=2.7900e-6i;
YO(2,4)=2.8000e-6i;
YO(2,5)=2.7100e-6i;
YO(3,6)=2.7900e-6i;
YO(4,5)=2.8100e-6i;
%Unesite duljine vodova
L(1,3)=26;
L(1,4)=52;
L(1,5)=53;
L(1,6)=58;
L(2,3)=30;
L(2,4)=27;
L(2,5)=28;
L(3,6)=48; 
L(4,5)=37; 
Z=ZO.*L;ypop=YO.*L;
Z1 = mat2str(Z,9)
format short e;
ypop1 = mat2str(ypop,9)
ypoppola=ypop/2
format short;
for i=1:c
     for j=1:c
     if L(i,j)~=0
     yuzd(i,j)=1/Z(i,j);
    end
 end
end
 yuzd1 = mat2str(yuzd,9)
for i=1:c
     for j=1:c
     if L(i,j)~=0
     ZO(i,j)=(Ub ^2)/(ZO(i,j)*L(i,j)*Sb);
    YO(i,j)=(YO(i,j)*L(i,j)*(Ub^2))/(2*Sb);
    end
 end
end
for i=1:c
    Y(i,i)=sum(ZO(i,:)) + sum(ZO(:,i)) + sum(YO(i,:)) + sum(YO(:,i));
   end
for i=1:c
     for j=1:c
       if i<j
     
       Y(i,j)=-ZO(i,j);
       end
       if i>j
       Y(i,j)=-ZO(j,i);
       end
    end
   end
Y
ypoppu=(ypoppola*Ub^2)/Sb
yuzdpu=(yuzd*Ub^2)/Sb
Yabs=abs(Y);Ykut=angle(Y);
P=zeros(c,1);Q=zeros(c,1);U=zeros(c,1);
%Unesite zadane radne snage(za ref cv unesite nulu;u gen cv unesti zbroj)
P(1,1)=-0.25;
P(2,1)=0;
P(3,1)=-0.20;
P(4,1)=0;
P(5,1)=-0.40;
P(6,1)=0.2;
%Unesite zadane jalove snage
Q(1,1)=-0.05i;
Q(2,1)=0i;
Q(3,1)=-0.05i;
Q(4,1)=0i;
Q(5,1)=-0.15i;
Q(6,1)=0i;
%Unesite predpostavljene napone èvorova zajedno sa naponom ref. cvora
U(1,1)=1+0i;
U(2,1)=1+0i;
U(3,1)=1+0i;
U(4,1)=1+0i;
U(5,1)=1+0i;
U(6,1)=1+0i;
KL=zeros(c,1);YP=zeros(c,c);
for p=1:c
  KL(p,1)=(P(p,1)-Q(p,1))/Y(p,p);
end
KL1 = mat2str(KL,9)
for p=1:c
 if p==refcv 
 p=p+1;
 end
for i=1:c
 YL(p,i)=Y(p,i)/Y(p,p);
end
end
YL1 = mat2str(YL,9) 
Uit=zeros(c,1); dU=zeros(c,1);dU=U;

%Unesite koeficijent ubrzanja alfa
alfa=1.4;
t=0; fprintf(1, '0.-ta iteracija\n ')
U1 = mat2str(U,9)
dU1 = mat2str(dU,9)
dU(refcv,1)=0;
while any(any(abs(dU)>0.0001)) 
  Uubrzani=zeros(c,1); Uit=U;p=1;
  for k=1:c-1
      if p==refcv 
    p=p+1;
    end
  U(p,1)=KL(p,1)/(conj(Uit(p,1)));
   i=1;
  for j=1:c-1
    if i==p   
    i=i+1;
    end
    if Uubrzani(i,1) ~= 0
      U(p,1)=U(p,1)-YL(p,i)*Uubrzani(i,1);
    else
      U(p,1)=U(p,1)-YL(p,i)*Uit(i,1);
    end
   i=i+1;
  end
  dU(p,1)=U(p,1)-Uit(p,1);
  Uubrzani(p,1)=Uit(p,1)+alfa*dU(p,1);p=p+1;
 end
  t=t+1;
  fprintf(1, '%d.  iteracija\n ',t)
  U1 = mat2str(U,9)
  dU1 = mat2str(dU,9)
  Uubrzani1 = mat2str(Uubrzani,9)
  end

fprintf(1, 'Konacni naponi cvorista u [p.u] i u [V]\n ')
format long
U
format short e
Uv=U*110e003
Sij=zeros(c,c); dS=zeros(c,c);Uvk=conj(Uv);yuzdk=conj(yuzd);ypopk=conj(ypop);
for i=1:c
 for j=1:c
   if i~=j && i<j
         Sij(i,j)=Uv(i,1)*(Uvk(i,1)-Uvk(j,1))*yuzdk(i,j)+ ((abs(Uv(i,1))^2)*(ypopk(i,j)/2));
   end
   if i~=j && i>j  
          Sij(i,j)=Uv(i,1)*(Uvk(i,1)-Uvk(j,1))*yuzdk(j,i)+ (abs(Uv(i,1))^2)*(ypopk(j,i)/2);       
  end
 end
end
format short
fprintf('Tokovi snage po vodovima i gubici snage u MVA: ')
Sij=Sij*1.0e-6;
Sij1 = mat2str(Sij,9)
dSij=zeros(c,c);
for i=1:c
 for j=1:c
   if i~=j && i<j
         dSij(i,j)=(Sij(i,j)+Sij(j,i));
   end
 end
end
dSij1 = mat2str(dSij,9)
snaga_reg_el=0;
for i=1:c
  snaga_reg_el= snaga_reg_el+Sij(refcv,i);
end
fprintf('Snaga regulacijske elektrane u MVA: ')
 snaga_reg_el1 = mat2str(snaga_reg_el,9)
fprintf(' PRORACUN KRATKOG SPOJA:\n\n ')

%PRORACUN KRATKOG SPOJA
%Unesite generatorski cvor i pocetne adm. gen u postocima te cvor u kojem je nastao k.s.
gencv=6; kscv=3; 
xdref=20;xdgen=20;

ydt=zeros(c,1);format short;
%Unesite snage cvorista tereta(za ref cv staviti 0)
St=zeros(c,1);
St(1,1)=0.25+0.05i;
St(2,1)=0+0i;
St(3,1)=0.2+0.05i;
St(4,1)=0+0i;
St(5,1)=0.40+0.15i;
St(6,1)=0.40+0.20i;
%Unesite nazivne snage gen u ref cv i gen cv
Snref=1.2;Sngen=1.2;
for i=1:c
      if i==refcv
          ydt(i,1)=((-100*Snref)/(xdref))*sqrt(-1);
    elseif i==gencv
          ydt(i,1)=(conj(St(i,1)))/((abs(U(i,1)) ^2))+(((-100*Sngen)/(xdgen))*sqrt(-1));
    else
           ydt(i,1)=(conj(St(i,1)))/((abs(U(i,1)) ^2));
    end
end
fprintf('Admitancije generatora i tereta: ')
ydt
for i=1:c
  Y(i,i)=Y(i,i)+ydt(i,1);
end
fprintf('Matrica admitancija za kratki spoj: ')
Y1 = mat2str(Y,9)
fprintf('Matric impedancija za kratki spoj: ')
Z=inv(Y)
Z1 = mat2str(Z,9)
Im=zeros(6,1);
Im(kscv,1)=-U(kscv,1)/Z(kscv,kscv);
fprintf('Vektor struje kvara: ')
Im1 = mat2str(Im,9)

fprintf('Vektor napona bolesne mreze: ')
Ubl=U+Z*Im
UblkV=Ubl*Ub*1.0e-3
Ubl1 = mat2str(Ubl,9)
UblkV1 = mat2str(UblkV,9)
fprintf('Struje u vodovima: ')
I=zeros(c,1);
for i=1:c
    for j=1:c
      if i~=j && i<j
        I(i,j)=((Ubl(i,1)-Ubl(j,1))*ZO(i,j))+((Ubl(i,1)*YO(i,j))/2);
      end
      if i~=j && i>j
         I(i,j)=((Ubl(i,1)-Ubl(j,1))*ZO(j,i))+((Ubl(i,1)*YO(j,i))/2);
      end
     end
end
 I1 = mat2str(I,9) 
fprintf('Struje kroz terete: ')
Ito=zeros(c,1);
for i=1:c
  if i==gencv
      Ito(i,1)=-Ubl(i,1)* (conj(St(i,1)))/((abs(U(i,1)) ^2));
  else
       Ito(i,1)=-Ubl(i,1)*ydt(i,1);
  end
end  
Ito1 = mat2str(Ito,9) 
 fprintf('Struje koje daju generatori: ')
Igref=0;Iggen=Ito(gencv,1);
for i=1:c
   Igref=Igref+I(refcv,i);
end
for i=1:c
   Iggen=Iggen+I(gencv,i);
end
Igref1 = mat2str(Igref,9)
Iggen1 = mat2str(Iggen,9)
fprintf('Bazna struja: ')
Ib=(Sb)/(Ub*sqrt(3))
fprintf('Stvarna struja k.s. i struje gen.: ') 
Iks= Im(kscv,1)*Ib
Igref=Igref*Ib
Iggen=Iggen*Ib
Iks1 = mat2str(Iks,9)
Igref1 = mat2str(Igref,9)
Iggen = mat2str(Iggen,9)






   
          






