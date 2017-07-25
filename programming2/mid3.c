#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define HASH_SIZE 4

typedef struct date{
int id;
char name[20];
int point;
struct date *next;
}LIST;

int hash(char *ps);
void add_list(LIST *hashtable[],LIST *padd);
void input(LIST sk[],int *nmax);
void output(double ave,LIST *hashtable[]);
double heikin(LIST *hashtable[]);
void deletion(LIST *hashtable[],char *dname);
void display(LIST *hashtable[]);

int main(void){
int i;
LIST *p;
LIST sk[30];
LIST *hashtable[HASH_SIZE];
int nmax=0;
for(i=0;i<HASH_SIZE;i++)hashtable[i]=NULL;
  char dname[10];
input(sk,&nmax);

for(i=0;i<nmax;i++)add_list(hashtable,&sk[i]);

display(hashtable);
heikin(hashtable);
output(heikin(hashtable),hashtable);
  printf("\nWho do you want to delete=");
  scanf("%s",dname);
printf("\n");
deletion(hashtable,dname);
display(hashtable);
heikin(hashtable);
output(heikin(hashtable),hashtable);
  return(0);
}
int hash(char *ps){
  int total=0;
  while(*ps!='\n'){
  total=total+*ps++;
  }
  return total%HASH_SIZE;

}
void add_list(LIST*hashtable[],LIST *padd){
  int hvalue;
  LIST *p,*pb;

  hvalue=hash(padd->name);
  if(hashtable[hvalue]==NULL)
    hashtable[hvalue]=padd;
  else{
    p=hashtable[hvalue];
    if(strcmp(padd->name,p->name)<0){
      hashtable[hvalue]=padd;
      padd->next=p;
    }
    else{
      pb=p;
      p=p->next;
      while(p!=NULL&&strcmp(padd->name,p->name)>0){
	pb=p;
	p=p->next;
      }pb->next=padd;
      padd->next=p;
    }
  }
}
void input(LIST sk[],int *nmax){
  FILE *fpi;
  char infile[20];

  printf("Write the name of input data file\n");
  scanf("%s",infile);

  if((fpi=fopen(infile,"r"))==NULL){
    printf("error at file\n");exit(1);
  }
  while(fscanf(fpi,"%d %s %d",&sk[*nmax].id,sk[*nmax].name,&sk[*nmax].point)!=EOF){
    sk[*nmax].next=NULL;
    (*nmax)++;
  }fclose(fpi);
}

void output(double ave,LIST *hashtable[]){
   FILE *fpo;
   char outfile[20];
   int i;
   LIST *p;
   printf("Write the name of output data\n");
   scanf("%s",outfile);
   if((fpo=fopen(outfile,"w"))==NULL){
      printf("error at file\n");
      exit(1);
   }
 for(i=0;i<HASH_SIZE;i++){
    fprintf(fpo,"hash value%d:",i);
 for(p=hashtable[i];p!=NULL;p=p->next) fprintf(fpo,"%s\t",p->name);
    fprintf(fpo,"\n");
}
fprintf(fpo,"average=%lf",ave);

  fclose(fpo);
}



double heikin(LIST *hashtable[]){
  int i;
  double total,count;
  double average;
  LIST *p;
  total=0;
  count=0;
  for(i=0;i<HASH_SIZE;i++){
    for(p=hashtable[i];p!=NULL;p=p->next){
      total+=p->point;
      count+=1;
    }
  }
  average=total/count;
  printf("\n");
  printf("average=%f\n",average);
return average;
}

void deletion(LIST *hashtable[],char *dname){
LIST *p;
LIST *pb;
int hvalue=hash(dname);
p=hashtable[hvalue];
    while(p!=NULL&&strcmp(p->name,dname)!=0){
      pb=p;
      p=p->next;
    }
 if(p==NULL) printf("There is no date to be deleted\n");
  else{
    if(p==hashtable[hvalue]){
 hashtable[hvalue]=p->next;
deletion(hashtable,dname);
}
    else pb->next=p->next;

}
}
void display(LIST *hashtable[]){
  int i;
  LIST *p;
  for(i=0;i<HASH_SIZE;i++){
    printf("hash value%d:",i);
    for(p=hashtable[i];p!=NULL;p=p->next)printf("%s\t",p->name);
    printf("\n");
  }
}


