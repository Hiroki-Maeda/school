#include <stdio.h>
#define MIN 18
#define MAX 20
#define NG -1

typedef struct data{
  int age;
  char *name;
  struct data *next;
}LIST;

int get_hash(int age);

int main(){
  LIST s[6] = {{18,"yamada",NULL},
	       {19,"kawada",NULL},
	       {20,"mutoh",NULL},
	       {18,"amano",NULL},
	       {18,"tanaka",NULL},
	       {20,"fukuda",NULL},
  };

  LIST *tb[3];
  LIST *p;
  int age, hash;

  tb[0]=&s[0];
  tb[1]=&s[1];
  tb[2]=&s[2];
  s[0].next = &s[3];
  s[3].next = &s[4];
  s[2].next = &s[5];
  
  printf("Input age from 18 to 20 \n");
  scanf("%d",&age);
  hash = get_hash(age);
  if(hash ==NG){
    printf("NO DATA\n");
  }else for(p=tb[hash]; p!=NULL; p=p->next){
      printf("%s\n",p->name);
    }
  return 0;
}

int get_hash(int age){
  int ret_code =NG;
  if(age>=MIN && age<=MAX){
    ret_code = age -18;
  }
  return ret_code;
}
