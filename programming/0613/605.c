/* 605 */
#include <stdio.h>
int main(void)
{
  char moji[4], mojicopy[4];
  printf("文字列を入力してください:");
  scanf("%s",moji);
  mojicopy[0] = moji[0];
  mojicopy[1] = moji[1];
  mojicopy[2] = moji[2];
  mojicopy[3] = moji[3];
  printf("moji=%s\n",moji);
  printf("mojicopy=%s\n",mojicopy);
  return 0;
  }
