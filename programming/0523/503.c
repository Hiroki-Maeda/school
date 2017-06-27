/* 503 */
#include <stdio.h>
int main(void)
{
  char moji;
  printf("小文字を入力=");
  scanf("%c",&moji);
  moji=moji-32;
  printf("大文字=%c\n",moji);
  return 0;
}
