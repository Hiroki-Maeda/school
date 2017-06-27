/* 903_do*/
#include <stdio.h>
#include <math.h>
int main(void){
  int n, souwa;
  double i, heihou;
  n=-1;
  i=0;
  souwa=0;
  heihou=0;
  do{
    n=n+1;
    souwa=souwa+n;
  }while(n<100);
    n=-1;
    do{
      n=n+1;
      i=sqrt(n);
      heihou=heihou+i;
    }while(n<100);
    printf("1〜１００までの総和＝%d\n",souwa);
    printf("1〜１００までの総和＝%f\n",heihou);
  return 0;
}
