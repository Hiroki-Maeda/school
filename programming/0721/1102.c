/*1102*/
#include <stdio.h>
void function1(void);
void function2(void);
void function3(void);

int main (void){

  printf("Main 1\n");
  function1();
  printf("Main 2\n");
  function2();
  printf("Main 3\n");
  function3();
  return 0;
}
void function2(void){
  printf("Function 2\n");
  return;
}
void function3(void){
  printf("Function 3\n");
  return;
}
void function1(void){
  printf("Function 1\n");
  return;
}
