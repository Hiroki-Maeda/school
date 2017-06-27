/*805*/
#include<stdio.h>
#include<math.h>
#define MAX 
int main(void){
  int count;
  double x, y;
  for(count=1;count<=MAX;count++){
    x=(double)1/pow(count,2);
    y+=x;
  }
  printf("y=%lf\n",y);
  return 0;
}

