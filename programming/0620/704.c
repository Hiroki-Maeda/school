/* 704 */
#include <stdio.h>
int main(void)
{
  double a,b, x;
  printf("ax+b=0の答えを求める\n");
  printf("a=");
  scanf("%lf",&a);
  printf("b=");
  scanf("%lf",&b);
  if(a==0){
    printf("解は存在しない\n");
  }else{
    x=-b/a;
    printf("x=%f\n",x);
  }
  return 0;
}
