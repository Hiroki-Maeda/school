/* 905 */
#include <stdio.h>
#include <math.h>

int main(void){
  int x ;
  float wa, a, b, PAI;
  wa=0;
  PAI=3.14159;
  for(x=0;x<=100;x++){
    a=(x*2*PAI/100);
  b=2*a;
  wa=cos(a)+sin(b);

  printf("x=%f\t%f\n",a, wa);
  }
  return 0;
}



