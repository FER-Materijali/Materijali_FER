#include <stdio.h>
#include <stdlib.h>
char generirajZnak(int vrsta){
  int x;
  char c;
  if(vrsta == 1){
    x = rand() % 52;
	if(x < 26){
	  c = 65 + x;
	} else {
	  c = 97 + x - 26;
	}
  }
  if(vrsta == 2){
    x = rand() % 10;
	c = 48 + x;
  }
  if(vrsta == 3){
    x = rand() % 3;
	if(x == 0){
	  c = '!';
	} else if(x == 1){
	  c = '?';
	} else {
	  c = '/';
	}
  }
  return c;
}

void generirajLozinku(int ns, int nb, int ni, char *izl){
  int brojac1 = 0, brojac2 = 0, brojac3 = 0, i = 0, x, y;
  char c;
  while(i < ns + nb + ni){  
	x = rand() % 3 + 1;
	c = generirajZnak(x);
	if(x == 1){
	  if(brojac1 < ns){
		y = rand() % (ns + nb + ni);
		if(*(izl + y) == 0){
		  *(izl + y) = c;
	      brojac1++;
	      i++;
		}
	  }
	}
	if(x == 2){
	  if(brojac2 < nb){
		y = rand() % (ns + nb + ni);
		if(*(izl + y) == 0){
		  *(izl + y) = c;
		  brojac2++;
          i++;		  
		}
	  }
	}
	if(x == 3){
		if(brojac3 < ni){
			y = rand() % (ns + nb + ni);
			if(*(izl + y) == 0){
				*(izl + y) = c;
				brojac3++;
				i++;
			}
		}
	}
}     
}