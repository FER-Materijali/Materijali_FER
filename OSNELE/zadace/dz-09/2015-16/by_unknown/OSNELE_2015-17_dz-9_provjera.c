#include <stdio.h>

double u1, u2;
double r1, r2, r3;

double p;
double r_tmp, r_th, u_r;

int main(void) {

  /* unos podataka */
  printf("Upisite U1(V): ");
  scanf("%lf", &u1);

  printf("Upisite U2(V): ");
  scanf("%lf", &u2);

  printf("Upisite R1(ohm): ");
  scanf("%lf", &r1);

  printf("Upisite R2(ohm): ");
  scanf("%lf", &r2);

  printf("Upisite R3(ohm): ");
  scanf("%lf", &r3);

  /* racunanje ekvi. otpora */
  r_tmp = (r1 * r2) / (r1 + r2);
  r_th = (r_tmp * r3) / (r_tmp + r3);

  /* racunanje napona i snage */
  u_r = ((u1/r1 + u1/r2 + u1/r3 + u2/r_th) / (1./r1 + 1./r2 + 1./r3 + 1./r_th)) - u2;
  p = (u_r * u_r) / r_th;

  /* ispis rezultata */
  printf("\nRezultati:\n\n\tR = %.2f ohm\n", r_th);
  printf("\tP = %.2f W\n", p);

  return 0;
}
