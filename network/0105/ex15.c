#include <stdio.h>
#include <string.h>


int main(void){
  char a[] = "This is a pen";
  int i;
  for(i=0;i<strlen(a);i++){
    printf("%c\n",a[i]);
  }
}
