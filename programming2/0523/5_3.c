#include <stdio.h>
#include <string.h>

void nibun(char a[],int lower,int upper);

int main(void){
  int n, ans;
  char a[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
  n =strlen(a);
  nibun(a,0,n);
  return 0;
}

void nibun(char a[],int lower,int upper){
  
  int ans;
  int middle;
   middle = (lower +upper)/2;

  if(a[middle]<'w'){
    lower = middle+1;
    nibun(a,lower,upper);
  }else if(a[middle]>'w'){
    upper = middle-1;
    nibun(a,lower,upper);
  }else{
   printf("%d\n",middle);
  }
}

  
  
