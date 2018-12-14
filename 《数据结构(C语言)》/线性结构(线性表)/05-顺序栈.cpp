//˳��ջ
#include <stdio.h>
#include <stdlib.h>
#define STACK_INIT_SIZE 10//�洢�ռ�ĳ�ʼ������
#define STACKINCREMENT 2	//�洢�ռ�ķ�������
#define OVERFLOW -2 
#define OK 1
#define ERROR -1
typedef int SElemType;
typedef int Status;

//ջ��˳��洢��ʾ 
typedef struct{
	SElemType *top;	//ջ��ָ�� 
	SElemType *base;	//ջ��ָ�� 
	int stacksize;	//��ǰ�ѷ���Ĵ洢�ռ� 
}SqStack; 


//��ջ���г�ʼ������ 
Status InitStack(SqStack &S)
{
	S.base=(SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));	//�����ڴ�ռ�
	if(!S.base)
		exit(OVERFLOW); 
	S.top=S.base;	//ָ��ͬһ���ַ����ʾջΪ��
	S.stacksize=STACK_INIT_SIZE;	//��ǰ�ѷ���Ŀռ� 
	return OK; 
}

//�õ�ջ��Ԫ��
Status GetTop(SqStack S,SElemType &e)
{
	//��ջ��Ԫ�ظ�ֵ��e
	if(S.base==S.top)	//��ջΪ�� 
		return ERROR; 
	e=*(S.top-1);
	return OK; 
 } 
 
//��ջ 
Status Push(SqStack &S,SElemType e)
{
	//����Ԫ��eΪ�µ�ջ��Ԫ�� 
	if(S.top-S.base>=S.stacksize)	//��ջ�Ѿ�����
	{	S.base=(SElemType *)realloc(S.base,(S.stacksize+STACKINCREMENT)*sizeof(SElemType));	//׷�ӷ����ڴ�ռ�
		if(!S.base) 
			exit(OVERFLOW);
		S.top=S.base+S.stacksize;	//���·���ջ��ָ�� 
		S.stacksize+=STACKINCREMENT;	//���Ӵ洢���� 
	}
	*S.top=e;	//��Ԫ�������ջ�� 
	S.top++;	//ָ�����һλ 
	return OK;
 } 

//��ջ
Status Pop(SqStack &S,SElemType e)
{
	//ɾ��ջ��Ԫ�� 
	if(S.base==S.top)	//��ջ
		return ERROR;
	S.top--;
	e=*S.top;
	return OK; 
 }
 
 
//��ӡ��ջ�ڵ�����Ԫ��
Status PrintN(SqStack S)
{
	//��ջ���ȿ�ʼ���Ԫ��
	if(S.base==S.top)	//���ջ�� 
	{
		printf("��ջΪ��");
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
	InitStack(S);	//��ʼ��
	for(int i=1;i<=10;i++)	//����ջ��Ԫ�� 
	{
		Push(S,i);
	}
	PrintN(S);	//��ӡ��ջ�����е�Ԫ�� 
	printf("\n");
	GetTop(S,e);	//�õ�ջ��Ԫ�� 
	printf("%d",e); 
	
	Pop(S,e);	//ɾ��ջ��Ԫ��
	printf("\n");
	PrintN(S); 

	return 0;
}
