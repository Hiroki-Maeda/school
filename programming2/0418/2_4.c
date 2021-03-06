#include <stdio.h>

typedef struct seiseki{
  int number;
  char *name;
  int ENG;
  int MATH[3];
  double ave;
  char grade;
}SK;

char get_grade(SK s);

int main(void){
  int i,j;
  SK s[3] ={
    {1001,"yamada",90,80,50,60,0.0},
    {1002,"aoki",80,70,50,60,0.0},
    {1003,"kawai",85,65,50,60,0.0},
  };

  for(i=0;i<=2;i++){
    s[i].grade=get_grade(s[i]);
  }
  printf("number\tname\tgrade \n");
  for(j=0;j<=2;j++){
    printf("%d\t %s\t %c\n",s[j].number, s[j].name, s[j].grade);
  }
  return 0;
}

char get_grade(SK s){
  s.ave = (s.ENG + s.MATH[0] + s.MATH[1] + s.MATH[2])/4.0;
  char x;
  if(s.ave>=80){
    x='A';
  }else if(s.ave<80&&s.ave>=70){
    x='B';
  }else if(s.ave<70&&s.ave>=60){
    x='C';
  }else{
    x='D';
  }

 return x;
}			
