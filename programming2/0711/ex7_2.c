#include <stdio.h>

#define HASH_SIZE 3

int hash(char *ps);

int main(){
  char *name="yamada";
  int hvalue;
  hvalue=hash(name);
  printf("hash value of %s is %d\n",name,hvalue);
  return 1;
}

int hash(char *ps){
  int total = 0;
  while(*ps != '\n'){
    total =total + *ps++;
  }
  return total%HASH_SIZE;
}
		   
