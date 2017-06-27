#include <stdio.h>

void piksrt(int n, int arr[]);

int main(){
  int a[11]={3,6,9,8,3,8,1,1,0,5,3};
  int n =11;
  int i;
  for(i=0;i<11;i++){
    printf("%d",a[i]);
  }
  printf("\n");
  piksrt(n,a);
  for(i=0;i<11;i++){
    printf("%d",a[i]);
  }
  printf("\n");
  return 0;
}

void piksrt(int n, int arr[]){
  int i,j;
  int a;
  for(j=1;j<n;j++){
    a = arr[j];
    i=j-1;
    while(i>-1&&arr[i]<a){
      arr[i+1]=arr[i];
      i--;
    }
    arr[i+1]=a;
  }
}
