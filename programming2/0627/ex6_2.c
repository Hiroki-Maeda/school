#include <stdio.h>
typedef struct namelist{
  char *names;
  struct namelist *next;
}LIST;

int main(){
  LIST name1 = {"furusawa",NULL};
  LIST name2 = {"deguchi",NULL};
  LIST name3 = {"kawa saki",NULL};
  LIST name4 = {"aoki",NULL};
  LIST name5 = {"egashira",NULL};

  LIST *p;

  int i;
  
  p=&name4;
  name4.next=&name2;
  name2.next=&name5;
  name5.next=&name1;
  name1.next=&name3;
  for(i=0;i<5;i++){
    printf("%s\n",p->names);
    p=p->next;
  }
  
  return 0;
  

}
