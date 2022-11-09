// KomunikacijaSFunkcijama.c
void z0 (int tri, int sedam) { // call by value
  int pom;
  pom = tri;
  tri = sedam;
  sedam = pom;
}
void z1 (int *tri, int *sedam) { // call by reference
 int pom;
  pom = *tri;
  *tri = *sedam;
  *sedam = pom;
}
void z2 (int *tri, int *sedam) { // lokalna zamjena adresa
  int *pom;
  pom = tri;
  tri = sedam;
  sedam = pom;
}
int main () {
  int tri=3, sedam=7;

  z0 (tri, sedam);
  z1 (&tri, &sedam);
  z2 (&tri, &sedam);

  return 0;
}
                                                               
