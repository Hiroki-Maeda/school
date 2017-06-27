/* 305 */
#include <stdio.h>
int main(void)
{
  double a1, a2, a3, a4;
  a1 = 1+1/2;
  a2 = 1+1.0/2;
  a3 = 1+1/2.0;
  a4 = 1+1.0/2.0;
  printf("a1=%f\na2=%f\na3=%f\na4=%f\n", a1, a2, a3, a4);
  return 0;
}
