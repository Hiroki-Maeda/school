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
    int i, j;
    int temp;
    for(i=0;i<n;i++){
        for(j=i;j<n;j++){
            if(abs(pb[i])<abs(pb[j])){
                temp=pb[i];
                pb[i]=pb[j];
                pb[j]=temp;    
            }
        }
    }
}