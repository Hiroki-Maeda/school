/*1203*/
#include <stdio.h>
#include <math.h>
double function(double a);
int main(void){
  double i, x, ans;
  for(x=-1.0;x<=1.0;x+=0.01){
    i=-2.0*x*x;
    ans=function(i);
    printf("%lf\t%lf\n",x ,ans);
  }
  return 0;
}
double function(double a){
  double ans;
  ans=exp(a);
  return (ans);
}
