#include <stdio.h> 
#include <stdlib.h>
#define OVERFLOW -2
#define OK 1
#define ERROR -1
typedef int ElemType; 
typedef int Status;

typedef struct LNode{
	ElemType data;	//数据域
	struct LNode *next;	//指针域 
}LNode,*LinkList; 


//构造一个空的循环链表 
void InitList(LinkList &L)
{
	L=(LinkList)malloc(sizeof(LNode));	//由系统生成一个LNode型的结点，同时将结点的起始位置赋值给指针变量L
	if(!L)
		exit(OVERFLOW);
	L->next=L; //头结点的指针域指向头结点 
}

//计算循环链表的长度
int ListLength_L(LinkList L)
{
	LinkList p=L->next;	//p指向头结点
	int j=0;	//表长 
	while(p!=L)
	{
		p=p->next;
		j++;
	 } 
	return j;
 } 
 
//插入元素
Status InsertList_L(LinkList &L,int i,ElemType e)
{
	//在表中的第i个位置插入元素e
	
	if (i<1||i>ListLength_L(L)+1)	//i值不合法 
	{
		return ERROR;
	}
	LinkList s,p=L->next;	//p指向头结点
	int j=0;
	while(j<i-1)	//找到位置为i-1的结点
	{
		p=p->next;
		j++; 
	 } 
	//插入结点
	s=(LinkList)malloc(sizeof(LNode));
	if(!s)
		exit(OVERFLOW);
	s->data=e;
	s->next=p->next;
	p->next=s;
	if(p==L)	//如果插入的位置是在表尾
		L=s;	//尾指针指向末尾节点
	return OK; 
	 
 } 
 
//删除元素
Status DeleteList_L(LinkList &L,int i,ElemType &e)
{
	//删除第i个结点，并将删除的元素赋值给e
	if(i<1||i>ListLength_L(L))	//i值不合法 
	{
		return ERROR; 
	 } 
	LinkList q,p=L->next;	//p指向头结点 
	int j=0;
	while(j<i-1)//找到第i-1个结点 
	{
		p=p->next;
		j++; 
	}
	//删除结点 
	q=p->next;p->next=q->next;
	e=p->data;
	if(L==q)	//如果删除的是最后一个结点
		L=p;	//尾指针指向末尾节点
	return OK; 
	 
 } 
 
 
 //寻找结点
Status GetElem_L(LinkList L,int i,ElemType &e)
{
	//查找第i个元素e
	if(i<1||i>ListLength_L(L))	//i值不合法
		return ERROR;
	LinkList p=L->next->next;	//指向第一个结点
	int j=1;
	while(j<i)
	{
		j++;
		p=p->next;
	 }
	e=p->data;
	return OK; 	 
} 

//合并两个循环链表 
void MergeList_L(LinkList &La,LinkList &Lb,LinkList &Lc)
{
	//将B加入到A的尾部 
	LinkList pa,pb; 
	pa=La->next;	//指向La的头结点
	pb=Lb->next; 	//指向Lb的头结点 
	//合并操作 
	La->next=pb->next;	//将La指向B表的第一个结点
	Lb->next=pa;	//Lb指向A表的头结点
	free(pb);	//释放B表的头结点
	Lc=La=Lb; 
}
//打印输出循环链表
void PrintN(LinkList L)
{
	LinkList p=L->next->next;	//指向第一个结点 
	while(p!=L)
	{
		printf("%d ",p->data);
		p=p->next;
	 } 
	printf("%d ",p->data) ;
	printf("\n");
 } 
 
  
int main()
{
	int e;
	LinkList L1,L2,L3;
	InitList(L1);
	InitList(L2);
	for(int i=1;i<=5;i++)
	{
		InsertList_L(L1,i,i);
		InsertList_L(L2,i,i*2);
	}
	PrintN(L1);
	PrintN(L2);
	MergeList_L(L1,L2,L3);//合并 
	PrintN(L3);
	DeleteList_L(L3,3,e); //删除
	PrintN(L3);
	GetElem_L(L3,3,e);//查找元素 
	printf("%d",e); 
	return 0; 
 } 

