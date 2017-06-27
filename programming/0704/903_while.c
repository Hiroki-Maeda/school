/* 903 while */
#include <stdio.h>
#include <math.h>
int main(void){
  int n, souwa;
  double i, heihou;
  n=0;
  i=0;
  souwa=0;
  heihou=0;
  while(n<=100){
    souwa=souwa+n;
    n=n+1;
  }
  n=0;
  while(n<=100){
    i=sqrt(n);
    heihou=heihou+i;
    n=n+1;
  }
  printf("1〜１００までの総和＝%d\n",souwa);
  printf("1〜１００までの総和＝%f\n",heihou);
  return 0;
}
