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

int main(int argc, char *argv[]){
  char *mrna;
  char *mrnas[2];
  char mrna1[]="GCAUGAUGAGCAUGUGGAAGCAUG";
  char mrna2[]="GCAUGAUGAGCAUGUGGAAAGCAUG";
  char startcdn[]="AUGA";
  char *stopcdn[3] ={"AAGC","GUAG","GUGA"};
  Seq *sq1;
  Seq *sq2;
  Seq *sq2stop;
  Seq *sq2end;
  Seq *pt;
  int numfound;
  int nth=0;
  int iselect;
  char buffer[256];

  mrnas[0]=mrna1;
  mrnas[1]=mrna2;
  printf("Input 0 or 1 (select mrna)\n");
  fgets(buffer,256,stdin);
  iselect=atoi(buffer);
  mrna=mrnas[iselect];
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
      sq2end=sq2stop->next->next->next->next;
      for(pt=sq2;pt!=sq2end;pt=pt->next){
        printf("%c",pt->nc);
      }
      printf("\n");
    }
  }

  freeLISTnodes(sq1);
  return 0;
}


Seq *srchE(Seq *sq,char *endcdn[3]) {
  Seq *pt;
  int i;
  for( pt=sq; pt!=NULL; ){
    if( pt->next != NULL){
      if( pt->next->next != NULL){
        if( pt->next->next->next != NULL){

          for( i=0; i<3; i++){
            if( ( pt->nc == endcdn[i][0] ) &&
                ( pt->next->nc == endcdn[i][1] ) &&
		( pt->next->next->nc == endcdn[i][2] ) &&
                ( pt->next->next->next->nc == endcdn[i][3] ) )
              {
               	return pt;
              }
          }


          pt = pt->next->next->next->next;
	} else {
          return NULL;
	}
      } else {
	return NULL;
      }
    } else {
      return NULL;
    }
  }
  return NULL;
}

int freeLISTnodes(Seq* sq) {
  Seq *pt,*ptb;

  for( pt=sq; pt!=NULL; ){
    ptb=pt->next;
    free(pt);
    pt=ptb;
  }

  return 0;
}

int chkCdn(char sq[], char *cdn){
    int i;
    int count;
    int length;
    length = strlen(sq);
    for(i=0;i<length-3;i++){
        if(sq[i]==cdn[0]&&sq[i+1]==cdn[1]&&sq[i+2]==cdn[2]&&sq[i+3]==cdn[3]){
            printf("found at %d",i);
            count++;
        }
    }
    return count;
}
Seq *srchS(Seq *sq,char *startcdn){
    Seq *pt;
    
    for(pt=sq;pt!=NULL;){
        if(pt->next!=NULL){
            if((pt->next)->next!=NULL){
                if(((pt->next)->next)->next!=NULL){
                    
                    if(pt->nc==startcdn[0]&&(pt->next)->nc==startcdn[1]&&((pt->next)->next)->nc==startcdn[2]&&(((pt->next)->next)->next)->nc==startcdn[3]){
                        return pt;
                    }
                    
                }else{
                    return NULL;
                }       
            }else{
                return NULL;
            }    
        }else{
            return NULL;
        }
        pt=pt->next;
    }
    return NULL;
}




/*
int chkCdn(char sq[], char *cdn){
    int length;
    int i;
    int count=0;
    length = strlen(sq);
    
    for(i=0;i<length-3;i++){
        if(sq[i]==cdn[0]&&sq[i+1]==cdn[1]&&sq[i+2]==cdn[2]&&sq[i+3]==cdn[3]){
            printf("found at %d\n",i);
            count++;
        }
    }
    return count;
}
Seq *srchS(Seq *sq,char *startcdn){
    Seq *pt;
    for(pt=sq;pt!=NULL;){
        if(pt->next!=NULL){
            if((pt->next)->next!=NULL){
                if(((pt->next)->next)->next!=NULL){
                    if(pt->nc==startcdn[0]&&(pt->next)->nc==startcdn[1]&&((pt->next)->next)->nc==startcdn[2]&&(((pt->next)->next)->next)->nc==startcdn[3]){
                        return pt;
                    }
                }else{
                    return NULL;
                }
            }else{
                return NULL;
            }   
        }else{
            return NULL;
        }
        pt=pt->next;
    }
    return NULL;
}
*/