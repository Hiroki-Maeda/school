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
            printf("break%d\n",i);
            break;
        }else{
            printf("feof=%d\n",feof(fp));
        }
        if(ferror(fp)){
            printf("IO Exception!\n");
        }    
   
    }
    printf("%s",line);
    fclose(fp);
    
    return 0;
}
    
    
