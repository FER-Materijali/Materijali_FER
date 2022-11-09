// StabloOO.cpp
#include <iostream>
#include <ctime>
using namespace std;

class Stablo {

private:
  struct cvor {
    char element[15];
    cvor *lijevo;
    cvor *desno;
  };
  cvor *_glava;
  
  void Dodaj(cvor **cv, char *element);
  bool Trazi(cvor *cv, char *element);
  void Inorder(cvor *cv);
  void OslobodiMemoriju(cvor **cv);

public:
  Stablo();
  ~Stablo();
  void Dodaj(char *element);
  bool Trazi(char *element);
  void Inorder();

};

Stablo::Stablo()
{
  _glava = NULL;
}
Stablo::~Stablo()
{
  OslobodiMemoriju(&_glava);
}
void Stablo::OslobodiMemoriju(cvor **cv)
{
  if (*cv != NULL)
  {
    if ((*cv)->lijevo != NULL) OslobodiMemoriju(&(*cv)->lijevo);
    if ((*cv)->desno != NULL) OslobodiMemoriju(&(*cv)->desno);
    free (*cv);
  }
}
void Stablo::Dodaj(char* element) { 
  Dodaj(&_glava, element);
}
void Stablo::Dodaj(cvor **cv, char* element) { 
  if (*cv == NULL) {
    *cv = (cvor *) malloc (sizeof (cvor));
    if (*cv == NULL) throw "Nema dovoljno memorije!"; 
    else
    { 
      strcpy((*cv)->element, element);
      (*cv)->lijevo = NULL;
      (*cv)->desno = NULL;
    }
  }
  else
  {
    if (strcmp(element, (*cv)->element) <= 0) 
      Dodaj(&(*cv)->lijevo, element);
    else
      Dodaj(&(*cv)->desno, element);
  }
}
bool Stablo::Trazi(char* element) { 
  return Trazi(_glava, element);
}
bool Stablo::Trazi(cvor *cv, char *element)
{
  if (cv == NULL) return false;
  else
  {
    if (strcmp(element, cv->element) < 0) 
      return Trazi(cv->lijevo, element);
    else if (strcmp(element, cv->element) > 0)
      return Trazi(cv->desno, element);
  }
  return true;
}
void Stablo::Inorder()
{
  Inorder(_glava);
}
void Stablo::Inorder(cvor *cv)
{
  if (cv != NULL) {
    Inorder(cv->lijevo);
    printf("%s \n", cv->element);
    Inorder(cv->desno);
  }
}
int main()
{

  try
  {
    Stablo St;
    St.Dodaj("Ivana");
    St.Dodaj("Marin");
    St.Dodaj("Tomislav");
    St.Dodaj("Sonja");

    printf("Inorder:\n");
    St.Inorder();
    printf("Trazi element Ivana: %d\n", St.Trazi("Ivana"));
    printf("Trazi element Ana: %d\n", St.Trazi("Ana"));

  }
  catch(char *ex)
  {
    printf("%s\n", ex);
  }

  return 0;
}