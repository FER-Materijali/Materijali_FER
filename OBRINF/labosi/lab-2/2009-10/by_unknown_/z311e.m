a=dtmfcode('*');
b=dtmfcode('7');
c=fft(a,205);
d=fft(b,205);
e=abs(c);
g=abs(d);
f=39:39:8000; 

figure;
stem(f,e,'k-o');
title ('Amplitudno-frekvencijska karakteristika za znak *');

figure;
stem(f,g,'r-o');
title ('Amplitudno-frekvencijska karakteristika za znak 7');

%%%%%
clear all;
a=dtmfcode('*');
b=dtmfcode('7');
c=fft(a,50);
d=fft(b,50);
e=abs(c);
g=abs(d);
f=160:160:8000; 

figure;
stem(f,e,'k-o');
title ('Amplitudno-frekvencijska karakteristika za znak *');

figure;
stem(f,g,'r-o');
title ('Amplitudno-frekvencijska karakteristika za znak 7');

%%%

clear all;
a=dtmfcode('*');
b=dtmfcode('7');
c=fft(a,500);
d=fft(b,500);
e=abs(c);
g=abs(d);
f=16:16:8000; 

figure;
stem(f,e,'k-o');
title ('Amplitudno-frekvencijska karakteristika za znak *');

figure;
stem(f,g,'r-o');
title ('Amplitudno-frekvencijska karakteristika za znak 7');
