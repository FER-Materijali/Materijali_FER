%Prvo unesite sve potrebne podatke tamo gdje pise Unesite…..
 fprintf(' PRORACUN TOKOVA SNAGA: ')
%PRORACUN TOKOVA SNAGA
%Unesite bazni napon i snagu,br cvorova i grana i referentni cvor  
Ub=110e3;Sb=100e6;c=6;g=10;refcv=6;
 format short;
ZO=zeros(c,c);YO=zeros(c,c);YP=zeros(c,c);Y=zeros(c,c);L=zeros(c,c);yuzd=zeros(c,c);



ZO(1,4)=(0.1940 +0.4210i);
ZO(1,5)=(0.1600 + 0.4250i);
ZO(2,3)=(0.0600 + 0.2990i);
ZO(2,5)=(0.1940 + 0.4210i);
ZO(2,6)=(0.0600 + 0.2990i);
ZO(3,5)=(0.1600 + 0.4250i);
ZO(3,6)=(0.1200 + 0.4130i);
ZO(4,5)=(0.1200 + 0.4060i);
ZO(4,6)=(0.1200 + 0.4130i);
ZO(5,6)=(0.1200 + 0.4130i);
L=zeros(c,c);yuzd=zeros(c,c);
%Unesite poprecne admitancije
YO(1,4)=2.7100e-6i;
YO(1,5)=2.8000e-6i;
YO(2,3)=3.7900e-6i;
YO(2,5)=2.7100e-6i;
YO(2,6)=3.7900e-6i;
YO(3,5)=2.8000e-6i;
YO(3,6)=2.7900e-6i;
YO(4,5)=2.8100e-6i;
YO(4,6)=2.7900e-6i;
YO(5,6)=2.8100e-6i;
%Unesite duljine vodova
L(1,4)=56;
L(1,5)=36;
L(2,3)=45;
L(2,5)=25;
L(2,6)=58;
L(3,5)=42;
L(3,6)=26;
L(4,5)=30;
L(4,6)=45; 
L(5,6)=33;

Z=ZO.*L;ypop=YO.*L;
Z
format short e;
ypop
format short;
for i=1:c
     for j=1:c
     if L(i,j)~=0
     yuzd(i,j)=1/Z(i,j);
    end
 end
end
 yuzd
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
Yabs=abs(Y);Ykut=angle(Y);
PZ=zeros(c-1,1);QZ=zeros(g-c+1,1);U=zeros(c,1);
%Unesite zadane radne snage
PZ(1,1)=-0.2;
PZ(2,1)=-0.22;
PZ(3,1)=0.3;
PZ(4,1)=-0.2;
PZ(5,1)=-0.3;
%Unesite zadane jalove snage
QZ(1,1)=-0.05;
QZ(2,1)=-0.08;
QZ(3,1)=0.15;
QZ(4,1)=-0.1;
QZ(5,1)=-0.1;
%Unesite predpostavljene napone èvorova zajedno sa naponom ref. cvora
U(1,1)=1+0i;
U(2,1)=1+0i;
U(3,1)=1+0i;
U(4,1)=1+0i;
U(5,1)=1+0i;
U(6,1)=1.0091+0i;
dP=PZ;dQ=QZ;
Uit=abs(U);Dit=angle(U); fprintf(1, '0.-ta iteracija\n ')
Uit
Dit
format short e ;
t=0;
while any(any(abs(dP)>0.0001)) || any(any(abs(dQ)>0.0001))
Pit=zeros(c-1,1);Qit=zeros(g-c+1,1);J1=zeros(c-1,c-1);J4=zeros(g-c+1,g-c+1);
dP=zeros(c-1,1);dQ=zeros(g-c+1,1);
k=0;
for i=1:c
 if i~=refcv && k<=c-1 
 k=k+1; 
for j=1:c
    Pit(k,1)=Pit(k,1)+Uit(i,1)*Uit(j,1)*Yabs(i,j)*cos(Dit(i,1)-Dit(j,1)-Ykut(i,j));
    end
end
end
Pit
k=0;
for i=1:c
 if i~=refcv && k<=c-1 
 k=k+1; 
for j=1:c
    Qit(k,1)=Qit(k,1)+Uit(i,1)*Uit(j,1)*Yabs(i,j)*sin(Dit(i,1)-Dit(j,1)-Ykut(i,j));
    end
end
end
Qit
dP=PZ-Pit;dQ=QZ-Qit;
dP
dQ
format short;
k=0;
for i=1:c
 if i~=refcv 
 k=k+1;
 for j=1:c
    if j~=i
J1(k,k)=J1(k,k)-Uit(i,1)*Uit(j,1)*Yabs(i,j)*sin(Dit(i,1)-Dit(j,1)-Ykut(i,j));
 end
   end
  end
