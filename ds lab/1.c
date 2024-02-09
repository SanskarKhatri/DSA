#include<stdio.h>
#include<stdlib.h>
int main(){
    int num=-10, num1=0,res;
    res= (num>0)?(1):(-1);
    printf("%d\n",res);
    res=(num>10)?(1):((num1<10)?0:-1);
    printf("%d\n",res);
}