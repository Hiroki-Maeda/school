#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define HASH_SIZE 4

typedef struct data{
    int gakunen;
    char *name;
    int seiseki;
    struct data *next;
}LIST;

int hash(char *ps);
void input(LIST *sk,int *nmax);
//void output(LIST *sk,int nmax,double engave,double mathave,double sciave);

int main(){

    LIST *ht[HASH_SIZE];
    LIST *p;
    LIST s[15];
    int nmax=0;
    int i;
    
    input(s,&nmax);
    
    for(i=0;i<nmax;i++){
        printf("Name: %s,  Hash value %d \n",s[i].name, hash(s[i].name));
    }
 /*   
    printf("\nBefore deletion\n");
    for(i=0;i<HASH_SIZE;i++){
        printf("hHash value %d\t",i);
        for(p=ht[i];p!=NULL;p=p->next){
            printf("%s\t",p->name);
        }
        printf("\n");
    }
    
    
    printf("\nAfter deletion\n");
    for(i=0;i<HASH_SIZE;i++){
        printf("hHash value %d\t",i);
        for(p=ht[i];p!=NULL;p=p->next){
            printf("%s\t",p->name);
        }
        printf("\n");
    }
    return 0;
   */ 
}

int hash(char *ps){
    int total =0;
    while(*ps!='\n'){
        total = total+*ps++;
    }
    return total%HASH_SIZE;
}

void input(LIST *sk,int *nmax){

    char namae[20], gakunenn[10], tokuten[10];
    char infile[20];
    FILE *fpi;
    int i;

    printf("write the name of input data file\n");
    scanf("%s",infile);
    if((fpi=fopen(infile,"r"))==NULL){
        printf("error at file.txt\n");
        exit(1);
    }
    printf("1\n");
    while(fscanf(fpi,"%s %s %s",gakunenn, namae, tokuten)!=EOF){  
 
        (sk+*nmax)->gakunen=atoi(gakunenn);
        strcpy((sk+*nmax)->name,namae);
        (sk+*nmax)->seiseki=atoi(tokuten);
       (*nmax)++;
    }

    printf("2\n");
    for(i=0;i<=*nmax;i++){
        printf("%d\t%10s\t%d\n",(sk+i)->gakunen,(sk+i)->name, (sk+i)->seiseki);
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
*/