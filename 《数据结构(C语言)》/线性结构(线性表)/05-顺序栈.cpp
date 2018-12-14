//顺序栈
#include <stdio.h>
#include <stdlib.h>
#define STACK_INIT_SIZE 10//存储空间的初始分配量
#define STACKINCREMENT 2	//存储空间的分配增量
#define OVERFLOW -2 
#define OK 1
#define ERROR -1
typedef int SElemType;
typedef int Status;

//栈的顺序存储表示 
typedef struct{
	SElemType *top;	//栈顶指针 
	SElemType *base;	//栈底指针 
	int stacksize;	//当前已分配的存储空间 
}SqStack; 


//对栈进行初始化操作 
Status InitStack(SqStack &S)
{
	S.base=(SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));	//分配内存空间
	if(!S.base)
		exit(OVERFLOW); 
	S.top=S.base;	//指向同一块地址，表示栈为空
	S.stacksize=STACK_INIT_SIZE;	//当前已分配的空间 
	return OK; 
}

//得到栈顶元素
Status GetTop(SqStack S,SElemType &e)
{
	//将栈顶元素赋值给e
	if(S.base==S.top)	//当栈为空 
		return ERROR; 
	e=*(S.top-1);
	return OK; 
 } 
 
//入栈 
Status Push(SqStack &S,SElemType e)
{
	//插入元素e为新的栈顶元素 
	if(S.top-S.base>=S.stacksize)	//当栈已经满了
	{	S.base=(SElemType *)realloc(S.base,(S.stacksize+STACKINCREMENT)*sizeof(SElemType));	//追加分配内存空间
		if(!S.base) 
			exit(OVERFLOW);
		S.top=S.base+S.stacksize;	//重新分配栈顶指针 
		S.stacksize+=STACKINCREMENT;	//增加存储容量 
	}
	*S.top=e;	//将元素添加如栈顶 
	S.top++;	//指针后移一位 
	return OK;
 } 

//出栈
Status Pop(SqStack &S,SElemType e)
{
	//删除栈顶元素 
	if(S.base==S.top)	//空栈
		return ERROR;
	S.top--;
	e=*S.top;
	return OK; 
 }
 
 
//打印出栈内的所有元素
Status PrintN(SqStack S)
{
	//从栈顶先开始输出元素
	if(S.base==S.top)	//如果栈空 
	{
		printf("此栈为空");
		return ERROR; 
	}
	S.top--;
	while(S.top>=S.base)
	{
		printf("%d ",*S.top);
		S.top--;
	 } 
	return OK;
 } 
int main()
{	
	SElemType e;
	SqStack S;	
	InitStack(S);	//初始化
	for(int i=1;i<=10;i++)	//插入栈顶元素 
	{
		Push(S,i);
	}
	PrintN(S);	//打印出栈中所有的元素 
	printf("\n");
	GetTop(S,e);	//得到栈顶元素 
	printf("%d",e); 
	
	Pop(S,e);	//删除栈顶元素
	printf("\n");
	PrintN(S); 

	return 0;
}
