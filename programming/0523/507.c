/* 507 */
#include <stdio.h>
int main(void)
{
  printf("文字を5文字入力してください\n");
  char a[6];
  scanf("%s",a);
  printf("その文字を反対から並べた文字列=%c%c%c%c%c\n",a[4], a[3], a[2], a[1], a[0]);
  return 0;
}
