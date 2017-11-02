#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MEMBER 3

typedef struct member{
  char name[20];
  int age;
  int height;
}DATA;

void read(DATA **ppdt);
void write(DATA **ppdt);
void sort(DATA **ppdt);
void write(DATA **ppdt);
void free_memory(DATA **ppdt);

int main(){
  DATA** ppdt;

  ppdt=(DATA**)malloc(sizeof(DATA*)*MEMBER);

  /* printf("ppdt = %p\n",(void *)ppdt); */

  printf("Input:\n");
  read(ppdt);
  printf("Input Data:\n");
  write(ppdt);
  sort(ppdt);
  printf("Output Data:\n");
  write(ppdt);
  free_memory(ppdt);

  return 0;
}

void read(DATA **ppdt){
  DATA* pdt;
  char shimei[20];
  int toshi,shincyou;
  int i;

  for(i=0;i<MEMBER;i++){
    scanf("%s %d %d",shimei,&toshi,&shincyou);
    /*    printf("%s %d %d\n",shimei,toshi,shincyou);*/
    pdt=(DATA*)malloc(sizeof(DATA));
    strcpy(pdt->name,shimei);
    pdt->age=toshi;
    pdt->height=shincyou;
    /* (printf("ppdt+i= %p\n",ppdt+i);*/
    *(ppdt+i)=pdt;
  }
}

void write(DATA **ppdt){
  int i;

  for(i=0;i<MEMBER;i++){
    printf("%s %d %d\n",(*(ppdt+i))->name,(*(ppdt+i))->age,(*(ppdt+i))->height);
  }
}

void free_memory(DATA **ppdt){
  int i;

  for(i=0;i<MEMBER;i++){
    free(*(ppdt+i));
  }
  free(ppdt);
}

void sort(DATA **ppdt){
  DATA* temp;
  int i,j;

  for(i=0;i<MEMBER;i++){
    /*      printf("%s %d %d",(ppdt[i]->name,ppdt[i]->age,ppdt[i]->height);*/
    for(j=i+1;j<MEMBER;j++){
      if((*(ppdt+j))->height > (*(ppdt+i))->height){
	temp=*(ppdt+i);
	*(ppdt+i)=*(ppdt+j);
        *(ppdt+j)=temp;
      }
    }
  }
}

/***********answer**************
q238059h@ias004:~/program/network/1027$ ex9
Input:
Nobuta
18
160
Kame
19
180
Imawono
50
170
Input Data:
Nobuta 18 160
Kame 19 180
Imawono 50 170
Output Data:
Kame 19 180
Imawono 50 170
Nobuta 18 160

******************************************/
