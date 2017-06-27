/* 903 for */
#include <stdio.h>
#include <math.h>
int main(void){
  int n, souwa;
  double i, heihou;
  souwa=0;
  heihou=0;

  for(n=0;n<=100;n++){
    souwa=souwa+n;
  }
  for(n=0;n<=100;n++){
    i=sqrt(n);
    heihou=heihou+i;
  }
  printf("1〜１００までの総和＝%d\n",souwa);
  printf("1〜１００までの総和＝%f\n",heihou);
  return 0;
}
