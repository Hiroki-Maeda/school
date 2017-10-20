#include <stdio.h>
#include <stdlib.h>

void myfgets(char *a,int b,FILE *fp);

int main( char argc, char *argv[]){
  FILE *fp;
  if((fp=fopen(argv[1],"r"))==NULL){
    printf("file open error\n");
    exit(1);
  }
  char a[251];
  myfgets(a,250,fp);
  printf("myfget:%s\n",a);

  return 0;
    
}

void myfgets(char *a,int b,FILE *fp){
  int i;
  for(i=0;i<=b;i++){
    if((*(a+i) = fgetc(fp))=='\n')
      break;
  }
 
}

/************answer***********

q238059h@iav059:~/program/network/1020$ ex6_5 ex6_5.txt
myfget:abcdefghijklmn

******************************/
