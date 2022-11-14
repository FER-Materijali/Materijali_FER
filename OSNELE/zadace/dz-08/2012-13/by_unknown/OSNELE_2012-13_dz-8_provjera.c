#include <stdio.h>
#include <math.h>
int main(){
float a,b,c,d,e,f,g,h,i,j;
float a1,a2,b1,b2,c1,c2,d1,d2,e1,e2,f1,f2,g1,g2;
float h1,h2,i1,i2,j1,j2;
float k1,k2,l1,l2,m1,m2,n1,n2,n3,n4,o1,o2,n5,n6;
printf("Napomena, zadatak je sastavljen za napon koji je jednak 220 pod kutem 0 stupnjeva\n\n");
printf("Unesi Z2 - realni dio ");
scanf("%f",&a);
printf("Unesi Z2 - imaginarni dio ");
scanf("%f",&b);
printf("Unesi Z3 - realni dio ");
scanf("%f",&c);
printf("Unesi Z3 - imaginarni dio ");
scanf("%f",&d);
printf("Unesi Z5 - realni dio ");
scanf("%f",&e);
printf("Unesi Z5 - imaginarni dio ");
scanf("%f", &f);
printf("Unesi Z4 - realni dio ");
scanf("%f", &g);
printf("Unesi Z4 - imaginarni dio ");
scanf("%f", &h);
printf("Unesi Z1 - realni dio ");
scanf("%f", &i);
printf("Unesi Z1 - imaginarni dio ");
scanf("%f", &j);
a1=a*c-b*d;
a2=a*d+b*c;
b1=a+c;
b2=b+d;
c1=a1*b1/(b1*b1+b2*b2)+a2*b2/(b1*b1+b2*b2);
c2=(b1*a2-b2*a1)/(b1*b1+b2*b2);
d1=c1+e;
d2=c2+f;
e1=d1*g-d2*h;
e2=d1*h+d2*g;
f1=d1+g;
f2=d2+h;
g1=(e1*f1+e2*f2)/(f1*f1+f2*f2); /*Realni dio od Z2345*/
g2=(f1*e2-f2*e1)/(f1*f1+f2*f2); /*Imaginarni dio od Z2345*/
h1=g1+i; /*Realni dio od Z ekv*/
h2=g2+j; /*Imaginarni dio od Z ekv*/
i1=220*h1/(h1*h1+h2*h2); /*Realni dio ukupne struje*/
i2=-220*h2/(h1*h1+h2*h2); /*Imaginarni dio ukupne struje*/
j1=(d1*f1*i1+d1*f2*i2-d2*f1*i2+d2*f2*i1)/(f1*f1+f2*f2); /*Realni dio struje I4*/
j2=(d1*f1*i2-d1*f2*i1+d2*f1*i1+d2*f2*i2)/(f1*f1+f2*f2); /*Imaginarni dio struje I4*/
k1=(g*f1*i1+g*f2*i2-h*f1*i2+h*f2*i1)/(f1*f1+f2*f2); /*Realni dio struje I5*/
k2=(g*f1*i2-g*f2*i1+h*f1*i1+h*f2*i2)/(f1*f1+f2*f2); /*Imaginarni dio struje I5*/
l1=(a*b1*k1+a*b2*k2-b*b1*k2+b*b2*k1)/(b1*b1+b2*b2); /*Realni dio struje I3*/
l2=(a*b1*k2-a*b2*k1+b*b1*k1+b*b2*k2)/(b1*b1+b2*b2); /*Imaginarni dio struje I3*/
o1=(c*b1*k1+c*b2*k2-d*b1*k2+d*b2*k1)/(b1*b1+b2*b2); /*Realni dio struje I2*/
o2=(c*b1*k2-c*b2*k1+d*b1*k1+d*b2*k2)/(b1*b1+b2*b2); /*Imaginarni dio struje I2*/
m1=j1+l1; /*Iab - realni dio*/
m2=j2+l2; /*Iab - imaginarni dio*/
n1=sqrt(m1*m1+m2*m2);
n2=sqrt(j1*j1+j2*j2);
n3=sqrt(k1*k1+k2*k2);
n4=sqrt(i1*i1+i2*i2);
n5=sqrt(l1*l1+l2*l2);
n6=sqrt(o1*o1+o2*o2);
printf("Z3 par Z2 = %14.10f + %14.10fi\n",c1,c2);
printf("Z235 = %14.10f + %14.10fi\n",d1,d2);
printf("Z2345 = %14.10f + %14.10fi\n",g1,g2);
printf("Zekv je %14.10f + %14.10fi\n\n",h1,h2);
printf("Ukupna struja (tj struja I1) je %14.10f + %14.10fi\n",i1,i2);
printf("Struja I2 je %14.10f + 14.10fi\n",o1,o2);
printf("struja I4 je %14.10f + %14.10fi\n",j1,j2);
printf("Struja I5 je %14.10f + %14.10fi\n",k1,k2);
printf("Struja I3 je %14.10f + %14.10fi\n",l1,l2);
printf("Struja Iab (struja od I3 i I4) je %14.10f + %14.10fi\n\n",m1,m2);
printf("Struja Iab efektivno je %14.10f\n",n1);
printf("Struja I4 efektivno je %14.10f\n",n2);
printf("Struja I5 efektivno je %14.10f\n",n3);
printf("Struja I1 efektivno je %14.10f\n",n4);
printf("Struja I3 efektivno je %14.10f\n",n5);
printf("Struja I2 efektivno je %14.10f\n",n6);
return 0;
}