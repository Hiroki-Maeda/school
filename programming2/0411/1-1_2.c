#include <stdio.h>

typedef struct seiseki{
  int number;
  char *name;
  int ENG;
  int MATH;
  double ave;
}SK;

int main(){
  int j;
  SK s[3]={
    {1001,"yamada",90,80,0.0},
    {1002,"aoki",80,70,0.0},
    {1003,"kawai",85,65,0.0},
  };
  for(j=0;j<3;j++){
    s[j].ave =(s[j].ENG+s[j].MATH)/2.0;
  }

  printf("number\tname\taverage \n");
  for(j=0;j<=2;j++){
    printf("%4d\t%s\t%8.2lf\n",s[j].number, s[j].name, s[j].ave);
  }
  return 0;
}
  
