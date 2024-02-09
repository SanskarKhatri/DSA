#include<stdio.h>
struct __attribute__((packed)) test
//struct test
{
  char t1;   //1
  int i;     //4
  char ch;   //1
  float k;   //4
};
main()
{
 struct test t;
 printf("%ld",sizeof(struct test));
}
