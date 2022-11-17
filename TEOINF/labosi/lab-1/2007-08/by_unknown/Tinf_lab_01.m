 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% TINF - Markovljeva izvorišta %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% 1.1 - funkcija "ti" - spremiti kao .m file
% function z=ti(x,y,q)
% if (nargin<3)
% q=rand(y);
% end
% for i=1:y
% q(i,:)=cumsum(q(i,:));
% q(i,:)=q(i,:)/q(i,y);
% end
% z=zeros(x,1);
% z(1)=1;
% for i=2:x% s=rand(1);
% s1=find(q(z(i-1),:)>s);
% z(i)=s1(1);
% end


clear
clc

% 2.1
q=rand(1,3);
disp(['q=[' num2str(q) '].']);
pause
% 2.2
q=q./sum(q);
disp(['q=[' num2str(q) '].']);
pause
% 2.3
z=ti(1000,3,[q;q;q]);
% 2.4
disp(['Srednja vrijednost je: ' num2str(mean(z)) '.']);
disp(['Standardna devijacija je: ' num2str(std(z)) '.']);
pause
% 2.5
hist(z,3);
pause
for i=1:3
disp(['p(' num2str(i) ')=' num2str(size(find(z==i),1)/1000) '.']);
end
clear i
pause
% 2.6
disp(['H(izv.)=' num2str(-sum(q.*log2(q))) ' [bita/simbolu]']);
pause

clear
clc

% 3.1
z=ti(1000,4);
% 3.2
p=hist(z,4)./1000;
disp(['p=[' num2str(p) ']']);
pause
% 3.3
for i=1:4
for j=1:4
q(i,j)=0;
for k=2:1000
if((z(k)==j)&(z(k-1)==i))
q(i,j)=q(i,j)+1;
end
end
q(i,j)=q(i,j)./size(find(z==i),1);
end
end
clear i j k
disp('q=p(xj|yi)=[');
disp(q);
disp('].');
pause
% 3.4
disp(['pxq=[' num2str(p*q) '].']);
pause
% 3.5
disp(['Srednja vrijednost je: ' num2str(mean(z)) '.']);
disp(['Standardna devijacija je: ' num2str(std(z)) '.']);
pause
% 3.6
disp(['p´=[' num2str(q(1,:)) '].']); % formula (7) iz pripreme
disp(['p´´=[' num2str(q(1,:)*q) '].']); % formula (8) iz pripreme
pause
% 3.8
for i=1:4
for j=1:4
pq(i,j)=p(i)*q(i,j);
end
end
py=sum(pq);
clear i j
disp(['H(izv.)=' num2str(-sum(py.*log2(py))) ' [bita/simbolu]']);

clear
clc