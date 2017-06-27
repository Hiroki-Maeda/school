 /**** moji.c ****/
 #include <stdio.h>

 int main(void){
  char s[254];
  int i;
  printf("aからzまでを繰り返し順番に打ち込んでください:");
  scanf("%s", s);
  for(i=0; s[i] != '\0'; i++);
  printf("あなたの文字数は %d でした。\n", i);
  }
