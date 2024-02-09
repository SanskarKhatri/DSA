#include<stdio.h>
int recursion(int);
int main(){
    int n;
    scanf("%d",&n);
    printf("%d\n",recursion(n));
}
int recursion(int n){
    if (!n){
        return 1;
    } else {
        return n*recursion(n-1);
    }
}