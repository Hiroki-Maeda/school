#include <stdio.h>
#include <string.h>

void quickp(int a[], int n);

int main(void){
  int i;
  int n=7;
  int a[7]={1,6,5,4,3,2,7};
  for(i=0;i<n;i++)printf("%d\t",a[i]);
  printf("\n");
  quickp(a,n);
  for(i=0;i<n;i++)printf("%d\t",a[i]);
  printf("\n");
  return 0;

}

void quickp(int a[], int n){
  int i,j,temp;
  int pivot;
  i=0;
  j=n-1;
  pivot=a[n/2];
  while(1){
    while(a[i]<pivot){
      i++;
	}
    while(a[j]>pivot){
      j--;
    }
    if(i>=j) break;
    temp = a[i];
    a[i] =a[j];
    a[j] =temp;

    i++;
    j--;
  }

}

    
