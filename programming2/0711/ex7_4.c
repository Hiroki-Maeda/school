#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define HASH_SIZE 3
typedef struct data{
  char *name;
  struct data *next;
}LIST;

int hash(char *ps);

int main(){
  int i;
  LIST *ht[HASH_SIZE];
  LIST *p;
  LIST s[5]={
    {"yamada",NULL},
    {"kawada",NULL},
    {"amano",NULL},
    {"tanaka",NULL},
    {"fukuda",NULL},
  };

  LIST addata = {"mutoh",NULL};
  LIST *padd;
  int hvalue;

  for(i=0;i<HASH_SIZE;i++){
    ht[i]=NULL;
  }

  ht[0] =&s[0]; s[0].next =&s[3];
  ht[1] =&s[4];
  ht[2] =&s[1]; s[1].next = &s[2];
  /*
  for(i=0;i<HASH_SIZE;i++){
    for(p=ht[i];p!=NULL;p=p->next){
      printf("%s\t",p->name);
    }
    printf("\n");
  }
*/
  /**tuka*/

  padd = &addata;
  hvalue = hash(padd->name);
  if(ht[hvalue]==NULL){
    ht[hvalue]=padd;
  }else{
    p=ht[hvalue];
    ht[hvalue]=padd;
    ht[hvalue]->next=p;

  }
  /*  
  for(i=0;i<HASH_SIZE;i++){
    for(p=ht[i];p!=NULL;p=p->next){
      printf("%s\t",p->name);
    }
    printf("\n");
  } 
  */
  
  return 0;
  
}

int hash(char *ps){
  int total =0;
  while(*ps !='\n'){
    total = total + *ps++;
  }
  return total%HASH_SIZE;

}
