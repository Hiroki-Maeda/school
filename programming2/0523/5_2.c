#include <stdio.h>

int saiki(int n);
int main(){
  int n;
  printf("何乗＝");
  scanf("%d",&n);
  int ans;
  ans = saiki(n);

  printf("ans=%d\n",ans);

  return 0;
}

int saiki(int n){
  int temp;
  if(n==1){
    return 2;
  }
  n--;
  temp = 2*saiki(n);
  return temp;
}
