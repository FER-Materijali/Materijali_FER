#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

int checkepsprod(int produkcija);
int gotoepsprod(int produkcija);
int izbacivac();
int izbacitoselfprod();
int ispis();
int existepsprod();
int existjedprod();
int mrtvi();
int nedohvatljivi();
int epsilon();
int jedinicna();

int brzvr=0, brnezvr=0, brprod;
char poc, zvr[20], nezvr[20], svi[40];

struct atom{
	int atomRB;
	char lijevo;
	char desno[20];};
atom prod[100];
/*pomocne fje*/
int checkepsprod(int produkcija){
    int i=0, j=0;
    for(i=0; i<brprod; i++){
        if(prod[i].atomRB==produkcija){
            for(j=0; j<20; j++){
                if (prod[i].desno[j]=='0')return 1;}}}
    return 0;}

int existepsprod(){
    int i=0, j=0;
    for(i=0; i<brprod; i++){
        for(j=0; j<20; j++){
            if (prod[i].desno[j]=='0')return 1;}}
    return 0;}

int existjedprod(){
    int i=0, j = 0;
    for(i=0; i<brprod; i++){
        for(j=0; j<brnezvr; j++){
            if(strlen(prod[i].desno)==1 && nezvr[j]==prod[i].desno[0])return 1;}}
    return 0;}

int gotoepsprod(int produkcija){
    int i=0, j=0, k=0;
    for(i=0; i<brprod; i++){
        if(prod[i].atomRB==produkcija){
            for(j=0; j <20; j++){
                for(k=0; k<brprod; k++){
                    if(prod[k].lijevo==prod[i].desno[j])
                        if(checkepsprod(prod[k].atomRB))
                            return prod[k].lijevo;}}}}
    return 0;}

int izbacivac(){
    int i=0, j=0, k=0, x=1;
    while(x==1){
        x=0;
        for (i=0; i<brprod; i++){
            if(prod[i].desno[0]==' ' || prod[i].lijevo==' '){
                brprod--;
                for(k=0; k<brprod-i; k++){
                    for(j=0; j<20; j++){
                        prod[i+k].lijevo=prod[i+k+1].lijevo;
                        prod[i+k].desno[j]=prod[i+k+1].desno[j];
                        x=1;}}}}}}

int izbacitoselfprod(){
    int i=0;
    for(i=0; i<brprod; i++){
        if(prod[i].lijevo==prod[i].desno[0] && strlen(prod[i].desno)==1)
            prod[i].lijevo=' ';
          izbacivac();}}

int ispis(){
    int i=0;
    for (i=1; i<brprod; i++){
        printf("%d. %c -> %s\n", prod[i].atomRB, prod[i].lijevo, prod[i].desno);}
        printf("\n");}

