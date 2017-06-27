#include <stdio.h>
#include <string.h>
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

  int i,j;

  LIST *temp;
  p->next=(name1+i);
  for(i=0;i<5;i++){
    (name1+i)->next = name1+i;
  }
  for(i=0;i<4;i++){
    for(j=0;j<5-i;j++){
      if(strcmp(*(p->next)->names,(*(*(p->next)->next)->names)>0){
	  temp->next = *(*(p->next)->next)->next;
	  *(*(p->next)->next)->next = *(p->next)->next;
	  *(p.next)->next = temp->next;
	}
	p=temp;
	
	}
      p->next=(p.next)-(5-i);
    }
  }
  p=name1;
  for(i=0;i<5;i++){
    printf("%s",p.name);
    p=p->next;
  }
  
  return 0;
  

}
