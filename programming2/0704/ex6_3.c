#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct name_list{
  struct name_list *next;
  char *name;
}LIST;


void dellist(LIST *head, char *pd);

int main(){
  LIST name0 = {NULL,NULL};
  LIST name1 = {NULL,"deguchi"};
  LIST name2 = {NULL,"itoh"};
  LIST name3 = {NULL,"kurata"};
  LIST name4 = {NULL,"ouchi"};

  LIST *p;
  LIST *head;

  char *pd = "itoh";

  name0.next = &name1;
  name1.next = &name2;
  name2.next = &name3;
  name3.next = &name4;

  for(p=&name1;p!=NULL;p=p->next){
    printf("%s\n",p->name);
  }
  printf("\n");
  head=&name0;
  p=head->next;


  
  dellist(head,pd);

  for(p=&name1;p!=NULL;p=p->next){
    printf("%s\n",p->name);
  };


  return 0;

}

void dellist(LIST *head, char *pd){
  LIST *p;
  LIST *pb;
  p=head->next;

  while(p!=NULL&&strcmp(p->name,pd)!=0){
    pb=p;
    p=p->next;
  }

  if(p!=NULL){
    printf("Name %s is deleted\n\n",p->name);
    pb->next = p->next;
  }else{
    printf("Name is not linked\n");

  }
}
