#include <stdio.h>
#include <stdlib.h>


char* readLine(FILE *fp);

int main(int argc,char *argv[]){
    char *line;
    FILE *fp;
    if((fp = fopen(argv[1], "r")) == NULL){
        printf("file open error\n");
        return 1;
    }

    while(1){

      line = readLine(fp);
        if(feof(fp)){
            break;
        }
       printf("%s",line);
    }

  	   if(ferror(fp)){
           printf("IO Exception!\n");
        }


    free(line);
    fclose(fp);
    return 0;
}

char* readLine(FILE *fp){
  char *line;
  line = (char *)malloc(sizeof(char));
  char *chp;

  fgets(line,255,fp);
  if(!feof){
    chp = NULL;
  }else{
    chp = line;
  }
  return chp;
}

/**********************answe**********************
maeda@DESKTOP-MGJGBGP:/mnt/c/Users/trump/Desktop/hiroki/school/network/1013$ ./ex6_2 foo.txt
3
4
545
33
4
66
626
56
6
66
689
12
454


*************************************************/
