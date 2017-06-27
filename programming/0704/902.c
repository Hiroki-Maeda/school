/* 902 */
#include <stdio.h>
int main(void){
  float n, sum;
  sum=0;
  while(n !=0){
    printf("number=");
    scanf("%f",&n);
    sum=sum+n;
  }
  printf("sum=%f\n",sum);
  return 0;
}
