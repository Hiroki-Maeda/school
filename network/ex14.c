#include <stdio.h>

typedef struct Book{
    char author[255];
    char title[255];
    char code_ISBN[255];
    int price;
}Book;

int main(void){
    Book bkdata[3];
    int i;
    for(i=0;i<3;i++){
        printf("input author\n");
        scanf("%s",bkdata[i].author);
        printf("author= %s\n",bkdata[i].author);
        printf("input title\n");
        scanf("%s",bkdata[i].title);
        printf("title= %s\n",bkdata[i].title);
        printf("input ISBN\n");
        scanf("%s",bkdata[i].code_ISBN);
        printf("ISBN= %s\n",bkdata[i].code_ISBN);
        printf("input price\n");
        scanf("%d",&bkdata[i].price);
        printf("price= %d\n",bkdata[i].price);
    }
    
    printf("\nBook Data\n");    
    for(i=0;i<3;i++){        
        printf("author= %s\n",bkdata[i].author);
        printf("title= %s\n",bkdata[i].title);
        printf("ISBN= %s\n",bkdata[i].code_ISBN);
        printf("price= %d\n",bkdata[i].price);


    }
}

/**********************************

input author
aaaa
author= aaaa
input title
aaaaa
title= aaaaa
input ISBN
aaaaaa
ISBN= aaaaaa
input price
1000 
price= 1000
input author
bbbb
author= bbbb
input title
bbbbb
title= bbbbb
input ISBN
bbbbbb
ISBN= bbbbbb
input price
2000
price= 2000
input author
cccc
author= cccc
input title
cccc
title= cccc
input ISBN
cccccc
ISBN= cccccc
input price
3000
price= 3000

Book Data
author= aaaa
title= aaaaa
ISBN= aaaaaa
price= 1000
author= bbbb
title= bbbbb
ISBN= bbbbbb
price= 2000
author= cccc
title= cccc
ISBN= cccccc
price= 3000

********************/
