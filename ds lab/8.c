#include<stdio.h>
int main(){
    char a[]="This is my first C lab", buff[100];
    FILE* fp=fopen("x.txt","w");
    fputs(a,fp);
    fclose(fp);
    fp=fopen("r.txt","r");
    
    
    fclose(fp);
}