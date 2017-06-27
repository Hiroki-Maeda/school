/*quicksort*/
#include <stdio.h>
#include <string.h>

void quickp(int a[], int left, int right);

int main(void){
  int i;
  int n=11;
  //  int a[7]={1,6,5,4,3,2,7};
  int a[11]={1,6,5,4,3,2,7,9,18,15,11};
  for(i=0;i<n;i++)printf("%d\t",a[i]);
  printf("\n");
  quickp(a,0,n-1);
  for(i=0;i<n;i++)printf("%d\t",a[i]);
  printf("\n");
  return 0;

}

void quickp(int a[], int left, int right){
  int i,j,temp;
  int pivot;
  i=left;
  j=right;
  pivot=a[(left+right)/2];
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
  if((i-1)-left>=1){
  quickp(a,left,i-1);
  }
  if(right-(j+1)>=1){
  quickp(a,j+1,right);
  }
}
