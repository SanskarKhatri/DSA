#include <stdio.h>
#include "array1i.c"
#define MAX 10
int main()
{
 ARRLST myLst;
 int choice,ele,res;
 init(&myLst);
 printf("Welcome");
 do{
   printf("\n 1.append 2 DelLast 3 display \n");
   printf("choose the option");
   scanf("%d",&choice);
   switch(choice)
    {
      case 1: printf("enter element");
              scanf("%d",&ele);
              res=append(&myLst,ele);
              if(res)
               printf("Successful");
              else
               printf("Unsuccessful");
             break;
      case 2: res=delLast(&myLst,&ele);
             if(res)
              printf("%d del ele",ele);
             else
               printf("Not possible");
             break;
      case 3: disp(&myLst);
             break;
   }
 }while(choice<4);
 return 1;
}
