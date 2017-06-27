/*604 */
#include <stdio.h>
int main(void){
  char moji[7];
  printf("数字を入力してください=");
  scanf("%s",moji);
  printf("入力した数字を反対から表示させると=%c%c%c%c%c%c\n",moji[5], moji[4], moji[3], moji[2], moji[1], moji[0]);
  return 0;
}
