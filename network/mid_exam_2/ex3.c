#include<stdio.h>
#include<stdlib.h> 
#include<string.h> 

typedef struct name_list{
  struct name_list *next;
  char *name;
}LIST;

void addlist2ndFB(LIST *head, LIST *adddata);

int main(void){
  LIST name0= {NULL, NULL};
  LIST name1= {NULL, "Yuta"};
  LIST name2={NULL, "Rikka"};
  LIST name3={NULL, "Dekomori"};
  LIST name4={NULL, "Nibutani"};
  LIST name5={NULL, "Kumin"};

  LIST *p; /*LIST pointer */
  LIST *head; /*LIST head*/

  LIST *p1;
  LIST *p2;
  LIST *p3;
  LIST *p4;

  head=&name0; /*LIST head*/
  p1=&name1;
  p2=&name2;
  p3=&name3;
  p4=&name4;

  head->next=p1;
  p1->next=p2;
  p2->next=p3;
  p3->next=p4;

  addlist2ndFB(head, &name5);

  /*リスト構造にある全データを画面に出力*/
    for(p=head->next;p!=NULL;p=p->next){
        printf("%s\n",p->name);
    }

  return(0);
}

void addlist2ndFB(LIST *head, LIST *adddata){
    LIST *p;
    LIST *bp;
    p=head->next;
    bp=head;
    if((head->next)==NULL){
        head->next=adddata;
    }else{
        while(1){
            if((p->next)==NULL){
                bp->next=adddata;
                adddata->next=p;
                break;
            }
            bp=bp->next;
            p=p->next;
        }
    }
}
