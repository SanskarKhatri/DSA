#include<stdio.h>
#include<stdlib.h>
#define MAX 10

typedef struct treeNode {
    int utype;
    union {
        char operator;
        float operand;
    } u;
    struct treeNode *left;
    struct treeNode *right;
} NODE;

int main(){
    NODE *bst;
    char exp[MAX]="567*+8-";
}
