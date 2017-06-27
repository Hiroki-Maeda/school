/* 304 */
#include <stdio.h>
int main(void)
{
  double a, b;
  
  printf("Input number1=");
  scanf("%lf",&a);
  printf("Input number2=");
  scanf("%lf",&b);
  printf("****Results*********\n");
  printf("%.1f+%f=%f\n", a, b, a+b);
  printf("%.1f-%f=%f\n", a, b, a-b);
  printf("%.1f*%f=%f\n", a, b, a*b);
  printf("%.1f/%f=%f\n", a, b, a/b);
  return 0;
}
