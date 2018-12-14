//双向链表
//一般我们都构造双向循环链表
#include <stdio.h>
#include <stdlib.h>
#define OVERFLOW -2
#define ERROR 0
#define OK 1
typedef int Status;
typedef int ElemType;
typedef struct DuLNode
{
	ElemType data;	//数据域
	struct DuLNode *next;	//指向后继结点
	struct DuLNode *prior;	//指向前驱结点 
}DuLNode,*DuLinkList;


//创建一个空的双向链表 
void  InitList_Du(DuLinkList &L)
{
	L=(DuLinkList)malloc(sizeof(DuLNode));	//由系统生成一个DuLNodex型的结点，将结点的起始位置赋给指针变量 
	if(!L)	
		exit(OVERFLOW); 
	L->next=L->prior=L;		//指向头结点 
}


//返回双向链表的长度 
int ListLength(DuLinkList L)
{
	int i=0;
	DuLinkList p=L->next;	//p指向第一个结点
	while(p!=L)	//因为时双向循环链表，当p不指向头结点时进入循环 
	{
		i++;
		p=p->next; 
	 } 
	return i;	//返回双向链表的长度 
}


//向链表中插入元素
Status InsertList_Du(DuLinkList &L,int i,ElemType e)
{
	//在第i个位置插入元素e
	DuLinkList s;
	if(i<1||i>ListLength(L)+1)
		return ERROR; 
	int j=0;
	DuLinkList p=L;	//指向头结点
	while(j<i)	//直接找到第i个结点 
	{
		j++;
		p=p->next;
	 } 
	s=(DuLNode*)malloc(sizeof(DuLNode));
	if(!s)
		exit(OVERFLOW);
	//插入节点 
	s->data=e;
	p->prior->next=s;
	s->prior=p->prior;
	p->prior=s;
	s->next=p;
	return OK; 
}


//删除链表中的某个结点
Status DeleteList_Du(DuLinkList &L,int i,ElemType e)
{
	//删除其中的第i个结点，并将数据赋值给e
	if(i<1||i>ListLength(L)) 	//i值不合法
		return ERROR;
	int j=0;
	DuLinkList p=L;	//p指向头结点
	while(j<i)	//找到第i个结点 
	{
		j++;
		p=p->next; 
	 } 
	//删除结点 
	p->prior->next=p->next;
	p->next->prior=p->prior;
	free(p);	//释放此结点 
	return OK; 
 } 

//打印出所有的结点 
void PrintN(DuLinkList L)
{
	if(L->next==L)
		printf("NULL");
	else
	{
		DuLinkList p=L->next;	//指向第一个结点
		while(p!=L)
		{
			printf("%d ",p->data);
			p=p->next;
		 } 
	 }
	printf("\n"); 
}
int main()
{
	int len,e;
	DuLinkList L;
	InitList_Du(L);	//初始化 
	for(int i=1;i<=5;i++)
	{
		InsertList_Du(L,i,i*2);
	}
	len=ListLength(L);	//测试长度 
	printf("%d\n",len);
	PrintN(L); 	//打印出数据
	//删除其中的某些数据
	DeleteList_Du(L,5,e);
	PrintN(L); 

	return OK;

 } 
