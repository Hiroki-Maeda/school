#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void){
  char bango[10], namae[10], eigo[10], sugaku[10];
  char infile[20], outfile[20];
  int number[10];
  char name[10][10];
  double ave[10];
  int i,j;
  FILE *fpi, *fpo;
  printf("while the name of input data file \n");
  scanf("%s",infile);
  if((fpi = fopen(infile,"r"))==NULL){
    printf("error at file \n");
    exit(1);
  }
  i=0;
  while(fscanf(fpi,"%s %s %s %s", bango, namae, eigo, sugaku) != EOF){
    number[i] = atoi(bango);
    strcpy(name[i],namae);
    ave[i] = (atof(eigo)+atof(sugaku))/2.0;
    i++;
  }
  fclose(fpi);

  printf("wirte the name of out put data file \n");
  scanf("%s", outfile);
  if((fpo = fopen(outfile,"w")) == NULL){
    printf("error at file \n");
    exit(1);
  }
  for(j=0;j<i;j++){
    fprintf(fpo,"%d\t%s\t%8.2lf\n", number[j], name[j], ave[j]);
  }
    fclose(fpo);
    return 0;
}

    
