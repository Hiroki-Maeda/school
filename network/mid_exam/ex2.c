#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUM 100

void sort(int n, int* pb);

char *readLine(FILE *fp);

char *readLine(FILE *fp){
  char *line;
  char *chp;
  int len;
  line=(char*)malloc(sizeof(char)*256);
  fgets(line,256,fp);
  if (feof(fp)) {
    chp=NULL;
    return chp;
  }
  else {
    len=strlen(line);
    if(line[len-1]=='\n'){
      line[len-1]='\0';
    }
    chp=line;
    return chp;
  }
}

int main(void){
  int i,n;
  int b[NUM];

  FILE *fp;
  char *line;

  fp=fopen("foo2.txt","r");
  if(fp==NULL) {
    printf("File not found!\n");
    exit(1);
  }

  n=0;
  while ((line=readLine(fp))!=NULL) {
    if (ferror(fp)) {
      printf("IO Exception!\n");
      exit(1);
    }
    printf("Reading %s\n",line);
    b[n]=atoi(line);
    free(line);
    n=n+1;
  }

  fclose(fp);

  sort(n,b);

  for(i=0;i<n;i++){
    printf("In order, %d\n",b[i]);
  }

  return 0;
}

void sort(int n, int* pb){
  int temp;
  int i, j;
  /*for(i=0;i<n;i++){
    pb[i]=abs(pb[i]);
  }*/
  for(i=0;i<n-1;i++){
    for(j=i+1;j<n;j++){
      if(abs(pb[i])<abs(pb[j])){
	temp=pb[i];
	pb[i]=pb[j];
	pb[j]=temp;
      }
    }
  }
}
/*
q238059h@iav060:~/NPTESTq238059h$ ex2
Reading -25
Reading 346
Reading -4365
Reading 347
Reading 89565
Reading 7235
Reading -18
Reading -24757
Reading 554
Reading 236
Reading -818
Reading 248
Reading -9145
In order, 89565
In order, 24757
In order, 9145
In order, 7235
In order, 4365
In order, 818
In order, 554
In order, 346
In order, 25
In order, 236
In order, 347
In order, 248
In order, 18
*/
