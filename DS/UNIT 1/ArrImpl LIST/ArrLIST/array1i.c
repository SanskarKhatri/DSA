#include <stdio.h>
#define MAX 10
typedef struct list
{
  int a[MAX];
  int size;
}ARRLST;

void init(ARRLST *p)
{
    p->size=-1;
}

int append(ARRLST *p,int data)
{
    if(p->size==MAX-1)
        return 0;
    (p->size)++;
    p->a[p->size]=data;
    return 1;
}
int delLast(ARRLST *p,int *data)
{
    if(p->size==-1)
        return 0;
    *data=p->a[p->size];
    p->size--;
    return 1;
}

void disp(ARRLST *p)
{
    if(p->size==-1)
    {
        printf("\nList is empty");
    }
    else
    {
        for(int i=0;i<=p->size;i++)
        {
            printf("\n%d ",p->a[i]);
        }
    }
}



