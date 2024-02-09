#include<stdio.h>
#include"DCLL.c"
int main()
{
DCLL *mylist;
mylist=(DCLL*)malloc(sizeof(DCLL));
init(mylist);
display(mylist);
ins_beg(mylist,5);
display(mylist);
ins_end(mylist,10);
display(mylist);
del_beg(mylist);
display(mylist);
del_end(mylist);
display(mylist);
return 0;
}
