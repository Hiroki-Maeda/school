#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct seiseki{
  int number;
  char name[20];
  int ENG;
  int MATH[2];
  double ave;
  char grade[4];
}LIST;

void get_heikin(LIST *a);
double get_ENG_heikin(LIST a[], int Maxn);
void input(LIST *a,int *Maxn);
void output(LIST a[],double ENGave,int Maxn);

int main(void){
  int Maxn = -1;
  LIST sk[5];
  int i;
  double ENGave;
  input(sk,&Maxn);
  for(i=0;i<=Maxn;i++){
    get_heikin(&sk[i]);
  }
  ENGave = get_ENG_heikin(sk,Maxn);
  output(sk, ENGave, Maxn);
  return 0;
}

void get_heikin(LIST *a){
  double temp=0;
  temp= ((double)a->ENG+(double)a->MATH[0]+(double)a->MATH[1])/3.0;
  a->ave =temp;
  if(temp>=80){
    strcpy(a->grade,"AAA");
  }else if(temp<80&&temp>=70){
    strcpy(a->grade,"AA");
  }else if(temp<70&&temp>60){
    strcpy(a->grade,"A");
  }else{
    strcpy(a->grade,"D");
  }
}
double get_ENG_heikin(LIST a[],int Maxn){
  double temp = 0;
  int i;
  for(i=0;i<=Maxn;i++){
    temp +=(double)a[i].ENG;
      }
  return temp/((double)Maxn+1.0);
}




void input(LIST *a,int *Maxn){
  char infile[20];
  FILE *fpi;
  char bangou[10], namae[15], eigo[10], sugaku1[10], sugaku2[10];
  printf("write the name of input data file \n");
  scanf("%s",infile);
  if((fpi=fopen(infile,"r"))==NULL){
    printf("error at file \n");
    exit(1);
  }
    while(fscanf(fpi,"%s\t%s\t%s\t%s\t%s", bangou, namae, eigo, sugaku1, sugaku2) != EOF){
      (*Maxn)++;
    (a+*Maxn)->number=atoi(bangou);
    strcpy((a+*Maxn)->name,namae);
    (a+*Maxn)->ENG =atoi(eigo);
    (a+*Maxn)->MATH[0]=atoi(sugaku1);
    (a+*Maxn)->MATH[1]=atoi(sugaku2);
  }
  fclose(fpi);
  printf("imput\n");
}





void output(LIST a[],double ENGave,int Maxn){
  char outfile[20];
  printf("write the name of out put data file \n");
  scanf("%s",outfile);
  FILE *fpo;
  if((fpo = fopen(outfile,"w"))==NULL){
    printf("error at file \n");
    exit(1);
  }
  int i;
  for(i=0;i<=Maxn;i++){
    fprintf(fpo,"%lf\t%s\n",a[i].ave, a[i].grade);
  }
  fprintf(fpo,"english average\t%lf\n",ENGave);
  fclose(fpo); 
}
