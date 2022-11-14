#include<stdio.h>
int main (void) {
int n, br, i=0, zn[3];
do {
	scanf("%d", &n);
} while (n<100 || n>999);
br=n;
while (n!=0) {
    zn[i++]=n%10;
	n/=10;
}
n=100*zn[0]+10*zn[1]+zn[2];
if (n>br) {
	printf("Broj %d veci je od ucitanog broja", n);
} else if (n<br) {
	printf("Broj %d manji je od ucitanog broja", n);
} else {
	printf("Broj %d jednak je ucitanom broju", n);
}
return 0;
}

/* #include<stdio.h>
int main (void) {
int n, m, br=0;
do {
	scanf("%d", &n);
} while (n<100 || n>999);
m=n;
while (n!=0) {
    br*=10;
	br+=(n%10);
	n/=10;
}
if (br>m) {
	printf("Broj %d veci je od ucitanog broja", br);
} else if (br<m) {
	printf("Broj %d manji je od ucitanog broja", br);
} else {
	printf("Broj %d jednak je ucitanom broju", br);
}
return 0;
}   */