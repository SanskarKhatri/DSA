// #include<stdio.h>
// # define MAX 50
// typedef struct arrlist
// {
//     int a[MAX];
//     int index;
// }arr;
// void init(arr *p)
// {
//     p->index=-1;
// }
// int append(arr *p,int data)
// {
//     if(p->index==MAX-1)
//     { 
//         return 0;
//     }
//     else
//     {
//         p->index++;
//         p->a[p->index]=data;
//         return 1;
//     }
// }
// int del(arr *p,int *data)
// {
//     if(p->index==-1)
//     {
//         return 0;
//     }
//     else
//     {
//         *data=p->a[p->index];
//         p->index--;
//         return 1;
//     }
// }
// void display(arr *p)
// {
//     for(int i=0;i<=p->index;i++)
//     {
//         printf("%d",p->a[i]);
//     }
// }
// int main()
// {
//     arr mylist;
//     init(&mylist);
//     int n,ele,res;
//     do
//     {
//     printf("Enter your choice 1.append 2.delete 3.display\n");
//     scanf("%d",&n);
//     switch(n)
//     {
//         case 1: 
//                 printf("\nEnter element");
//                 scanf("%d",&ele);
//                 res=append(&mylist,ele);
//                 if(res)
//                   printf("\nSuccessful");
//                 else
//                   printf("\nUnsuccessful");
//                 break;
//         case 2: 
//                 res=del(&mylist,&ele);
//                 if(res)
//                   printf("\nElement deleted %d",ele);
//                 else
//                   printf("\nUnsuccessful");
//                 break;
//         case 3:
//                 display(&mylist);
//                 break;
//     }
//     }while(n<4);
//     return 1;
// }

#include<stdio.h>
#include<stdlib.h>
#define MAX 3
typedef struct vararr
{
    int *a;
    int index;
    int size;
}var;
var *l;
void init(var *p)
{
    p->index=-1;
    p->size=0;
}
void alloc(var *p)
{
    if(p->size==0)
    {
        p->a=(int*)malloc(MAX*sizeof(int));
        p->size=MAX;
    }
    else if(p->index==p->size-1)
    {
        p->a=(int*)realloc(p->a,(2*p->size)*(sizeof(int)));
        p->size=2*p->size;
    }
}
int append(var *p,int data)
{
    alloc(p);
    if(p->index==p->size-1)
    {
        return 0;
    }
    p->index++;
    p->a[p->index]=data;
    return 1;
}
int del(var *p,int *pdata)
{
    if(p->index==-1)
      return 0;
    *pdata=p->a[p->index];
    p->index--;
    return 1;
}
void display(var *p)
{
    if(p->index==-1)
    {
        printf("List is empty");
    }
    else
    {
        for(int i=0;i<=p->index;i++)
        {
            printf("%d\t",p->a[i]);
        }
    }
}
int main()
{
    var mylist;
    init(&mylist);
    int n,ele,res;
    do
    {
    printf("\nEnter your choice 1.append 2.delete 3.display 4.Quit\n");
    scanf("%d",&n);
    switch(n)
    {
        case 1: 
                printf("\nEnter element");
                scanf("%d",&ele);
                res=append(&mylist,ele);
                if(res)
                  printf("\nSuccessful");
                else
                  printf("\nUnsuccessful");
                break;
        case 2: 
                res=del(&mylist,&ele);
                if(res)
                  printf("\nElement deleted %d",ele);
                else
                  printf("\nUnsuccessful");
                break;
        case 3:
                display(&mylist);
                break;
    }
    }while(n<4);
    return 1;
}