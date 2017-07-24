#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define HASH_SIZE 4

typedef struct seiseki{
  int bangou;
  char name[20];
  int tokuten;
  struct seiseki *next;
  int hvalue;
}LIST;
int hash(char *ps);
void input(LIST *sk,int *nmax);
//void output(LIST *sk,int nmax,double engave,double mathave,double sciave);
//void get_heikin(LIST *sk,int nmax,double *engave,double *mathave,double *sciave);
void hash_input(LIST *sk ,LIST *st);

/******************************************************/

int main(void){
  LIST sk[15];
  int nmax;
  LIST *p;
  nmax=-1;
  input(sk,&nmax);
  printf("1\n");

  LIST *ht[HASH_SIZE];
  int i;
  printf("%d\n",nmax);
  for(i=0;i<=nmax;i++){
    printf("hash\n" );
    sk[i].hvalue=hash(sk[i].name);
  }

printf("hashv\n");
  for(i=0;i<=nmax;i++){
    printf("bbbb\n");
    hash_input(sk,ht[i]);
  }
  printf("hash_input\n");

	/*
    j=0;
  for(i=0;i<HASH_SIZE;i++){
    head = &ht[i];
    p = &ht[i];

    while(sk[j]!=NULL){
      if(sk[j].hvalue==i){
	strcmp(p->name,sk
	*/

  for(i=0;i<HASH_SIZE;i++){
    printf("hash %d:",i);
    for(p=ht[i];p!=NULL;p=p->next){
      printf("%s\t",p->name);
    }
    printf("\n");
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
   printf("%d\t%10s\t%d\n",(sk+i)->bangou,(sk+i)->name,(sk+i)->tokuten);
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

int hash(char *ps){
  int total =0;

  while(*ps !=EOF){
    total = total + *ps++;
  }
  printf("%d\n",total%HASH_SIZE);
  return total%HASH_SIZE;

}


void hash_input(LIST *sk,LIST *ht){
    LIST *bp;
    LIST *p;
    printf("aaaa");
    if(ht==NULL){
      ht=sk;
  }else{
      if(strcmp(sk->name,ht->name)<0){
          ht=sk;
          sk->next=ht;
        
    }else{
        p=ht;
        while(strcmp(sk->name,p->name)>=0 && *(p->next)->name!=EOF){
          bp=p;
          p=p->next;
      }if(strcmp(sk->name,p->name)>0 ){
          p->next=sk;
      }else{
          bp->next=sk;
          sk->next=p;
      }
    }
  } 
}