/* gl. fje za pojednostavljenje*/
int mrtvi(){
    int i,j,k,zivizn=0, brzivihtmp=0, staribrzivih=0, brmrtvih=0, br=0, ima=0, brnovihzivih=0, brzivih=0, tmp, stop=0, check=1;
    char zivi[50], mrtvi[50], novizivi[50],;
    printf("Odbacivanje mrtvih znakova\n\n");
    printf("Zivi znakovi: ");
    for (i=0; i<strlen(zvr); i++){
        zivi[i]=zvr[i];
        printf("%c ", zivi[i]);
        brzivih++;}
    printf("\n");
/*prolaz kroz produkcije u potrazi za zivim znakovima*/
    while(check){
        for (i=1; i<brprod; i++){
            for (j=0; j<strlen(prod[i].desno); j++){
                zivizn=0;
                for (k=0; k<brzivih; k++){
                    if(prod[i].desno[j]==zivi[k]){
                        zivizn=1;}}
/*broji zive i ako su svi zivi imamo novi zivi znak*/
                if (zivizn==1) brzivihtmp++;}
            if (brzivihtmp==strlen(prod[i].desno)){
                novizivi[brnovihzivih]=prod[i].lijevo;
                brnovihzivih++;}
            brzivihtmp=0;}
        printf("Novi zivi znakovi: ");
        staribrzivih=tmp=brzivih;
        for(i=0; i<brnovihzivih; i++){
              for(j=0; j<brzivih; j++){
                    if (novizivi[i]==zivi[j]){
                        stop=1;
                        break;}}
              if (stop==1){
                    stop=0;
                    continue;}
              zivi[brzivih]=novizivi[i];
              brzivih++;}
        for(i=0; i<brzivih; i++)
              printf("%c ",zivi[i]);
        printf("\n");
        if(brzivih==staribrzivih)check=0;}
    printf("Mrtvi znakovi: ");
/*oni koji nisu zivi, mrtvi*/
    for(i=0; i<strlen(svi); i++){
          ima=0;
          for(j=0; j<brzivih; j++){
                if(svi[i]==zivi[j]) ima=1;}
          if (ima==0){
                mrtvi[brmrtvih]=svi[i];
                brmrtvih++;}}
    for(i=0; i<brmrtvih; i++) printf("%c",mrtvi[i]);
    printf("\n");
    if(brmrtvih==0) printf("Nema mrtvih znakova\n");
/*oznacavanje produkcija za odbacivanje*/
    for(i=0; i<brprod; i++){
          for(j=0; j<brmrtvih; j++){
                if(prod[i].lijevo==mrtvi[j]) prod[i].lijevo=' ';
                for(k=0; k<strlen(prod[i].desno); k++){
                      if(prod[i].desno[k]==mrtvi[j])
                            prod[i].desno[0]=' ';}}}
    for(i=0; i<brmrtvih; i++){
          br=0;
          for(j=0; j<brnezvr; j++){
                if(nezvr[j]==mrtvi[i]) continue;
                nezvr[br]=nezvr[j];
                br++;}
          brnezvr--;}
    izbacivac();
    printf("\nGramatika nakon odbacivanja mrtvih znakova:\n");
    ispis();}

int nedohvatljivi(){
    int i=0, j=0, k=0, l=0, ima=0, brdoh=1, brnedoh=0, staribrdoh=0, br=0,check=1, stop=0, tmp=0;
    char doh[50], dohtmp[50], nedoh[50];
    doh[0]=poc;
    printf("Odbacivanje nedohvatljivih znakova\n\n");
/*trazi se produkcija koja s lijeve strane ima doh. znak pa se nezavrnsi znakovi s desne strane dodaju u listu doh.*/
    while(check){
        check=1;
        for(i=0; i<brdoh; i++){
              for(j=1; j< brprod; j++){
                    if(doh[i]==prod[j].lijevo){
                        for(k=0; k<sizeof(prod[j].desno); k++){
                            for(l=0; l<brnezvr; l++){
                                if(prod[j].desno[k]==nezvr[l]){
                                    dohtmp[br++]=nezvr[l];
                                    break;}}}}}}
        staribrdoh=tmp=brdoh;
        for(i=0; i<br; i++){
              for(j=0; j<brdoh; j++){
                    if (dohtmp[i]==doh[j]){
                        stop=1;
                        break;}}
              if (stop==1){
                    stop=0;
                    continue;}
              doh[brdoh]=dohtmp[i];
              brdoh++;}
        if (staribrdoh==brdoh) check=0;}
    printf("Dohvatljivi znakovi: ");
    for(i=0; i<brdoh; i++) printf("%c ",doh[i]);
    for(i=0; i<brnezvr; i++){
          ima=0;
          for(j=0; j<brdoh; j++) if(nezvr[i] == doh[j]) ima=1;
          if (ima==0){
                nedoh[brnedoh] = nezvr[i];
                brnedoh++;}}
    printf("\nNedohvatljivi znakovi: ");
/*oni koji nisu dohvatljivi, nedohvatljivi*/
    for(i=0; i<brnedoh; i++){
          br=0;
          printf("%c ",nedoh[i]);
          for(j=0; j<brnezvr; j++){
                if(nezvr[j]==nedoh[i]) continue;
                nezvr[br]=nezvr[j];
                br++;}
          brnezvr--;}
    if(brnedoh==0)
    printf("Nema nedohvatljivih znakova\n");
    printf("\n");
    for(i=1; i<brprod; i++){
          for(j=0; j<brnedoh; j++){
                if(prod[i].lijevo==nedoh[j])
                prod[i].lijevo =' ';}}
    printf("\nGramatika nakon odbacivanja nedohvatljivih znakova:\n");
    izbacivac();
    ispis();}

