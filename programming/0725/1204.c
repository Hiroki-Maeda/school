/*1204*/
#include<stdio.h>
#include<math.h>
double kai(double a, double b, double c);
double kai2(double a, double b, double c);
int main(void){
  double a, b, c, d, ans, ans2; 
  printf("ax^2+bx+c=0を計算します。\n");
  printf("a=");
  scanf("%lf",&a);
  printf("a=");
  scanf("%lf",&b);
  printf("a=");
  scanf("%lf",&c);
  ans=kai(a, b, c);
  d=b*b-4*a*c;
  if(d==0){
  ans=kai(a, b, c);
    printf("x=%lf\n",ans);
  }else if(d<0){
    printf("解なし\n");
  }else{
  ans=kai(a, b, c);
  ans2=kai2(a, b, c);
  printf("x=%lf,%lf\n",ans ,ans2);
  }
  return 0;
}

double kai(double a, double b, double c){
  double ans, d, e;
  d=b*b-4*a*c;
  e=sqrt(d);
  ans=(-b+e)/(2*a);
  return (ans);
}
double kai2(double a, double b, double c){

  double ans, d, e;
  d=b*b-4*a*c;
  e=sqrt(d);
  ans=(-b-e)/(2*a);
  return (ans);
}
