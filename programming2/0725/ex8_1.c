#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct data{
    int key;
    struct data *left;
    struct data *right;
}NODE;

void printdata(NODE *root);

int main(void){
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