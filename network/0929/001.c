#include <stdio.h>

int main(){
  int i, ans;
  ans = 0;
  printf("1~100をたす\n");
  for(i=0;i<100;i++){
    ans+=1+i;
  }
  printf("ans =%d \n",ans);
  return 0;
}

  
