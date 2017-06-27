#include <stdio.h>

typedef struct namelist{
  int number;
  char *name;
  struct namelist *next;
}LIST;

int main(void){
  LIST name1 = {1001,"aoki", NULL};
  LIST name2 = {1002,"deguchi", NULL};
  LIST name3 = {1003,"egashira", NULL};
  LIST name4 = {1004,"furusawa", NULL};
  LIST name5 = {1005,"kawasaki", NULL};
  LIST *p;

  name1.next = &name2;
  name2.next = &name3;
  name3.next = &name4;
  name4.next = &name5;
  int i;
  p=&name1;
  for(i=0;i<5;i++){
    printf("%s\n",p->name);
    p=p->next;
  }
  return 0;
}
