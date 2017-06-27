/* 203 */
#include <stdio.h>
int main(void)
{
  int a, b, c;
  printf("一つ目の数字を入力してください\n");   
    scanf("%d",&a);
    printf("二つ目の数字を入力してください\n");
    scanf("%d",&b);
    printf("三つ目の数字を入力してださい\n");
    scanf("%d",&c);
    char wa, seki;
    wa = a + b + c;
    seki = a * b * c;
    printf("%d+%d+%d=%d\n", a, b, c, wa);
    printf("%d*%d*%d=%d\n", a, b, c, seki);
    return 0;
}

