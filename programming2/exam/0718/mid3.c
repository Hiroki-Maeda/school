/*学年ごと出力、平均*/
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

#define HASH_SIZE 4

typedef struct seiseki
{
    int gakunen;
    char namae[20];
    int tensu;
    struct seiseki *next;
}NODE;

int hash(int key,int h);
void add_list(NODE *hashtable[],NODE *padd);
void input(NODE sk[],int *nmax);
void heikin(NODE *hashtable[]);

int main(void)
{
    int i;
    NODE *p;
    NODE ak[30];
    NODE *hashtable[HASH_SIZE];
    
    int nmax=0;
    for(i=0;i<HASH_SIZE;i++) hashtable[i]=NULL;
    input(ak,&nmax);
    
    for(i=0;i<nmax;i++) add_list(hashtable,&ak[i]);
    for(i=0;i<HASH_SIZE;i++)
    {
        printf("GAKUNEN%d:",i+1);
        for(p=hashtable[i];p!=NULL;p=p->next) printf("%s \t",p->namae);
        printf("\n");
    }
    heikin(hashtable);
    return(0);
}

int hash(int key,int h)
{
    return key-1;
}

void add_list(NODE *hashtable[],NODE *padd)
{
    int hvalue;
    NODE *p;
    
    hvalue=hash(padd->gakunen,HASH_SIZE);
    if(hashtable[hvalue]==NULL) hashtable[hvalue]=padd;
    else
    {
        p=hashtable[hvalue];
        hashtable[hvalue]=padd;
        padd->next=p;
    }
}

void input(NODE ak[],int *nmax)
{
    FILE *fpi;
    char infile[20];
    
    printf("Weite the name of input date file \n");
    scanf("%s",infile);
    
    if((fpi=fopen(infile,"r"))==NULL) {
        printf("error at file \n");
        exit(1);
    }
    while(fscanf(fpi,"%d %s %d", &ak[*nmax].gakunen,&ak[*nmax].namae,&ak[*nmax].tensu)!=EOF)
    {
        ak[*nmax].next=NULL;
        (*nmax)++;
    }
    fclose(fpi);
}

void heikin(NODE *hashtable[])
{
    int i;
    double total,count;
    double average[HASH_SIZE];
    NODE *p;
    
    for(i=0;i<HASH_SIZE;i++)
    {
        total=0;
        count=0;
        for(p=hashtable[i];p!=NULL;p=p->next)
        {
            total+=p->tensu;
            count+=1;
        }
        average[i]=total/count;
    }
    printf("\n");
    for(i=0;i<HASH_SIZE;i++) printf("GAKUNEN%d: HEIKIN-TEN %f \n",i+1,average[i]);
}
