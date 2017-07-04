#include <stdio.h>
void print(double a[5][5]);

int main(){
  int i,j,k,l;
  int count =0;
  double a[5][5];
  double b[5][5];
  double c[5][5]={0};
  double temp;
  for(i=0;i<4;i++){
  c[i][i]=1;
  }

  printf("input\n");
  for(i=0;i<4;i++){
    for(j=0;j<4;j++){
      printf("a[%d][%d]=",i+1,j+1);
      scanf("%lf",&a[i][j]);
      b[i][j]=a[i][j];
    }
  }
  
  printf("inverse matrix=\n");

  
  while(count<3){
    for(i=count;i<4;i++){
      for(j=count;j<4;j++){
	while(b[k][count]==0){
	  l++;
	  k=(k+l)%4;
	  printf("%d\n",k);
	}
	b[i][j]/=b[k][count];
	c[i][j]/=b[k][count];
      }
      printf("%lf\n",b[i][k]);
    }
    for(i=count;i<3;i++){
      for(j=0;j<4;j++){
	b[i+1][j]-=b[k][j];
	c[i+1][j]-=c[k][j];
      }
    }
    k++;
    count++;
  }
  
  print(c);
  for(k=3;k>0;k--){
    temp = b[k][k];
    for(i=k-1;i>=0;i--){
      b[i][k]/=(double)temp;
      c[i][k]/=(double)temp;
    }
    for(i=0;i<k;i++){
      b[i][k]-=b[k][k];
    }
    for(i=0;i<3;i++){
      for(j=0;j<3;j++){
	c[i][j]-=c[k][j];
      }
    }
  }
    print(c);
    return 0;
}

void print(double a[5][5]){
  int i;
  for(i=0;i<4;i++){
    printf("%lf\t%lf\t%lf\t%lf\n",a[i][0],a[i][1],a[i][2],a[i][3]);
  }
}
