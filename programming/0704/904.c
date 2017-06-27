/* 904 */
#include <stdio.h>
int main(void){
  int n;
  char moji[30];
  printf("文字を入力してください\n");
  scanf("%s",moji);
  n=0;
 
  while(moji[n]!=0){
    n=n+1;
  }

 printf("入力した文字を反対から表示させると＝");
  for(n=n-1;n>=0;n--){
    printf("%c",moji[n]);
 
  }
  printf("\n");

  return 0;
  }
