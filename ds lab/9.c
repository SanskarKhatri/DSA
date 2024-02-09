#include<stdio.h>
void prin(int n){
    printf("%d\n",n);
    if(n>0){
        prin(n-1);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    prin(n);
}