/*1205*/
#include<stdio.h>
int fibonach(int x);
int main(void){
  printf("フィボナッチ数列を計算します。\n");
  int ans, n;
    printf("n=");
    scanf("%d",&n);
    ans=fibonach(n);
    printf("answer=%d\n",ans);
}
int fibonach(int x){
  int a[20],i;
  a[0]=0;
  a[1]=1;
  for(i=1;i<=10;i++){
    a[i+1]=a[i]+a[i-1];
  }
  return (a[x]);
}
