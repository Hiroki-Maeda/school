#include <stdio.h>
#include <stdlib.h>

void myfgets(char *a,int b,FILE *fp);

int main(int argc, char *argv[]){
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
  int checkSize =0;
  for(i=0;i<=b;i++){
    if((*(a+i) = fgetc(fp))=='\n'){
      break;
    }
    if(i<b-1){
      checkSize = 1;
    }
  }
  if(checkSize = 1){
    *(a+i++)='\n';
    *(a+i)='\0';
  }else{
    *(a+i)='\n';
  }
}
/************answer***********

q238059h@iav059:~/program/network/1020$ ex6_5 ex6_5.txt
myfget:abcdefghijklmn

******************************/
