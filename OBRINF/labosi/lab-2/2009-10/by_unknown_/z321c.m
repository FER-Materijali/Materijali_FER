function [h]=z321c(frekv1,frekv2,fsx,n)
% f1=0.25;
% f2=0.75;
% fs=2;
if mod(n,2)==1
     error('Red filtera mora biti paran broj');
else    
f1=frekv1;
f2=frekv2;
fs=fsx;
N=n+1;

N2=floor(N/2);
w1=((2*pi)*f1)/fs;
w2=((2*pi)*f2)/fs;
i=0;
h(i+1)=(1/pi)*(1/(N2-i))*(sin(w2*(N2-i))-(sin(w1*(N2-i))));
for i=1:1:(N2-1)
    h(i+1)=(1/pi)*(1/(N2-i))*(sin(w2*(N2-i))-(sin(w1*(N2-i))));
end
for i=N2:N2:N2
    h(i+1)=(1/pi)*(w2-w1);
end
for i=(N2+1):1:(N-1)
    h(i+1)=(1/pi)*(1/(i-N2))*(sin(w2*(i-N2))-(sin(w1*(i-N2))));
end
end

    


