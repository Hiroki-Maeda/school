#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct dummy {
  char name[20];
  int age;
  int height;
  struct dummy *next; 
} LIST;

char*StrString(char*s1,char*s2); /*文字列 s1 から文字列 s2 を探し最初の位置をアドレスで返す関数*/
LIST*NewList(void); /*新しいリストデータを生成しそのアドレスを返す関数*/
void SortList(LIST* head); /*リスト構造をバブルソートで並べ替える関数*/

int main()
{
  FILE* fp;
  char str[256]; /* １行読み込みのための文字配列*/
  char mbuf[20]; /* メンバ変数読み込みのための文字配列*/
  char* chrp; /*１行中から<li>を最初に発見した場所を示すポインタ*/
  char* chrp2; /*１行中から</li>を最初に発見した場所を示すポインタ*/
  int depth,bdepth; /* depth: <li> タグ の階層の程度, bdepth: 最下層の<li>タグの登場順序*/
  LIST* head; /*リストのヘッドポインタ*/
  LIST* p; 
  LIST* p_next; 
  LIST* np;
  LIST* npb;

  head=NewList(); /*リスト構造の先頭データを指すための形式的なデータを生成*/
  np=head;
  depth=0;
  bdepth=0;
  fp=fopen("sample-lists.html","r"); /*ファイルを開く*/
  while(!feof(fp))
    {
      fgets(str,256,fp);/*１行読み込み*/
      switch(depth)  /*<li>の階層で分岐*/
	{
	case 0:
	  chrp=StrString(str,"<li>");
	  if (chrp!=NULL)
	    {
	      printf("tag-start= %s\n",chrp);
	      npb=np;
	      np=NewList(); /*リスト構造の新しいデータの生成*/
	      bdepth=0;
	      depth=1;}
	  else
	    {
	      chrp2=StrString(str,"</li>");
	      if(chrp2!=NULL)
		{
		  printf("tag-end= %s\n",chrp2);
		  npb->next=np;} /*リスト構造の新しいデータを今までのリスト構造に追加*/
	    }
	  break;
	case 1:
	  chrp=StrString(str,"<li>");
	  if (chrp!=NULL)
	    {
	      printf("tag-to-tag= %s\n",chrp);
	      chrp2=StrString(str,"</li>");
	      if(chrp2!=NULL)
		{
		  strncpy(mbuf,chrp+4,chrp2-chrp-4);/*mbuf に<li>の直後から</li>の直前までの文字列をコピー*/
		  mbuf[chrp2-chrp-4]='\0';/*strncpyは文字列の終わり(\0)を付加してくれないので追加*/
		  switch (bdepth)  
		    {
		    case 0:
		      strcpy(np->name,mbuf);
		      bdepth++;
		      break;
		    case 1:
		      np->age=atoi(mbuf);
		      bdepth++;
		      break;
		    case 2:
		      np->height=atoi(mbuf);
		      depth=0;
		      break;
		    }
		}
	    }
	  break;
	}
    }
  fclose(fp);
  
  printf("\n入力:\n");

  for(p=head->next;p!=NULL;p=p->next)
    {
      printf("%s ",p->name);
      printf("%d ",p->age);
      printf("%d\n",p->height);
    }

  SortList(head);

  printf("\n出力:\n");

  for(p=head->next;p!=NULL;p=p->next)
    {
      printf("%s ",p->name);
      printf("%d ",p->age);
      printf("%d\n",p->height);
    }

  for(p=head;(p->next)!=NULL;p=p_next)
    {
      p_next=p->next;
      free(p);
    }

  return 0;
}


char*StrString(char*s1, char*s2)
{
  int n;

  n = strlen(s2);                            /* 文字列 s2 の長さを求める */
  
  while (1) {
    s1 = strchr(s1, s2[0]);                /* s2 の先頭の１文字を探す */
    if (s1 == NULL)                        /* 見つからなければ */
      return (NULL);                     /* NULL を返す */
    if(strncmp(s1, s2, n) == 0)            /* 見つかったら n 文字比較 */
      return s1;                 /* 一致したらポインタを返す */
    s1++;    /* ポインタを進めて */         
  }            /* 次の strchr に備える */   
}

LIST*NewList(void)
{
  LIST* p;
  p=(LIST*)malloc(sizeof(LIST));
  p->next=NULL;
  return p;
}

void SortList(LIST* head)
{
  int n=0;
  int i;
  LIST* p;
  LIST* p1;
  LIST* p2;
  LIST* p3;

  for(p=head;(p->next->next)!=NULL;p=p->next)
    {
      n++;
      p1=p->next;
      p2=p1->next;
      p3=p2->next;
      printf(" 1st: name = %s, name = %s\n",p1->name,p2->name);
      if(p2->height<p1->height)
	{
	  p->next=p2;
	  p2->next=p1;
	  p1->next=p3;
	}
    }

  printf(" n=%d\n",n);

  while(--n)
    {
      for(p=head,i=0;i!=n;p=p->next,i++)
	{
	  p1=p->next;
	  p2=p1->next;
	  p3=p2->next;
	  printf(" 2nd:%d  name = %s, name = %s\n",n,p1->name,p2->name);
	  if(p2->height<p1->height)
	    {
	      p->next=p2;
	      p2->next=p1;
	      p1->next=p3;
	    }
	}
    }  
}


/*********answer**********

q238059h@ias004:~/program/network/1027$ ex10
tag-start= <li>

tag-to-tag= <li>Nobuta</li>

tag-to-tag= <li>18</li>

tag-to-tag= <li>170</li>

tag-end= </li>

tag-start= <li>

tag-to-tag= <li>Kame</li>

tag-to-tag= <li>19</li>

tag-to-tag= <li>180</li>

tag-end= </li>

tag-start= <li>

tag-to-tag= <li>Imawano</li>

tag-to-tag= <li>50</li>

tag-to-tag= <li>160</li>

tag-end= </li>

tag-start= <li>

tag-to-tag= <li>Yama</li>

tag-to-tag= <li>19</li>

tag-to-tag= <li>150</li>

tag-end= </li>


入力:
Nobuta 18 170
Kame 19 180
Imawano 50 160
Yama 19 150
 1st: name = Nobuta, name = Kame
 1st: name = Kame, name = Imawano
 1st: name = Kame, name = Yama
 n=3
 2nd:2  name = Nobuta, name = Imawano
 2nd:2  name = Nobuta, name = Yama
 2nd:1  name = Imawano, name = Yama

出力:
Yama 19 150
Imawano 50 160
Nobuta 18 170
Kame 19 180

*************************************/
