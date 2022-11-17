t=[1:1/8000:5]';
x=sin(2*pi*t.*t);
x=x.*triang(length(x));
plot(t,x)
hold on
plot(t, triang(length(x)),':');
plot(t, -triang(length(x)),':');