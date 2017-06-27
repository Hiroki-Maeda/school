/*1103*/
#include <stdio.h>
void kansu(double);
int main (void){
  double a;
  a = 1.5;
  printf("p1:main_a=%f\n",a);
  kansu(a);
  printf("p4:main_a=%f \n",a);
  return 0;
}
void kansu(double b){
  printf("p2:func_b=%f\n",b);
  b++;
  printf("p3:func_b=%f\n",b);
 return;
}
