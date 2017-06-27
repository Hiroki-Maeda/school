/*802*/
#include <stdio.h>
#include <math.h>
int main(void){
  int a;
  double b;
  for(a=1;a<=100;a++)
    {
      b=sqrt(a);
      printf("%d\t%lf\n",a ,b);
    }
  return 0;
}
