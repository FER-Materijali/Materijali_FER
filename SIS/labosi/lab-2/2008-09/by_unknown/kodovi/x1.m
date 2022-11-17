function y=x1(t)
for i = 1:numel(t);
    if ((t(i)>=0) && (t(i)<=1) || (t(i)>= 3) && (t(i)<=4));
        y(i)=1;
    else
        y(i)=0;
    end
end
