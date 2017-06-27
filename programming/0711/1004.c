//1004
#include <stdio.h>
int main(void){
  printf("九九の表\n");
  int a, b ,c;
  for(a=1;a<=9;a++){
    for(b=1;b<=9;b++){
    c=a*b;
    printf("%d\t",c);
    }
   printf("\n");
  }
  return 0;
}
