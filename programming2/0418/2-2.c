#include <stdio.h>

typedef struct seiseki{
  int number;
  char *name;
  int ENG;
  int MATH[3];
  double ave;
}SK;

//int average1(int a1, int a2, int a3, int a4);
//int average2(SK a);
//int average3(SK *a);
SK average4(SK a);
int main(){
  int j,i;
  SK s[3]={
    {1001,"yamada",90,80,50,60,0.0},
    {1002,"aoki",80,70,50,60,0.0},
    {1003,"kawai",85,65,50,60,0.0},
  };
  /****************1*****************/
  /*
  for(j=0;j<3;j++){
        int mathsum=0;
	for(i=0;i<=2;i++){
	  mathsum += *((s+j)->MATH+i);
	}
	(s+j)->ave =((s+j)->ENG+mathsum)/4.0;
  }
  */
  /*
  for(i=0;i<=2;i++){
    s[i].ave = average1(s[i].ENG, s[i].MATH[0], s[i].MATH[1], s[i].MATH[2]);
  }
  */
  
  /*************************************/
  
  /****************2********************/
  /*
  for(i=0;i<=2;i++){
    s[i].ave = average2(s[i]);
  }
  */
  /*************************************/

  /****************3********************/
  /*
  for(i=0;i<=2;i++){
    s[i].ave = average3(&s[i]);
  }
  */
  /*************************************/

  /****************4********************/
  for(i=0;i<=2;i++){
    s[i] = average4(s[i]);
  }
  
  /*************************************/
  printf("number\tname\taverage \n");
  for(j=0;j<=2;j++){
    printf("%4d\t%s\t%8.2lf\n",(s+j)->number, (s+j)->name, (s+j)->ave);
  }
  return 0;
  

  
}

/****************1**********************/
/*
int average1(int a1, int a2, int a3, int a4){
  return (a1+a2+a3+a4)/4.0;
}
*/
/****************************************/

/****************2***********************/
/*
int average2(SK a){
  return (a.ENG + a.MATH[0] + a.MATH[1] + a.MATH[2])/4.0;
}
*/
/****************************************/

/****************3***********************/
int average3(SK *a){
  return (a->ENG + a->MATH[0] + a->MATH[1] + a->MATH[2])/4.0;
}
/***************************************/

/****************4**********************/
SK average4(SK a){
  a.ave = (a.ENG + a.MATH[0] + a.MATH[1] + a.MATH[2])/4.0;
  return a;
}
/***************************************/