end
m=0;
for i=1:c
 if i~=refcv  
 m=m+1;n=0;
 for j=1:c
    if j~=i  && j~=refcv
    n=n+1;
        if n==m 
    n=n+1;end
        if  n<=(c-1)
J1(m,n)=Uit(i,1)*Uit(j,1)*abs(Y(i,j))*sin(Dit(i,1)-Dit(j,1)-angle(Y(i,j)));end
   end
  end
end
end
J1
k=0;
for i=1:c
 if i~=refcv 
 k=k+1;J4(k,k)=-2*Uit(i,1)*Yabs(i,i)*sin(Ykut(i,i));
 for j=1:c
    if j~=i
J4(k,k)=J4(k,k)+Uit(j,1)*Yabs(i,j)*sin(Dit(i,1)-Dit(j,1)-Ykut(i,j)); end
   end
  end
end
m=0;
for i=1:c
 if i~=refcv  
 m=m+1;n=0;
 for j=1:c
    if j~=i  && j~=refcv
    n=n+1;
        if n==m 
    n=n+1;end
        if  n<=(c-1)
J4(m,n)=Uit(i,1)*Yabs(i,j)*sin(Dit(i,1)-Dit(j,1)-Ykut(i,j));end
   end
  end
end
end
J4
format short e;
Ucv=Uit;Dcv=Dit;
dU=inv(J4)*dQ;dD=inv(J1)*dP;dU
dD
if all(all(abs(dP)<0.0001)) && all(all(abs(dQ)<0.0001)),break,end
Upom=Uit;Upom(refcv,:)=[];Upom=Upom+dU;
Dpom=Dit;Dpom(refcv,:)=[];Dpom=Dpom+dD;
k=0;
for i=1:c
 if i~=refcv
 k=k+1;
 Uit(i,1)=Upom(k,1);Dit(i,1)=Dpom(k,1);
 end
end 
t=t+1;
fprintf(1, '%d.  iteracija\n ',t)
Uit
format short e
Dit
end
fprintf(1, 'Konacni naponi cvorista u [p.u] i u [V]\n ')
for i=1:c
 U(i,1)=complex(Uit(i,1)*cos(Dit(i,1)),Uit(i,1)*sin(Dit(i,1)));
end

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
Sij=Sij*1.0e-6;Sij
dSij=zeros(c,c);
for i=1:c
 for j=1:c
   if i~=j && i<j
         dSij(i,j)=(Sij(i,j)+Sij(j,i));
   end
 end
end
dSij
snaga_reg_el=0;
for i=1:c
  snaga_reg_el= snaga_reg_el+Sij(refcv,i);
end
fprintf('Snaga regulacijske elektrane u MVA: ')
 snaga_reg_el
fprintf(' PRORACUN KRATKOG SPOJA:\n\n ')

%PRORACUN KRATKOG SPOJA
%Unesite generatorski cvor i pocetne adm. gen u postocima te cvor u kojem je nastao k.s.
gencv=3; kscv=4; 
xdref=20;xdgen=18;

ydt=zeros(c,1);format short;
%Unesite snage cvorista tereta(za ref cv staviti 0)
St=zeros(c,1);
St(1,1)=0.2+0.05i;
St(2,1)=0.22+0.08i;
St(3,1)=0.3+0.05i;
St(4,1)=0.2+0.1i;
St(5,1)=0.3+0.1i;
St(6,1)=0;
%Unesite nazivne snage gen u ref cv i gen cv
Snref=1;Sngen=1;
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
Y
fprintf('Matric impedancija za kratki spoj: ')
Z=inv(Y)
Im=zeros(6,1);
Im(kscv,1)=-U(kscv,1)/Z(kscv,kscv);
fprintf('Vektor struje kvara: ')
Im

fprintf('Vektor napona bolesne mreze: ')
Ubl=U+Z*Im
UblkV=Ubl*Ub*1.0e-3
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
 I 
fprintf('Struje kroz terete: ')
Ito=zeros(c,1);
for i=1:c
  if i==gencv
      Ito(i,1)=-Ubl(i,1)* (conj(St(i,1)))/((abs(U(i,1)) ^2));
  else
       Ito(i,1)=-Ubl(i,1)*ydt(i,1);
  end
end  
Ito 
 fprintf('Struje koje daju generatori: ')
Igref=0;Iggen=Ito(gencv,1);
for i=1:c
   Igref=Igref+I(refcv,i);
end
for i=1:c
   Iggen=Iggen+I(gencv,i);
end
Igref
Iggen
fprintf('Bazna struja: ')
Ib=(Sb)/(Ub*sqrt(3))
fprintf('Stvarna struja k.s. i struje gen.: ') 
Iks= Im(kscv,1)*Ib
Igref=Igref*Ib
Iggen=Iggen*Ib







   
          






