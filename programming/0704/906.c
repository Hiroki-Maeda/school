/* 906 */
#include <stdio.h>
#include <math.h>

int main(void){
  int x ;
  float wa, wa2 , a, b, a2, b2, PAI, y;
  wa=0;
  y=1;
  PAI=3.14159;
  for(x=0;y<0;x++){
  a=(x*2*PAI/100);
  b=2*a;
  wa=cos(a)+sin(b);
  a2=((x+1)*2*PAI/100);
  b2=2*a;
  wa2=cos(a2)+sin(b2);
  y=wa*wa2;
}
  printf("x=%f\t%f\n",a, wa);
  return 0;
}

