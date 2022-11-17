function y = u2(t)
%funckija u2
for i=1:numel(t)
%numel vraca broj elemenata od t
    y(i)=0;
%funkcija je 0 svuda osim na intervalima
%[-5,-4], [-2,-1] i [1,2]
    if(-5<=t(i))&(t(i)<=-4)
        y(i)=1;
    end
    if(-2<=t(i))&(t(i)<=-1)
        y(i)=-1;
    end
    if(1<=t(i))&(t(i)<=2)
        y(i)=-2;
    end

end

