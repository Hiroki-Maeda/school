#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct seiseki{
   int number;
   char name[20];
   int ENG;
   int MATH;
   int SCIENCE;
   double ave;
}LIST;

void input(LIST *sk,int *nmax);
void output(LIST *sk,int nmax,double engave,double mathave,double sciave);
void get_heikin(LIST *sk,int nmax,double *engave,double *mathave,double *sciave);

int main(void){
  LIST sk[10];
  double engave,mathave,sciave;
  int nmax;
  nmax=-1;
   input(sk,&nmax);
   get_heikin(sk,nmax,&engave,&mathave,&sciave);
   output(sk,nmax,engave,mathave,sciave);
  return(0);
}


void input(LIST *sk,int *nmax){

  char bango[10],namae[20],eigo[10],sugaku[10],rika[10];
  char infile[20];
  FILE *fpi;
  int i;

   printf("write the name of input data file\n");
   scanf("%s",infile);
   if((fpi=fopen(infile,"r"))==NULL){
       printf("error at file.txt\n");
        exit(1);
 }
   while(fscanf(fpi,"%s %s %s %s %s",bango,namae,eigo,sugaku,rika)!=EOF){
    (*nmax)++;
    (sk+*nmax)->number=atoi(bango);
    strcpy((sk+*nmax)->name,namae);
     (sk+*nmax)->ENG=atoi(eigo);
     (sk+*nmax)->MATH=atoi(sugaku);
     (sk+*nmax)->SCIENCE=atoi(rika);
}


 for(i=0;i<=*nmax;i++){
   printf("%d\t%10s\t%d\t%d\t%d\n",(sk+i)->number,(sk+i)->name,(sk+i)->ENG,(sk+i)->MATH,(sk+i)->SCIENCE);
}
fclose(fpi);
}

void output(LIST *sk,int nmax,double engave,double mathave,double sciave){
  FILE *fpo;
  char outfile[20];
  int i;
  
  printf("write the name of output data file\n");
  scanf("%s",outfile);
  if((fpo=fopen(outfile,"w"))==NULL){
    printf("error at file.txt\n");
     exit(1);
}
  for(i=0;i<=nmax;i++){
   fprintf(fpo,"%d\t%10s\t%d\t%d\t%d\t%8.2lf\n",(sk+i)->number,(sk+i)->name,(sk+i)->ENG,(sk+i)->MATH,(sk+i)->SCIENCE,(sk+i)->ave);
}
  fprintf(fpo,"Average of English is %8.2lf\n",engave);
  fprintf(fpo,"Average of Math is %8.2lf\n",mathave);
  fprintf(fpo,"Average of Science is %8.2lf\n",sciave);
 fclose(fpo);
}

void get_heikin(LIST *sk,int nmax,double *engave,double *mathave,double *sciave){

  int i;
  double temp=0;
  for(i=0;i<=nmax;i++){
    (sk+i)->ave=((sk+i)->ENG+(sk+i)->MATH+(sk+i)->SCIENCE)/3.0;
}
  for(i=0;i<=nmax;i++){
     temp+=sk[i].ENG;
}
  *engave=temp/(nmax+1);
  temp=0;
  for(i=0;i<=nmax;i++){
     temp+=sk[i].MATH;
}
  *mathave=temp/(nmax+1);
   temp=0;
  for(i=0;i<=nmax;i++){
     temp+=sk[i].SCIENCE;
}
  *sciave=temp/(nmax+1);
}
     














