#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define HASH_SIZE 4

typedef struct seiseki{
  int bangou;
  char name[20];
  int tokuten;
  struct seiseki *next;
}LIST;
void dellist(LIST *ht,char *dname, int *nmax);
void input(LIST *sk,int *nmax);
void output(LIST *sk,int nmax,double engave,double mathave,double sciave);


/******************************************************/

int main(void){
  LIST sk[12];
  int nmax;
  LIST *p;
  int i;
  char delname[20];

  nmax=-1;
  input(sk,&nmax);
  printf("1\n");
    printf("delname=");
  scanf("%s",delname);
  dellist(sk,delname,&nmax);
  printf("2\n");
  

  printf("3\n");
     printf("%d",nmax);
 for(i=0;i<=nmax;i++){
   printf("%d\t%s\t%d\n",(sk+i)->bangou,(sk+i)->name,(sk+i)->tokuten);
}
  return(0);
}


/****************************************************/
void input(LIST *sk,int *nmax){

  char suji[10],namae[20],seiseki[10];
  char infile[20];
  FILE *fpi;
  int i;
  

   printf("write the name of input data file\n");
   scanf("%s",infile);
   if((fpi=fopen(infile,"r"))==NULL){
       printf("error at file.txt\n");
        exit(1);
 }
   while(fscanf(fpi,"%s %s %s ",suji,namae,seiseki)!=EOF){
    (*nmax)++;
    (sk+*nmax)->bangou=atoi(suji);
    strcpy((sk+*nmax)->name,namae);
    (sk+*nmax)->tokuten=atoi(seiseki);
     
}


 for(i=0;i<=*nmax;i++){
   (sk+i)->next=(sk+i+1);
   printf("%d\t%s\t%d\n",(sk+i)->bangou,(sk+i)->name,(sk+i)->tokuten);
}
fclose(fpi);
}
/*
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
*/
/****************************************/

void dellist(LIST *ht, char *dname,int *nmax){
  int i=0;
  LIST *p;
  LIST *bp;  
  p=ht;
  while(i<=*nmax){
    while(p!=NULL && strcmp(p->name,dname)!=0){
      bp=p;
      p=p->next;
    }
    if(p==NULL){
	printf("There is no data to be deleted\n");
    }else if(strcmp(p->name,dname)==0){
      *nmax--;
      if(p==ht){
	ht=p->next;
      }else{
	bp->next=p->next;
      }
    }
  }
}
