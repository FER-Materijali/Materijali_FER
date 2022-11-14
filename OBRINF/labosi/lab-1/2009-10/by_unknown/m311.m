h=[1 -1 1];             % definiramo impulsni odziv
x=sin(pi/3*[0:30]);     % definiramo pobudu
y=conv(x,h);            % raèunamo odziv FIR sustava
stem([-1:31],y);   

x1=sin(pi/3*[0:30]);     % definiramo pobudu
y1=conv(x1,h);            % raèunamo odziv FIR sustava
stem([-1:31],y1); 

x2=sin(pi/2*[0:30]);     % definiramo pobudu
y2=conv(x2,h);            % raèunamo odziv FIR sustava
stem([-1:31],y2); 

x3=x1+x2;
y3=conv(x3,h);
stem([-1:31],y3);

h=[1 -1 1];             % definiramo impulsni odziv
x=sin(pi/3*[0:30]);     % definiramo pobudu
y=conv(x, h);           % raèunamo odziv FIR sustava
[xq,xr]=deconv(y,h);    % iz y i h raèunamo pobudu sustava
stem(xq-x);             % crtamo razliku stvarne i rekonstuirane
                        % pobude, obratite pažnju na velièinu greške
                        
                       
