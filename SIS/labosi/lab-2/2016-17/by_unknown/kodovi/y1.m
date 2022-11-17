function y = y1(t)
%funkcija y1
for i=1:numel(t)
%numel vraca broj elemenata od t
    y(i)=0;  
%funkcija je 0 svuda osim na intervalu [0,4]
    if(0<=t(i))&(t(i)<=4)
        y(i)=3-t(i);
    end
    
end

