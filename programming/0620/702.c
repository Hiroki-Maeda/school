/* 702 */
#include <stdio.h>
int main(void)
{
  int wa, seki, n;
  wa=0;
  seki=1;
  for(n=1;n<=10;n++){
    wa=wa+n;
    seki=seki*n;
  }
  printf("1から１０までの整数の和=%d\n",wa);
  printf("1から１０までの整数の積=%d\n",seki);
  return 0;
}
