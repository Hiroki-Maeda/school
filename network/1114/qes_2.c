#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct struct_dummy {
  char nc;
  struct struct_dummy *next;
} Seq;

int chkCdn(char sq[], char *cdn);
Seq *srchS(Seq *sq,char *startcdn);
Seq *srchE(Seq *sq,char *stopcdn[3]);
int freeLISTnodes(Seq *sq);

int  main(int argc, char *argv[]){
  char mrna[]="GCAUGCAUGCGCAUGUGUAAGCAU";
  char startcdn[]="AUG";
  char *stopcdn[3] ={"UAA","UAG","UGA"};
  Seq *sq1;
  Seq *sq2;
  Seq *sq2stop;
  Seq *sq2end;
  Seq *pt;
  int numfound;
  int nth=0;
  numfound = chkCdn(mrna,startcdn);
  printf("%d\n",numfound);
  sq1 = (Seq *)malloc(sizeof(Seq));
  pt= sq1;
  for(nth=0;nth<strlen(mrna)-1;nth=nth+1){
    pt->nc=mrna[nth];
    pt->next= (Seq *)malloc(sizeof(Seq));
    pt=pt->next;
  }
  pt->nc=mrna[nth];
  pt->next=NULL;
  for(pt=sq1;pt!=NULL;pt=pt->next){
    printf("%c",pt->nc);
  }
  printf("\n");
  sq2=srchS(sq1,startcdn);
  if(sq2==NULL){
    printf("Start: Not found\n");
  } else{
    sq2stop=srchE(sq2,stopcdn);
    if(sq2stop==NULL){
      printf("Stop: Not found\n");
    } else {
      sq2end=sq2stop->next->next->next;
      for(pt=sq2;pt!=sq2end;pt=pt->next){
	printf("%c",pt->nc);
      }
      printf("\n");
    }
  }
  freeLISTnodes(sq1);
  return 0;
}

int chkCdn(char sq[], char *cdn){
  char *temp;
  int count=0;
  while(1){
    temp = strchr(sq,cdn[0]);
    if(temp==NULL){
      return count;
    }
    if(strncmp(sq, cdn, 3)){
      count++;
    }
    sq++;
  }
}

Seq *srchS(Seq *sq,char *startcdn){
  Seq *temp=sq;
  int i=0;
  Seq *ans;
  while(1){
    if(i==3){
      return ans;
    }
    if(temp==NULL){
      return NULL;
    }
    if(strchr((temp->nc),startcodn[i])){
      if(i==0){
	ans=temp;
      }
      i++;
      temp=temp->next;
    }else{
      ans=0;
      i=0;
      if(i==0){
	temp=temp->next;
      }
    }
    
  } 
}

