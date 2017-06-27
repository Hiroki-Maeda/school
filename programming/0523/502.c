/* 502 */
#include <stdio.h>
int main(void)
{
  char a[5]={65,66,67};
  printf("実行結果：\n");
  printf("%s\n",a);
  printf("%s%s\n",a, a);
  return 0;
}

