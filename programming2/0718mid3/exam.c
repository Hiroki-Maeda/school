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
void output(LIST *sk,int nmax,double engave,double mathave,double sciave);
void get_heikin(LIST *sk,int nmax,double *engave,double *mathave,double *sciave);

/******************************************************/

int main(void){
  LIST sk[15];
  int nmax;
  LIST *p;
  LIST *padd;
  nmax=-1;
  input(sk,&nmax);
  printf("1\n");
  
  LIST *ht[HASH_SIZE];
  LIST *head;
  LIST *bp;

  int i,j,k;
  int a, b, c, d;
  a=0;
  b=0;
  c=0;
  d=0;
  printf("%d\n",nmax);
  for(i=0;i<=nmax;i++){
    sk[i].hvalue=hash(sk[i].name);
  }
  printf("2\n");
  while(a!=1 && b!=1 && c!=1 && d!=1){
    if(hash(sk[i].name)==0 && a==0){
      ht[0]=&sk[i];
      k=i; 
      for(j=i;j<HASH_SIZE;j++){
	head = ht[j];
	p = ht[j];
	
	while(sk[j].name!=NULL){
	  padd=&sk[j];
	  while(1){
	    if(sk[k].hvalue==i){
	      if((strcmp(p->name,sk[k].name)==0||strcmp(p->name,sk[k].name)<0)&&((p->next)==NULL||strcmp((p->next)->name,sk[k].name)>0)){
		p->next=&sk[k];

		break;
	      }else{
		p=ht[i];
		ht[i]=padd;
		ht[i]->next=p;

		break;
	      }
	    }
	  }
	}
      }
    }else if(hash(sk[i].name)==1 && b==0){
      ht[0]=&sk[i];
      k=i; 
      for(j=i;j<HASH_SIZE;j++){
	head = ht[j];
	p = ht[j];
	
	while(sk[j].name!=NULL){
	  padd=&sk[j];
	  while(1){
	    if(sk[k].hvalue==i){
	      if((strcmp(p->name,sk[k].name)==0||strcmp(p->name,sk[k].name)<0)&&((p->next)==NULL||strcmp((p->next)->name,sk[k].name)>0)){
		p->next=&sk[k];
		break;
	      }else{
		p=ht[i];
		ht[i]=padd;
		ht[i]->next=p;
		break;
	      }
	    }
	  }
	}
      }
      
    }else if(hash(sk[i].name)==2 && c==0){
      ht[0]=&sk[i];
      k=i; 
      for(j=i;j<HASH_SIZE;j++){
	head = ht[j];
	p = ht[j];
	
	while(sk[j].name!=NULL){
	  padd=&sk[j];
	  while(1){
	    if(sk[k].hvalue==i){
	      if((strcmp(p->name,sk[k].name)==0||strcmp(p->name,sk[k].name)<0)&&((p->next)==NULL||strcmp((p->next)->name,sk[k].name)>0)){
		p->next=&sk[k];
		break;
	      }else{
		p=ht[i];
		ht[i]=padd;
		ht[i]->next=p;
		break;
	      }
	    }
	  }
	}
      }
      
    }else if(hash(sk[i].name)==3 && d==0){
      ht[0]=&sk[i];
      k=i; 
      for(j=i;j<HASH_SIZE;j++){
	head = ht[j];
	p = ht[j];
	
	while(sk[j].name!=NULL){
	  padd=&sk[j];
	  while(1){
	    if(sk[k].hvalue==i){
	      if((strcmp(p->name,sk[k].name)==0||strcmp(p->name,sk[k].name)<0)&&((p->next)==NULL||strcmp((p->next)->name,sk[k].name)>0)){
		p->next=&sk[k];
		break;
	      }else{
		p=ht[i];
		ht[i]=padd;
		ht[i]->next=p;
		break;
	      }
	    }
	  }
	}
      }
    }
  }
  printf("3\n");
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

  while(*ps !='\n'){
    total = total + *ps++;
  }
  printf("%d\n",total%HASH_SIZE);
  return total%HASH_SIZE;

}
