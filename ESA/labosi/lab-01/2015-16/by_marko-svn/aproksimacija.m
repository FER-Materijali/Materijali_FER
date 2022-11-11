for i=1:11
    st{i} = polyfit(R,T,i);  %trazenje polinoma i-tog stupnja st{i}
    tA{i}= polyval(st{i},R); %racunanje vrijdnosti temperature                                      
                             %iz aproksimiranih polinoma    
end;

for i=1:11     %izracun srednje pogreske interpolacije za svaki polinom
    err(i) = 0;
    for j=1:length(T)
        err(i) = err(i) + abs(T(j)-tA{i}(j));
    end;
    err(i) = err(i)/length(T);
end;

    figure('units','normalized','position',[0 0 1 1]); %full screen

for i=1:11 %iscrtavanje 11 razlicitih aproksimacija zajedno 
           %s pravim vrijednostima kako bismo ih mogli usporediti
     
    subplot(3,4,i);
    plot(R,T,'r');
    hold;
    plot(R,tA{i});
    grid;
    xlabel('R');
    ylabel('T[R]');
    title(strcat('Polinom n=',int2str(i)));
end;

    figure('units','normalized','position',[0 0 1 1]); %full screen
    
    stem([1:11],err,'r');           %iscrtavanje pogresaka interpolacije
    grid;                           %za svaki stupanj polinoma
    xlabel('n');
    ylabel('err[n]');
    title('Pogreska interpolacije');
    for i=1:11
        text(i,err(i),num2str(err(i))); %dodavanje numerickih podataka
    end;                                %svakoj tocki
    
    