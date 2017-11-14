#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
  int ans = 0;;
  int i;
  for(i=1;i<argc;i++){
    ans+=atoi(*(argv+i));
  }
  printf("ans=%d\n",ans);
  return 0;
  

}

/********answer************

q238059h@iav059:~/program/network/1110$ ex11 4 6 7 3 2 8 1
ans=31


*********************************/
