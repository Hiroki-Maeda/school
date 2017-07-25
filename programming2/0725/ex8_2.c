#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct data{
    int key;
    struct data *left;
    struct data *right;
}NODE;

void printdata(NODE *root);
NODE *getdata(NODE *root , int x);

int main(void){
    int key;
    NODE *p;
    NODE *root;
    NODE state1 = {50,NULL,NULL};
    NODE state2 = {40,NULL,NULL};
    NODE state3 = {60,NULL,NULL};
    NODE state4 = {30,NULL,NULL};
    NODE state5 = {45,NULL,NULL};
    NODE state6 = {80,NULL,NULL};
    NODE state7 = {55,NULL,NULL};
    
    root = &state1;
    
    state1.left = &state2;
    state1.right = &state3;
    state2.left = &state4;
    state2.right = &state5;
    state3.left = &state7;
    state3.right = &state6;
    
    printdata(root);
    printf("input the value that you wont to find \n");
    scanf("%d",&key);
    p= getdata(root, key);
    if(p!=NULL){
        printf("Your target number %d is found \n", p->key);
    }else{
        printf("Your target number is not found\n");
    }
    return 0;
}

void printdata(NODE *root){
    if(root ==NULL){
        return;
    }else{
        printdata(root->left);
        printf("%d\n",root->key);
        printdata(root->right);
    }
}

NODE *getdata(NODE *root , int x){
  NODE *p;
  if(root->key==x){
    return root;   
  }
  if(root->left == NULL){
    return NULL;
  }
  p=getdata(root->left,x);
  if(p!=NULL){
    return p;
  }
  if(root->right == NULL){
    return NULL;
  }
  p=getdata(root->right,x);
    if(p!=NULL){
      return p;
  }
    return NULL;
}
