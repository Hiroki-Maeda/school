#include <stdio.h>
#include <stdlib.h>

int main(){
  int i;
  int a[5];
  for(i=0;i<5;i++){
    a[i]=i+1;
  }
  int ans=0;
  for(i=0;i<5;i++){
    ans +=a[i];
  }
  printf("%d\n",ans);

  int *b;
  b = (int *)malloc(sizeof(int)*5);
  for(i=0;i<5;i++){
    *(b+i)=i+6;
  }
  int *c;
  c = (int *)malloc(sizeof(int)*5);
  for(i=0;i<5;i++){
    *(c+i)=*(b+i);
  }
  ans =0;
    for(i=0;i<5;i++){
      ans +=*(c+i);
  }
  printf("%d\n",ans);
return 0;

}

/********answer****************

q238059h@iav059:~/program/network/1020$ ex8
15
40

******************************/
