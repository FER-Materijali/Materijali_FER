function y = u1(t)
%funkcija u1
for i = 1:numel(t)
%numel daje broj elemenata od t
    y(i)=0;
%funkcija je 0 svuda osim na intervalima
%[0,1] i [3,4]
    if(0 <= t(i)) & (t(i) <= 1)
        y(i)=1;
    end
    if(3 <= t(i)) & (t(i)<=4)
        y(i)=1;
    end
    
end

