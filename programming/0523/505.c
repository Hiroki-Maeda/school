/* 505 */
#include <stdio.h>

  int main(void)
  {
    char moji[10];
  scanf("%s",moji);
  moji[0]=moji[0]-32;
  moji[1]=moji[1]-32;
  moji[2]=moji[2]-32;
  moji[3]=moji[3]-32;
  moji[4]=moji[4]-32;
  moji[5]=moji[5]-32;
  moji[6]=moji[6]-32;
  moji[7]=moji[7]-32;
  moji[8]=moji[8]-32;
  moji[9]=moji[9]-32;

  printf("大文字の文字列=%s\n",moji);
return 0;
}
