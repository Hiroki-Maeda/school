/*1003*/
#include <stdio.h>
# define n 11
int main(void){
  int i, j, m;
  int a[n], b;
  printf("5個の整数を入力してください。\n");

  for(i=1; i<n; i++){
    printf("a[%d]=", i);
    scanf("%d",&a[i]);
  }
  printf("入力した数字を小さい順に並べかえると\n");
  for(m=9; m>=1;m--){
    for(j=1;j<n;j++){
      if(a[j]>a[j+1]){
	b=a[j];
	a[j]=a[j+1];
	a[j+1]=b;
      }
    }
  }
    for(i=1; i<n; i++){
      printf("a[%d]=%d\n",i ,a[i]);
    }

    return 0;
}
