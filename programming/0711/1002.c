/* 1001 */
#include <stdio.h>
int main (void){
  printf("number=");
  int a;
  scanf("%d",&a);
  switch(a){
  case 1:
    printf("One\n");
    break;
  case 2:
    printf("two\n");
    break;
  case 3:
    printf("Three\n");
    break;
  case 4:
    printf("four\n");
    break;
  case 5:
    printf("five\n");
    break;
  default:
    printf("例外\n");
  }
    return 0;
  }
