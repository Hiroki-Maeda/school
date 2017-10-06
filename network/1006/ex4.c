#include <stdio.h>
#include <stdlib.h>



typedef struct dummy_Cell {
  int data;
  struct dummy_Cell *next;
} Cell;

int main(){
  
  Cell *c2;
  c2 = (Cell *)malloc(sizeof(Cell));
  c2->data =100;
  c2->next =NULL;  
  Cell *c1;
  c1 = (Cell *)malloc(sizeof(Cell));
  c1->data = 200;
  c1->next = NULL;
  c1->next = c2;

  printf("First cell %d, Next cell %d \n",c1->data,c2->data);
  printf("First cell %d, Next cell %d \n",c1->data,c1->next->data);

  free(c1);
  free(c2);
  return 0;
}


/**************answer**********************

q238059h@iav059:~/program/network/1006$ ex4
First cell 200, Next cell 100 
First cell 200, Next cell 100 


********************************************/
