/* 603 */
#include <stdio.h>
int main(void)
{
  int a=20, b=30, c;
  c=a;
  a=b;
  b=c;
  printf("a=%d\n",a);
  printf("b=%d\n",b);
  return 0;
}

