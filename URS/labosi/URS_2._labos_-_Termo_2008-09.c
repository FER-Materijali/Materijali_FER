/*************************************************************************/
/*                             TERMOMETAR                                */
/*************************************************************************/

/*=======================================================================*/
/*                                .h                                     */
/*=======================================================================*/

#include  <reg51.h>

/*=======================================================================*/
/*                        globalne varijable                             */
/*=======================================================================*/

sbit DQ  =P1^0;
sbit CLK =P1^1;
sbit RST_=P1^2;

/*=======================================================================*/
/*           Funkcija za upis 8 bitne rijeci u DS1620                    */
/*=======================================================================*/

void slanje8(unsigned char podatak)
{
unsigned char data i;

for(i=0;i<8;i++)   /* petlja za upis podatka u DS1620 bit po bit, */
   {               /* pocevsi od najmanje znacajnog (LSB)         */
   CLK=0;
   DQ=(bit)(podatak&(1<<i));       
   CLK=1;          /* rastuci brid za upis i-tog bita */
   }
}


/*=======================================================================*/
/*     Funkcija za upis u konfiguracijski registar sklopa DS1620         */
/*=======================================================================*/

void PisiControl(unsigned char rijec)
{
unsigned int data j;
RST_=0;
RST_=1;
slanje8(0x0C);
slanje8(rijec);
RST_=0;
for(j=0;j<700;j++);     /* Pauza od oko 10 ms. Ovo je samo ilustrcija. */
                        /* U praksi se ovo NIKAD ovako ne izvodi.      */
}


/*=======================================================================*/
/*           Funkcija za upis narebe bez argumenta u DS1620              */
/*=======================================================================*/

void PisiKomandu(unsigned char komanda)
{
RST_=0;
RST_=1;
slanje8(komanda);
RST_=0;
}


/*=======================================================================*/
/*            Funkcija za citanje 9 bitne rijeci iz DS1620               */
/*=======================================================================*/

int CitajTemp(void)
{
int data podatak=0;          /* temperatura * 2 */
unsigned char data i;        /* brojac u petlji */

RST_=0;

RST_=1;

slanje8(0xAA);      /* naredba za citanje temperature */
DQ=1;               /* priprema za citanje iz DS1620 */

for(i=0;i<9;i++)    /* petlja za citanje podatka iz DS1620 bit po bit, */
   {                /* pocevsi od najmanje znacajnog (LSB) */
   CLK=0;           /* padajuci brid  CLK koji postavlja podatak na DQ */
   if(DQ) podatak=podatak+(1<<i); 
   CLK=1;           /* uklanja podatak sa DQ */
   }

RST_=0;

return(podatak);
}
