//1006
#include<stdio.h>
int main(void){
  int a[10][10], b[10][10], c[10][10];
  int i, j;
    for(i=1;i<=3;i++){
      for(j=1;j<=3;j++){
	printf("a[%d][%d]=",i ,j);
	scanf("%d",&a[i][j]);
      }
    }
    for(i=1;i<=3;i++){
      for(j=1;j<=3;j++){
	printf("b[%d][%d]=",i ,j);
	scanf("%d",&b[i][j]);
      }
    }
    for(i=1;i<=3;i++){
      for(j=1;j<=3;j++){
	c[i][j]=a[i][j]+b[i][j];

      }
    }
      printf("|%d\t%d\t%d| |%d\t%d\t%d| |%d\t%d\t%d|\n", a[1][1], a[1][2], a[1][3], b[1][1], b[1][2], b[1][3], c[1][1], c[1][2], c[1][3]);
      printf("|%d\t%d\t%d|+|%d\t%d\t%d|=|%d\t%d\t%d|\n", a[2][1], a[2][2], a[2][3], b[2][1], b[2][2], b[2][3], c[2][1], c[2][2], c[2][3]);
      printf("|%d\t%d\t%d| |%d\t%d\t%d| |%d\t%d\t%d|\n", a[3][1], a[3][2], a[3][3], b[3][1], b[3][2], b[3][3], c[3][1], c[3][2], c[3][3]);
    
    
    return 0;
}
