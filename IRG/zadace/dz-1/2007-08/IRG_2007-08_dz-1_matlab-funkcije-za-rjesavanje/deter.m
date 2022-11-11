function out=deter(n1,n2)
%funkcija deter(n1,n2) za zadani par vektora izracunava i vraca njihov
%vektorski umnozak (tocnije njegove koeficijente)

out=zeros(3,1);
out(1) = n1(2)*n2(3) - n1(3)-n2(2);
out(2) = -( n1(1)*n2(3) - n1(3)*n2(1) );
out(3) = n1(1)*n2(2) - n1(2)*n2(1);