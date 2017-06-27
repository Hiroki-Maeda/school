/*1105*/
#include <stdio.h>
#include <math.h>
double sincos1 (double x);
int main (void){
  int i;
  double a, ans;
  for(i=0;i<=100;i++){
    a=i*2*3.1415926/100;
    ans=sincos1(a);
    printf("%f\t%f\n",a ,ans);
  }
}
double sincos1(double x){
  double c, d, e;
  c=sin(x);
  d=cos(x);
  e=c*d;
  return (e);
}
