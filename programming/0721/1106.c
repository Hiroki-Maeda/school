/*1106*/
#include <stdio.h>
int max_out(int a, int b);
int main (void){
  int a, b, ans;
  printf("2つの整数を比較します\n");
  printf("number1=");
  scanf("%d",&a);
  printf("number2=");
  scanf("%d",&b);
  ans=max_out(a, b);
  printf("大きい数は%dです\n",ans);
  return 0;
}
int max_out(int a, int b){
  int c;
  if(a>=b){
    c=a;
  }else{
    c=b;
  }
 return(c);
}
