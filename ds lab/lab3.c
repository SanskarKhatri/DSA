#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define SIZE 100
typedef struct STACK {
	int top;
	char arr[SIZE];
} stack;
stack* createStack(){
	stack* p;
	p=(stack*)malloc(sizeof(stack));
	if (!p) 
		return NULL;
	p->top=-1;
	return p;
}
int isEmpty(stack *p){
	return p->top==-1;
}
char peek(stack *p){
	return (p->arr[p->top]);
}
char pop(stack *p){
	if (!isEmpty(p))
		return p->arr[p->top--];
	return '$';
}
void push(stack *p, char x){
	(p->arr)[++p->top]=x;
}
int Prec(char ch){
	switch (ch) {
	case '+':
	case '-':
		return 1;

	case '*':
	case '/':
		return 2;

	case '^':
		return 3;
	}
	return -1;
}
char* infix_to_postfix(char infix[SIZE], int n){
	int i,k;
	stack* opStck=createStack();
	for(i=0,k=-1;i<n;i++){
		if(isdigit(infix[i])){
			infix[++k]=infix[i];
		}
		else if(infix[i]=='('){
			push(opStck,infix[i]);
		}
		else if(infix[i]==')'){
			while(!isEmpty(opStck) && peek(opStck)!='('){
				infix[++k]=pop(opStck);
			}
			if(!isEmpty(opStck) && peek(opStck)!='('){
				return NULL;
			}
			else {
				pop(opStck);
			}
		}
		else {
			while (!isEmpty(opStck) && Prec(infix[i]) <= Prec(peek(opStck))){
				infix[++k] = pop(opStck);
			}
			push(opStck, infix[i]);
		}
	}
	while(!isEmpty(opStck)){
		infix[++k] = pop(opStck);
	}
	infix[++k]='\0';
	printf("%s\n",infix);
	return infix;
}
char* rev(char array[SIZE]){
    int i,j;
    char temp[SIZE];
    for (i=strlen(array)-1,j=0;i+1!=0;i--,j++){
        if(array[i]=='('){
            temp[j]=')';
        } else if(array[i]==')'){
            temp[j]='(';
        } else {
            temp[j]=array[i];
        }
    }
    temp[j]='\0';
    strcpy(array,temp);
	printf("%s\n",array);
    return array;
}
void infix_to_prefix(char infix[SIZE], char prefix[SIZE], int n)
{
	strcpy(prefix,rev(infix_to_postfix(rev(infix),n)));
}

int evaluate_prefix(char prefix[SIZE], int n)
{
	char c;
	stack* opStck=createStack();
	int a,b,res=0;
	for(int i=n-1;i>=0;i--){
		if(isdigit(prefix[i])){
			push(opStck,prefix[i]);
		} else {
			a=(int)pop(opStck)-48;
            b=(int)pop(opStck)-48;
            switch(prefix[i]){
                case '+':
                res=a+b;
                break;
                case '*':
                res=a*b;
                break;
                case '-':
                res=a-b;
                break;
                case '/':
                res=a/b;
                break;
                case '^':
                res=pow(a,b);
                break;
            }
            c=res+'0';
            push(opStck,c);
		}
	}
	return res;
}

int main()
{
	char infix[SIZE], prefix[SIZE];     

	int n;

	scanf("%d", &n);
	scanf("%s", infix);

	infix_to_prefix(infix, prefix, n);

	// int res = evaluate_prefix(prefix, strlen(prefix));

	// printf("%s %d\n", prefix, res);
	printf("%s %s\n",infix,prefix);
	return 0;
}


