#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <math.h>
int m[5][8];
int n;

void color(int t, int f)
{
	HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
   SetConsoleTextAttribute(H,f*16+t);
}
void remplir(int m[5][8])
{
int i,j;
for (i=0;i<5;i++)
{
    m[i][0]=9;
    for (j=1;j<8;j++) {
    	m[i][j]= rand()%10;
      srand(rand()+time(0));
      }
}
}

void saisie_num(int *num){
int i;
char n;
printf("saisir votre numero: \n");
for(i=0;i<8;i++){
       do{
       n=getch();
	  num[i]=n-'0';}while(!(num[0]==9 && num[i]<=9 && num[i]>=0));
     printf(" %d ",num[i]);
     }
}



void verif (int m[5][8],int t[8], int x,int c){
int i=1 ;
while (i<8 && t[c] != m[x][i]){
i++;

}
if(m[x][i] == t[c] && i!=c){
	m[x][i]=m[x][i]+10;
	t[c]=t[c]+10;
}
}

void aff(int t[8],int *ver_g){
	int c=0;
	for(;c<8;c++){
		if (t[c]>=100) {color(11,0);printf("%i ",t[c]-100);*ver_g=*ver_g+1;}else if(t[c]>=10){color(14,0);printf ("%i ",t[c]-10);}
		else {color(12,0);printf ("%i ",t[c]);}

	}
}


void etat_int(int m[5][8] , int x ){

	int i;
	for (i=0;i<8;i++){
		if (m[x][i]>= 100)m[x][i]=m[x][i]-100;else if(m[x][i]>=10){m[x][i]=m[x][i]-10;
		}
	}
}

void trait(int m[5][8],int x){
int i,ver_g=0,num[8],chance=0;

srand(time(0)*x);
x=rand()%5;
float s;


	 time_t depart, arrivee;
    time(&depart);
do{
printf("\n");
printf("chance num %d :\n",chance+1);


saisie_num(num);

for(i=0;i<8;i++){
    if(m[x][i]==num[i]){
    	m[x][i]=m[x][i]+100;
      num[i]=num[i]+100;
    }
}
for(i=1;i<8;i++){
	if(m[x][i]==num[i])continue;
    verif(m,num,x,i);
}
printf("\n");
ver_g=0;
aff(num,&ver_g);
etat_int(m,x);
time(&arrivee);
	s=difftime(arrivee, depart);
	if (s>=61) {
    color(11,0);
	printf ("\n\t THE END \n");
	printf("%f\n",difftime(arrivee, depart));break;
   }
chance++;
color(7,0);
}while(!(chance==8 || ver_g==8));
if(ver_g==8){
color(7,1);
printf("\n \t Felicitation vous avez ganger\n"); color(7,0);

system("PAUSE");
}else{
color(14,8);
printf("\n \t Dommage vous avez perdu\n");
color(15,8);
printf("votre numero est: ");
for(i=0;i<8;i++){
      printf("%d ",m[x][i]);
}
printf("\n\n");   color(7,0);
system("PAUSE");
}
}
main()
{  int x;

   remplir(m);
   x=rand()%5;
   do
   {
		color(120,10);
      system("CLS");

      printf("\n \t \t \t \t \t TTCASH \n \n");
      printf("\t \t \t \t ***********************\n");
   	printf("\t \t \t \t * 1 : Jouer *** \n");
   	printf("\t \t \t \t * 2 : Sortir ** \n");
   	printf("\t \t \t \t ******************* \n");
      color(7,0);
   	printf("\n");
   	do
   	{
   	  color(11,0);	printf("Votre choix : ... [1,2] !!! ");
        color(7,0);
   		scanf("%d",&n);
   	}while(!(n<=2 && n>=1));

   	switch(n)
   	{
   		case 1 : trait(m,x); break;
      	case 2 : printf("choix 2 valide");exit;
   	}
   }while(n!=2);
}