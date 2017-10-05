#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){

  char s0[20]="Good bye\n";
  printf("%s",s0);

  char *s1 = (char *)malloc(sizeof(char)*20);
  strcpy(s1,"Hello World\n");
  printf("%s",s1);

  free(s1);

  return 0;

}
  
  
/*************answer********************

q238059h@ias020:~/program/network/0929$ ex2
Good bye
Hello World

***************************************/
