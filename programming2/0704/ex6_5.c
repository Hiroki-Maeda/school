#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct namelist{
  char *name;
  struct namelist *next;
}LIST

int main(void){
  char namae[20];
  LIST *head;
  LIST namehead = {NULL,NULL};
  LIST *pt;
  LIST *p;
  LIST*pb;
  FILE *fpi;
  FILE *ifo;
  int i;
  int Ndata = 5;

  head = &namehead;
  if((fpi = fopen("nlist1.dat","r"))== NULL){
    printf("file error \n ");
    exit(1);
  }
  LIST s[Ndata];
  
  for(i=0;i<Ndata;i++){
    fscanf(fpi,"%s",namae);
    s[i].name = namae;
    pt=s[0];
    
    p=head->next;
    pb=head;
    while(p!=NULL&&strcmp(p->name,pt+i)<=0){
      pb=p;
      p=p->next;
    }
    pb->next=
      
