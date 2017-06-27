/* 405 */
#include <stdio.h>
int main(void){
  char a[20], b[20];
  printf("名字＝");
  scanf("%s", a);
  printf("名前＝");
  scanf("%s", b);
  printf("イニシャル＝%c.%c.\n", b[0], a[0]);
  return 0;
}
