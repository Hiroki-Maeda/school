/*1202*/
#include <stdio.h>
int kaijyou(int x);
int main(void){
  int n, ans;
  printf("階乗を計算します\n");
  printf("n=");
  scanf("%d",&n);
  ans = kaijyou(n);
  printf("%d!=%d\n",n ,ans);
  return 0;
}
int kaijyou(int x){
  int i, ans;
  ans=1;
  for(i=1;i<=x;i++){
    ans*=i;
  }
  return (ans);
}
