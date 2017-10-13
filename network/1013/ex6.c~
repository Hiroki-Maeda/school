#include <stdio.h>

int main(int argc,char *argv[]){
  char line;

  FILE *fp;
  if((fp = fopen(argv[1], "r")) == NULL){
    printf("file open error\n");
    return 1;
  }

  while(fgetc(line = fgetc(fp)) != EOF){
    printf("%s",line);
    if(ferror(fp)==1){
      printf("IO Exception!\n");
    }
  }
  fclose(fp);
  return 0;
}
    
    
