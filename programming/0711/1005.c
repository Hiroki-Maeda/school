//1005
#include <stdio.h>
int main(void){
  int a, b;
  printf("じゃんけん\n");
  printf("ルール\n");
  printf("グー＝１、チョキ＝２、パー＝３\n");
  printf("Aさんの入力=");
  scanf("%d",&a);
  printf("Bさんの入力=");
  scanf("%d",&b);
  if(a==1){
    switch(b){
    case 1:
      printf("あいこ\n");
      break;
    case 2:
      printf("Aさんの勝ち\n");
      break;
    default :
      printf("Bさんの勝ち\n");
    }
  }else if(a==2){
    switch(b){
    case 1:
      printf("Bさんの勝ち\n");
      break;
    case 2:
      printf("あいこ\n");
      break;
    default :
      printf("Aさんの勝ち\n");
    }
    }else{
    switch(b){
    case 1:
      printf("Aさんの勝ち\n");
      break;
    case 2:
      printf("Bさんの勝ち\n");
      break;
    default :
      printf("あいこ\n");
    }
  }
    return 0;
}
