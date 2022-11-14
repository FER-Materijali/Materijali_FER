#include <stdio.h>
#include <conio.h>
#define maxstup 20
#define maxred 20
int main () {
    int n,i,j,redx=0,stupx=0,dijagx=0,dijag2x=0,redo=0,stupo=0,dijago=0,dijag2o=0;
    char polje[maxred][maxstup];
       
    scanf("%d",&n);
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            scanf("%c",&polje[i][j]);
            }
       }
    
    for (i=0; i<n; i++) {
         for (j=0;j<n;j++) {
             if(polje[i][j]=='X'){ 
                                   redx+=1;
                                   if (redx==n) {
                                               printf("X");
                                               goto nastavak;
                                               }
                                               }
             else redx=0;
             if(polje[j][i]=='X'){
                                 stupx+=1;
                                 if (stupx==n) {
                                              printf("X");
                                              goto nastavak;
                                              }
                                              }
             else stupx=0;
             
             if (polje[j][j]=='X') {
                                   dijagx+=1;
                                   if(dijagx==n) {
                                                printf("X");
                                                goto nastavak;
                                                }
                                                }
             else dijagx=0;
             
             if (polje[j][n-1-j]=='X') {
                                       dijag2x+=1;
                                       if (dijag2x==n){
                                                      printf("X");
                                                      goto nastavak;
                                                      }
                                                      }
             else dijag2x=0;
             
             if(polje[i][j]=='O'){ 
                                   redo+=1;
                                   if (redo==n) {
                                               printf("O");
                                               goto nastavak;
                                               }
                                               }
             else redo=0;
             if(polje[j][i]=='O'){
                                 stupo+=1;
                                 if (stupo==n) {
                                              printf("O");
                                              goto nastavak;
                                              }
                                              }
             else stupo=0;
             
             if (polje[j][j]=='O') {
                                   dijago+=1;
                                   if(dijago==n) {
                                                printf("O");
                                                goto nastavak;
                                                }
                                                }
             else dijago=0;
             
             if (polje[j][n-1-j]=='O') {
                                       dijag2o+=1;
                                       if (dijag2o==n){
                                                      printf("O");
                                                      goto nastavak;
                                                      }
                                                      }
             else dijag2o=0;
             
             }
             }
             if (redx<n && stupx<n && dijagx<n && dijag2x<n && stupo<n && redo<n && dijago<n && dijag2o<n) {
                        printf("-");
                        }
             nastavak:
             getch();
             return 0;
             }
               
             
             
             
             
             
             
             
             
             
             
             
             
             
             
             
             
             
