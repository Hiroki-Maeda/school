#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void){
  char bango[100]="1001\tyamada\t70.00\n1002\taoki\t65.00\n1003\tkawai\t65.00";
  FILE *fpo;
  char outfile[10];
  printf("wirte the name of out put data file \n");
  scanf("%s", outfile);
  if((fpo = fopen(outfile,"w")) == NULL){
    printf("error at file \n");
    exit(1);
  }

    fprintf(fpo,"%s\n", bango);
    fclose(fpo);
    return 0;
}
