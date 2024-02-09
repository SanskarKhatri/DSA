#include<stdio.h>
int fib(int);
main()
{
    int n;
    printf("Enter the no of Fib. series:");
    scanf("%d",&n);
for(int i=0;i<n;i++)
 printf("%d\t",fib(i+1));
}

int fib(int n)
{ if(n==1) return 0;
 if (n==2) return 1;
 return(fib(n-2)+fib(n-1));
}
