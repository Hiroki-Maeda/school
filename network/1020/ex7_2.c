
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int main() {
  char *line;
  while ((line=readLine(stdin))!=NULL) {
      if (ferror(stdin)) {
        printf("IO Exception!\n");
        exit(1);
      }
      printf("%s\n",line);
      free(line);
  }
  return 0;
}


/************answer***************:

q238059h@iav059:~/program/network/1020$ ex7_2
aaaa
aaaa
bbbbb
bbbbb
cccccc
cccccc


**********************************/
