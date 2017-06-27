#include <stdio.h>
#include <string.h>

int main(void){
  printf("-1");
  char *a[5]={"tokyo","shinbashi","shinagawa","kawasaki","yokohama"};
  int i,j,ccr;
  printf("0");
  char temp[10]; 
  for(j=0;j<5;j++){
    strcpy(temp,a[j]);
    i=j+1;
    printf("1");
    while(i<5){
      ccr = strcmp((const char *)temp,(const char *)a[i]);
      printf("2");
      if(ccr<0){
	strcpy(a[i-1],a[i]);
      }else{
	break;
      }
      i++;
      printf("3");
    }
    strcpy(a[i-1],temp);
  }
  for(i=0;i<5;i++){
    printf("%s",a[i]);
  }
  return 0;
}
