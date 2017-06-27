#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct seiseki{
  char name[20];
  int ENG;
  int MATH;
  int RIKA;
  double ave;
}LIST;


void quickp(LIST a[], int left, int right);
double nibun(LIST a[],char *hiroshima,int lower,int upper);
void input(LIST *a,int *Maxn);
void output(LIST a[],double hiroshimaave,int Maxn);
void heikin(LIST a[],int Maxn);
/************program********************/
int main(){
  LIST sk[9];
  int maxn=0;
  double hiroshimaave;
  input(sk,&maxn);
  heikin(sk,maxn-1);
  quickp(sk,0,maxn-1);
    char hiroshima[20];
  printf("who? =");
  
  scanf("%s",hiroshima);
  hiroshimaave = nibun(sk,hiroshima,0,maxn-1);
  output(sk,hiroshimaave,maxn-1);
  return 0;
}


/************quicksort******************/

void quickp(LIST a[], int left, int right){
  int i,j;
  LIST temp;
  char pivot[20];
  i=left;
  j=right;
  strcpy(pivot,a[(left+right)/2].name);
  while(1){
    while(strcmp(a[i].name,pivot)<0){
      i++;
    }
    while(strcmp(a[j].name,pivot)>0){
      j--;
    }
    if(i>=j) break;
    temp = a[i];
    a[i] = a[j];
    a[j] = temp;
    
    i++;
    j--;
  }
  if((i-1)>left){
    quickp(a,left,i-1);
  }
  if((j+1)<right){
    quickp(a,j+1,right);
  }
}


/**************nibuntansaku****************/
double nibun(LIST a[],char *hiroshima,int lower,int upper){

  int ans;
  int middle;
  middle = (lower +upper)/2;
  
  if(strcmp(a[middle].name,hiroshima)<0){
  lower = middle+1;
  nibun(a,hiroshima,lower,upper);
  }else if(strcmp(a[middle].name,hiroshima)>0){
  upper = middle-1;
  nibun(a,hiroshima,lower,upper);
  }else{
    return a[middle].ave;
  }
  }
/*********file*******************/
void input(LIST *a,int *Maxn){
  char infile[20];
  FILE *fpi;
  char namae[15], eigo[10], sugaku[10], rika[10];
  printf("write the name of input data file \n");
  scanf("%s",infile);
  if((fpi=fopen(infile,"r"))==NULL){
    printf("error at file \n");
    exit(1);
  }
  while(fscanf(fpi,"%s\t%s\t%s\t%s",namae, eigo, sugaku, rika) != EOF){
    strcpy((a+*Maxn)->name,namae);
    (a+*Maxn)->ENG =atoi(eigo);
    (a+*Maxn)->MATH=atoi(sugaku);
    (a+*Maxn)->RIKA=atoi(rika);
    (*Maxn)++;
  }
  fclose(fpi);
  printf("imput\n");
}





void output(LIST a[],double hiroshimaave,int Maxn){
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
    fprintf(fpo,"%s\t%d\t%d\t%d\n", a[i].name, a[i].ENG, a[i].MATH, a[i].RIKA);
  }
  fprintf(fpo,"average = %lf\n",hiroshimaave);
  fclose(fpo); 
}

/*************heikin************/

void heikin(LIST a[],int Maxn){
  int i;
  for(i=0;i<=Maxn;i++){
    a[i].ave = (a[i].ENG + a[i].MATH + a[i].RIKA)/3.0;
  }
}
