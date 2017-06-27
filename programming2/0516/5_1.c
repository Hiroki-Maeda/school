#include <stdio.h>

int kaijo(int n);
int main(void){
  int n=10;
  int i=0;
  i = kaijo(n);
  printf("%d\n",i);
  return 0;
}

int kaijo(int n){
  int i=0;
  if(n==0){
    return 1;
  }
    i=n*kaijo(n-1);

  return i;
}