int epsilon(){
    int i=0, j=0, k=0, l=0, m=0, br=0, pravi=0;
    int novibrprod=brprod, staribrprod=brprod;
    char novolijevo='1', staraprod, novaprod;
    while(existepsprod()){
    printf("\nOdbacivanje 0-produkcija\n");
/*prolazi kroz produkcije i trazi eps-prod pomocu fje checkprod*/
    for(i=1; i<staribrprod; i++){
        if(checkepsprod(prod[i].atomRB)){
            printf("\n0-produkcija: %d. %c -> %s\n",prod[i].atomRB, prod[i].lijevo, prod[i].desno);
/*provjerava s gotoepsprod koje prod imaju s desne strane lijevi znak eps-prod i stvara
2 nove prod(jednu s obrisanim znakom i drugu novu)*/
            for (j=1; j<staribrprod; j++){
                if(gotoepsprod(prod[j].atomRB)==prod[i].lijevo){
                    staraprod=prod[j].lijevo;
                    novaprod=novolijevo++;
                    prod[brprod].atomRB=brprod;
                    prod[brprod].lijevo=staraprod;
                    br = 0;
                    for(l=0; l<20; l++){
                        if(prod[j].desno[l]==prod[i].lijevo) continue;
                        prod[brprod].desno[br]=prod[j].desno[l];
                        br++;}
/*za slucaj da desno nema znaka pa postaje eps-prod*/
                            if(strlen(prod[brprod].desno)==0)
                                prod[brprod].desno[0]='0';
                                brprod++;}}
/*oznacavanje prod za brisanje*/
                  prod[i].lijevo=' ';
                  izbacivac();
                  printf("\nGramatika nakon odbacivanja 0-produkcije:\n");
                  ispis();
                  break;}}
    staribrprod = brprod;}}

int jedinicna(){
    int i=0, j=0, k=0, l=0, m=0, staribrprod=brprod, stop=0;
    printf("Odbacivanje jedinicnih produkcija\n");
/*prolazi kroz produkcije dok postoji jed. prod pomocu fje existjedprod i nalazi ih*/
    while(existjedprod()){
        stop=0;
        for(i=1; i<staribrprod; i++){
              for(j=0; j<brnezvr;j++){
                    if(strlen(prod[i].desno)==1 && nezvr[j]==prod[i].desno[0]){
                       printf("\nJedinicna produkcija: %d. %c -> %s\n",prod[i].atomRB, prod[i].lijevo, prod[i].desno);
/*trazi prod s lijevom stranom jednakoj desnoj strani jed. prod, spremaju se nove prod s
lijevom stranom jednakom lijevoj strani jed. prod i oznacavaju jed. za brisanje*/
                       for(k=1; k<staribrprod; k++){
                             if (prod[k].lijevo==nezvr[j]){
                                 prod[brprod].lijevo=prod[i].lijevo;
                                 prod[brprod].atomRB=brprod;
                                 for(l=0; l<20; l++){
                                       prod[brprod].desno[l] = prod[k].desno[l];}
                                 brprod++;}}
                       prod[i].lijevo=' ';
                       izbacivac();
                       stop=1;
                       break;}}
        if (stop==1) break;}
        staribrprod=brprod;}
    printf("\nGramatika nakon odbacivanja jedinicnih produkcija:\n");
/*poziv fje za brisanje ako je nastala prod koja ima s obje strane isti nezavrsni znak*/
    izbacitoselfprod();
    izbacivac();
    ispis();
    printf("\nPonovna provjera nedohvatljivih znakova!\n\n");
    nedohvatljivi();}

