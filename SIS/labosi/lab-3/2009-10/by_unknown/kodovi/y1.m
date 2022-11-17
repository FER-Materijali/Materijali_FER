function y=y1(t)


for i=1:numel(t)
    if ((t(i)>=0) && (t(i)<2))
        y(i)=2*t(i)-1;
    elseif ((t(i)>=2) && (t(i)<4))
        y(i)=-2*t(i)+7;
    else
        y(i)=0;
    end
end