#include <stdio.h>

int main(int argc,char *argv[]){
    char line[256];
    int i;
    FILE *fp;
    if((fp = fopen(argv[1], "r")) == NULL){
        printf("file open error\n");
        return 1;
    }

    while(1){
           
        line[i++] = fgetc(fp);
        if(feof(fp)){
            break;
        }  
   
    }

  	   if(ferror(fp)){
           printf("IO Exception!\n");
        }    
    printf("%s",line);
    fclose(fp);
    
    return 0;
}
    
/**********************answe**********************
  maeda@DESKTOP-MGJGBGP:/mnt/c/Users/trump/Desktop/hiroki/school/network/1013$ ./ex6 foo.txt
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
a  


*************************************************/ 
