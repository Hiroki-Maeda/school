#include <stdio.h>

typedef struct name_list{
  struct name_list *next;
  struct name_list *before;
  char *name;
}LIST;

int main(){
  LIST s[4] ={
    {NULL,NULL,"deguchi"},
    {NULL,NULL,"itoh"},
    {NULL,NULL,"kurata"},
    {NULL,NULL,"ouchi"},
  };

  LIST *p;
  LIST *next_head, *before_head;

  s[0].next=&s[1];
  s[0].before=NULL;
  s[1].next=&s[2];
  s[1].before=&s[0];
  s[2].next=&s[3];
  s[2].before=&s[1];
  s[3].next=NULL;
  s[3].before=&s[2];

  
  next_head = &s[0];
  before_head = &s[3];

  for(p = next_head;p!=NULL;p = p->next){
    printf("%s\n",p->name);
  }
  printf("\n");
  
  for(p = next_head;p!=NULL;p = p->next){
    printf("%s\n",p->name);
  }

  return 0;
}
