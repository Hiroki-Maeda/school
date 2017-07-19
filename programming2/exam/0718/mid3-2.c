#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct name_list
{
    int number;
    char name[10];
    struct name_list *next;
}LIST;

void input(LIST sk[],int *nmax);/*データ読み込み*/
void dellist(LIST *head,char *pd,int *counter);/*名前の削除*/
void addlist(LIST *ph,LIST *pa);/*リスト構造に追加*/

int main(void)
{
    LIST SK[10];
    LIST *head;
    LIST *p;
    LIST headname={0,NULL,NULL};
    int i;
    int Ndate=0;
    int counter=0;
    char delname[10];
    
    head=&headname;
    input(SK,&Ndate);
    for(i=0;i<=Ndate-1;i++) addlist(head,&SK[i]);
    for(p=head->next;p!=NULL;p=p->next) printf("%s\n",p->name); printf("\n");
    printf("Who do you want to delete?\n");
    scanf("%s",delname);
    dellist(head,delname,&counter);
    
    for(p=head->next;p!=NULL;p=p->next) printf("%s %d\n",p->name,p->number); printf("\n");
    
    return(0);
}

void input(LIST sk[],int *nmax)
{
    FILE *fpi;
    char infile[20];
    printf("Write the name of input date file \n");
    scanf("%s",infile);
    if((fpi=fopen(infile,"r"))==NULL)
{
 printf("error at file \n"); 
exit(1);
}
    while (fscanf(fpi,"%d %s",&sk[*nmax].number,&sk[*nmax].name)!=EOF)
    {
        sk[*nmax].next=NULL;
        (*nmax)++;
    }
    fclose(fpi);
}

void dellist(LIST *head,char *pd,int *counter)
{
    LIST *p;
    LIST *pb;
    p=head->next;
    pb=head;

    while(p!=NULL&&strcmp(p->name,pd)!=0)
    {
      pb=p;
      p=p->next;
    }
    
    while(p!=NULL&&strcmp(p->name,pd)!=0)
    {
        *counter+=1;
        p=p->next;
    }
    if(p!=NULL)
    {
        
        pb->next=p->next;
    }
    else
    {
        printf("Name is not listed\n");
        pb->next=p;
    }
}

void addlist(LIST *ph,LIST *pa)
{
    LIST *p;
    LIST *pb;
    p=ph->next;
    pb=ph;
    while(p!=NULL&&strcmp(p->name,pa->name)<=0)
    {
        pb=p;
        p=p->next;
    }
    pb->next=pa;
    pa->next=p;
}
