#include<stdio.h>
#include<stdio.h>
// void f1(int a[]);
// void f2(int *p);
// main()
// {
//   int a[]={2,3,4};
//   f1(a);
//   printf("%d %d\n",a[1],a[2]);
//   f2(a);
//   printf("%d %d",a[1],a[2]);
// }
// void f1(int a[])
// {
//   a++;
//   a[1]=45;
// }

// void f2(int *p)
// {
//   p++;
//   p[1]=98;
// }

struct __attribute__((packed)) test 
{  char t1;
  int i;
  char ch;
  float k;
};
main()
{
 struct test t;
 printf("%ld",sizeof(struct test));
}
