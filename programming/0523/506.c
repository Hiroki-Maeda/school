/* 506 */
#include <stdio.h>
int main(void)
{
  char a[6];
  printf("文字一文字入力してください=");
	 scanf("%c",&a[0]);
	 a[1]=a[0]+1;
	 a[2]=a[0]+2;
	 a[3]=a[0]+3;
	 a[4]=a[0]+4;
      	 printf("その文字の後5文字=%s\n",a);
	 return 0;
	 }
