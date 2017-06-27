/*804*/
#include<stdio.h>
#include<math.h>
int main(void)
{
  int a, b, c;
  double x, y, e, d;
  printf("a,b,cの値を入力しa*x*x+b*x+c=0のxの値を求める\n");
  printf("a=");
  scanf("%d",&a);
  printf("b=");
  scanf("%d",&b);
  printf("c=");
  scanf("%d",&c);
  printf("入力した値より%d*x*x+%d*x+%d=0を解くと\n",a ,b, c);
  d=b*b-4*a*c;
  e=sqrt(d);
  x=(-b+e)/(2*a);
  y=(-b-e)/(2*a);
  if(d<0){
    printf("解なし\n");
  }else if(d==0){
    
    printf("x=%lf\n",x);
  }else{
    printf("x=%lf,%lf\n",x ,y); 
  }
  return 0;
}
