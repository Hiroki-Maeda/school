/* 705 */
#include <stdio.h>
int main(void){
  char moji[30];
  int a;
  printf("英字を入力してください=");
  scanf("%s",moji);
  for(a=0;moji[a]!='\0';a++){
    if(moji[a]=='z'||moji[a]=='Z'){
      moji[a]=moji[a]-25;
        
    }else{
      moji[a]=1+moji[a];
    }}
    printf("入力した文字の一つ先の文字列=%s\n",moji);
    return 0;

  }