int main(int argc, char *argv[])
{
	int br=0, i=0;
	char tmp;
	FILE *dat1, *dat2;

	dat1=fopen("ulaz.txt", "r");
	dat2=fopen("izlaz.txt", "w");
	if (dat1==NULL) return 0;

/*uèitavanje i ispis zadane gramatike*/
	while(1){
        fscanf(dat1, "%c", &nezvr[br]);
        if (nezvr[br]=='{' || nezvr[br]==',' || nezvr[br]=='\t' || nezvr[br]=='\n' || nezvr[br]==' ') continue;
        brnezvr++;
        if (nezvr[br]=='}'){
            nezvr[br]='\0';
            br=0;
            brnezvr--;
            break;}
		br++;}

	while(1){
        fscanf(dat1, "%c", &zvr[br]);
        if (zvr[br]=='{' || zvr[br]==',' || zvr[br]=='\t' || zvr[br]=='\n' || zvr[br]==' ') continue;
        brzvr++;
        if (zvr[br]=='}'){
            zvr[br]='\0';
            br=0;
            brzvr--;
            break;}
		br++;}

	printf("Zadana gramatika\n");
	printf("Nezavrsni znakovi: {");
    while(1){
          if(nezvr[br]=='\0') break;
          printf("%c,", nezvr[br]);
          br++;}

	printf("}\nZavrsni znakovi: {");
    br=0;
    while(1){
          if(zvr[br]=='\0') break;
          printf("%c,", zvr[br]);
          br++;}

	while(1){
        fscanf(dat1, "%c", &tmp);
        if (tmp!='{' && tmp!=',' && tmp!=' ' && tmp!='\n' && tmp!='\t' && tmp!='}'){
            poc=tmp;
            continue;}
        if (tmp=='}') break;}
	fscanf(dat1,"%c",&tmp);
    printf ("}\nPocetni znak: {%c}\n",poc);
	br=1;

	printf("Produkcije:\n");
	while(fscanf(dat1, "%c -> %s\n", &prod[br].lijevo, &prod[br].desno)>0){
		prod[br].atomRB=br;
		printf("%d. %c -> %s\n", prod[br].atomRB, prod[br].lijevo, prod[br].desno);
		br++;
		brprod=br;}
	for(i=0; i<(strlen(zvr)+strlen(nezvr)); i++){
           if (i<strlen(zvr)) svi[i]=zvr[i];
           else svi[i]=nezvr[i-strlen(zvr)];}
    printf("\n");

/*poziv fja za pojednostavljenje*/
	mrtvi();
	nedohvatljivi();
    if(existepsprod()) epsilon();
    if(existjedprod()) jedinicna();

/*ispis pojednostavljene gramatike*/
        printf("Pojednostavljena gramatika\nNezavrsni znakovi: {");
    for(i=0; i<brnezvr; i++){
            printf("%c",nezvr[i]);
            if(i!=brnezvr-1) printf(",");
            else printf("}\n");}
    printf("Zavrsni znakovi: {");
    for(i=0; i<brzvr; i++){
            printf("%c",zvr[i]);
            if(i!=brzvr-1) printf(",");
            else printf("}\n");}
    printf("Pocetni znak: {%c}\n",poc);
    printf("Produkcije:\n");
    ispis();

/*upis u izlaz*/
    fprintf(dat2,"{");
    for(i=0; i<brnezvr; i++){
            fprintf(dat2,"%c",nezvr[i]);
            if(i!=brnezvr-1) fprintf(dat2,",");
            else fprintf(dat2,"}\n");}
    fprintf(dat2,"{");
    for(i=0; i<brzvr; i++){
            fprintf(dat2,"%c",zvr[i]);
            if(i!=brzvr-1) fprintf(dat2,",");
            else fprintf(dat2,"}\n");}
    fprintf(dat2,"{%c}\n",poc);
    for(i=1; i<brprod; i++) fprintf(dat2, "%c -> %s\n",prod[i].lijevo,prod[i].desno);

  	fclose(dat1);
	fclose(dat2);
    system("PAUSE");
    return 0;}

