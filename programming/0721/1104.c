/*1104*/
#include <stdio.h>
int func3(int x);
int main(void){
  int a,b;
  printf("3乗する整数=");
  scanf("%d",&a);
  b=func3(a);
  printf("%dを3乗した値=%d\n",a ,b);
  return 0;
}
int func3(int x){
  int ans;
  ans=x*x*x;
  return (ans);
}
