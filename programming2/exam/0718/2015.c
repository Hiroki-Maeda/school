/*ファイル入力、名前キーのハッシュ、アルファベット順、平均点と名前の画数*/
/*特定の名前入力削除、削除後の名前と平均*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define HASH_SIZE 4

typedef struct seiseki{
  int bango;
  char namae[20];
  int tensu;
  struct seiseki *next;
}NODE;

int hash(char *ps);
void add_list(NODE *hashtable[],NODE *padd);
void input(NODE sk[],int *nmax);
void heikin(NODE *hashtable[]);
void deletion(NODE *hashtable[]);
void display(NODE *hashtable[]);
int main(void){
  int i;
  NODE *p;
  NODE sk[30];
  NODE *hashtable[HASH_SIZE];
  int nmax=0;
  /*ハッシュテーブルの初期化*/
  for(i=0;i<HASH_SIZE;i++)hashtable[i]=NULL;
  /*ファイル空のデータの入力*/
  input(sk,&nmax);
  /*データの格納*/
  for(i=0;i<nmax;i++)add_list(hashtable,&sk[i]);
  /*名簿の表示*/
  display(hashtable);
  heikin(hashtable);
  deletion(hashtable);
  display(hashtable);
  heikin(hashtable);
  return(0);
}
int hash(char *ps){
  int total=0;
  while(*ps!='\0')total=total+*ps++;
  return total%HASH_SIZE;/*剰余*/

}
void add_list(NODE *hashtable[],NODE *padd){
  int hvalue;
  NODE *p,*pb;

  hvalue=hash(padd->namae);/*はっしゅ値*/
  if(hashtable[hvalue]==NULL)
    hashtable[hvalue]=padd;
  else{
    p=hashtable[hvalue];
    if(strcmp(padd->namae,p->namae)<0){
      hashtable[hvalue]=padd;
      padd->next=p;
    }
    else{
      pb=p;
      p=p->next;
      while(p!=NULL&&strcmp(padd->namae,p->namae)>0){
	pb=p;
	p=p->next;
      }pb->next=padd;
      padd->next=p;
    }
  }
}
void input(NODE sk[],int *nmax){
  FILE *fpi;
  char infile[20];

  printf("Write the name of input data file\n");
  scanf("%s",infile);

  if((fpi=fopen(infile,"r"))==NULL){
    printf("error at file\n");exit(1);
  }
  while(fscanf(fpi,"%d %s %d",&sk[*nmax].bango,&sk[*nmax].namae,&sk[*nmax].tensu)!=EOF){
    sk[*nmax].next=NULL;
    (*nmax)++;
  }fclose(fpi);
}
void heikin(NODE *hashtable[]){
  int i;
  double total,count;
  double average;
  NODE *p;
  total=0;
  count=0;
  for(i=0;i<HASH_SIZE;i++){
    for(p=hashtable[i];p!=NULL;p=p->next){
      total+=p->tensu;
      count+=1;
    }
  }
  average=total/count;
  printf("\n");
  printf("average for all members%f\n",average);
}

void deletion(NODE *hashtable[]){
  char dname[10];
  int i;
  NODE *p,*pb;
  int find=0;
  printf("\nWho do you want to delete\n");
  scanf("%s",dname);

  for(i=0;i<HASH_SIZE;i++){
    p=hashtable[i];
    while(p!=NULL&&strcmp(p->namae,dname)!=0){
      pb=p;
      p=p->next;
    }
    if(p!=NULL){
      if(p==hashtable[i])hashtable[i]=p->next;
      else pb->next=p->next;
      printf("%s is found and deleted\n",dname);
      find=1;
    }
  }
  if(find==0)printf("There is no %s",dname);
}
void display(NODE *hashtable[]){
  int i;
  NODE *p;
  for(i=0;i<HASH_SIZE;i++){
    printf("hash value%d:",i);
    for(p=hashtable[i];p!=NULL;p=p->next)printf("%s\t",p->namae);
    printf("\n");
  }
}
