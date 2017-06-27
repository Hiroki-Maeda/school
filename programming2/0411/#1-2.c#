#include <stdio.h>

typedef struct seiseki{
  int number;
  char *name;
  int ENG;
  int MATH[3];
  double ave;
}SK;

int main(){
  int j,i;
  SK s[3]={
    {1001,"yamada",90,80,50,60,0.0},
    {1002,"aoki",80,70,50,60,0.0},
    {1003,"kawai",85,65,50,60,0.0},
  };
  for(j=0;j<3;j++){
        int mathsum=0;
	for(i=0;i<=2;i++){
	  mathsum += s[j].MATH[i];
	}
	s[j].ave =(s[j].ENG+mathsum)/4.0;
  }
  
  printf("number\tname\taverage \n");
  for(j=0;j<=2;j++){
    printf("%4d\t%s\t%8.2lf\n",s[j].number, s[j].name, s[j].ave);
  }
  return 0;
}
