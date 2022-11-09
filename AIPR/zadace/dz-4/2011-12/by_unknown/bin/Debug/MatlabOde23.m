function MatlabOde23 
t0=0;
tkraj=1;
y0=[1 ;-2 ];
[t2, y2] = ode23(@datMatSustava, [t0, tkraj], y0);
subplot(3,1,3), plot (t2,y2); 
xlabel('Vrijeme'); 
ylabel('Vrijednost varijabli stanja'); 
title ('ode23', 'FontWeight','bold', 'Color','blue');
axis([0 1 min(min(y2)) max(max(y2))])
