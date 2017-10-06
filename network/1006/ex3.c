#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dummy_Person{
  char name[10];
  int age;
}Person;

int main(){
  Person *p;
  p = (Person *)malloc(sizeof(Person));
  strcpy(p->name,"Nobuta");
  p->age = 18;

  printf("name = %s\nage = %d\n", p->name, p->age);

  free(p);
  return 0;

}


/************answer***********

q238059h@iav059:~/program/network/1006$ ex3
name = Nobuta
age = 18

******************************/
  
