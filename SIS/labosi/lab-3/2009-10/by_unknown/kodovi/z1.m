function y=x2(t)


for i=1:numel(t)
    if ((t(i)>=-3) && (t(i)<=-2))
        y(i)=2;
    elseif ((t(i)>=0) && (t(i)<=1))
        y(i)=1;
    elseif ((t(i)>=3) && (t(i)<4))
        y(i)=-1;
    else
        y(i)=0;
    end
end