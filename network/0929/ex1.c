#include <stdio.h>
#include <stdlib.h>

typedef struct date{
  char name[10];
  int age;
  int hight;
}date;
int main(){
  int i,j;

  date *p;
  p = (date *)malloc(sizeof(date)*3);



  printf("入力:\n");
  for(i=0;i<3;i++){
    scanf("%s%d%d",(p+i)->name, &(p+i)->age, &(p+i)->hight);
  }
  date temp;
  for(i=0;i<1;i++){
    for(j=0;j<1-i;j++){
      if((p+i)->hight <
	 (p+i+1)->hight){
	temp = *(p+i);
	*(p+i)= *(p+i+1);
	*(p+i+1) = temp;
      }
    }
  }
  printf("\n");
  printf("出力:\n");
  for(i=0;i<3;i++){
    printf("%s %d %d\n",(p+i)->name, (p+i)->age, (p+i)->hight);
  }
  free(p);
  return 0;
}

/***********answer*************************

q238059h@ias020:~/program/network/0929$ ex1
入力:
Nobuta 18 160
Kame 19 180
Imawano 50 170

出力:
Kame 19 180
Nobuta 18 160
Imawano 50 170

*******************************************/
