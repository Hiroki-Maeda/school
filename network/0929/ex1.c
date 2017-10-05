#include <stdio.h>
#include <stdlib.h>

struct date{
  char name[10];
  int weight;
  int hight;
}
int main(){
  int i,j;
  date a[3];
  date *p;
  p = (date *)malloc(sizeof(date));
  
  printf("名前　年齢　身長\n");
  printf("1=");
  scanf("%s %d %d",*p->name,*p->weight,*p->hight);
  printf("2=");
  scanf("%s %d %d",*(p+1)->name,*(p+1)->weight,*(p+1)->hight); 
  printf("3=");
  scanf("%s %d %d",*(p+2)->name,*(p+2)->weight,*(p+2)->hight);

  data temp;
  for(i=0;i<1;i++){
    for(j=0;j<1-i;j++){
      if(*(p+i)->hight < *(p+i+1)->height){
	temp = *(p+i);
	*(p+i)=*(p+i+1);
	*(p+i+1) = temp;
      }
    }
  }
  for(i=0;i<3;i++){
    printf("%"
  
