/* 602.c */
#include <stdio.h>
int main(void){
  char moji[4];
  printf("文字を4文字入れてください=");
  scanf("%s",moji);
  printf("入力した文字を反対から表示すると=%c%c%c%c\n", moji[3], moji[2], moji[1], 
moji[0]);
  return 0;
  }
