/* 703 */
#include <stdio.h>
int main(void)
{
  int a;
  printf("数字を入力してください=");
  scanf("%d",&a);
  if(a%2==0){
    printf("この数は偶数です\n");
  }else{
    printf("この数は奇数です\n");
  }
  return 0;
}
