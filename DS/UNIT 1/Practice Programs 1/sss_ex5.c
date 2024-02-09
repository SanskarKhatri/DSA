#include<stdio.h>
void f1(int a[]);
void f2(int *p);
main()
{
  int a[]={2,3,4};
  f1(a);
  printf("\na[1]=%d a[2]=%d\n",a[1],a[2]);
  f2(a);
  printf("\na[1]=%d a[2]=%d",a[1],a[2]);
}
void f1(int a[])
{
  printf("\na=%p",a);
  a++;
  printf("\na=%p",a);
  a[1]=45;
}

void f2(int *p)
{
  p++;
  p[1]=98;
}

