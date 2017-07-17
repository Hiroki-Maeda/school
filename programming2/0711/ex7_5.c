#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define HASH_SIZE 3

typedef struct data{
  char *name;
  struct data *next;
}LIST;

int hash(char *ps);

void dellist(LIST *ht[],char *dname);

int main(){

  LIST *ht[HASH_SIZE];
  LIST *p;
  LIST s[6] ={
    {"yamada",NULL},
    {"kawada",NULL},
    {"mutoh",NULL},
    {"amano",NULL},
    {"tanaka",NULL},
    {"fukuda",NULL},
  };

  int i;
  char *delname = "mutoh";

  for(i=0;i<6;i++){
    printf("Name: %s,  Hash value %d \n",s[i].name, hash(s[i].name));
  }
    ht[0]=&s[0]; s[0].next =&s[4];
    ht[1]=&s[5];
    ht[2]=&s[1]; s[1].next=&s[2];s[2].next=&s[3];

    printf("\nBefore deletion\n");
    for(i=0;i<HASH_SIZE;i++){
      printf("hHash value %d\t",i);
      for(p=ht[i];p!=NULL;p=p->next){
	       printf("%s\t",p->name);
      }
	   printf("\n");
    }
    
    dellist(ht,delname);
    
    printf("\nAfter deletion\n");
    for(i=0;i<HASH_SIZE;i++){
      printf("hHash value %d\t",i);
      for(p=ht[i];p!=NULL;p=p->next){
	printf("%s\t",p->name);
      }
      printf("\n");
    }
    return 0;
  
}

int hash(char *ps){
  int total =0;
  while(*ps!='\n'){
    total = total+*ps++;
  }
  return total%HASH_SIZE;
}

void dellist(LIST *ht[], char *dname){
    printf("%s",dname);
  int hvalue = hash(dname);
    LIST *p;
    LIST *bp;  
    p=ht[hvalue];
  while(p!=NULL && strcmp(p->name,dname)!=0){
        bp=p;
        p=p->next;
  }
    if(p==NULL){
        printf("There is no data to be deleted\n");
    }else{
        if(p==ht[hvalue]){
            ht[hvalue]=p->next;
        }else{
            bp->next=p->next;
        }
    } 
    
}
  
