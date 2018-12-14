#include <stdio.h>
#include <stdlib.h>
#define OVERFLOW -2
#define ERROR -1 
#define OK 1
typedef int ElemType; 
typedef int Status; 
//线性表的动态单链表存储结构
typedef struct LNode{
	ElemType data;	//数据域
	struct LNode *next;	//指针域 
}LNode,*LinkList;
//	typedef struct LNode LNode; //这里LNode就相当于struct LNode
//	typedef struct LNode * LinkList; //同理，LinkList就相当于struct LNode * （一个struct LNode类型的指针） 


//构建带有头结点的空的单链表 
void InitList_L(LinkList &L)
{
	L=(LinkList)malloc(sizeof(LNode));	//由系统生一个LNode型的结点，同时将该节点的起始位置赋给头指针L
	if(!L)
		exit(OVERFLOW); 
	L->next=NULL;	//头结点的指针域为空 
 } 
 
 
 //查找第i个节点
Status GetElem_L(LinkList L,int i,ElemType &e)
{
	//带头节点的单链表 
	// i 表示第几个元素，将值赋给e
	 
	LinkList p;
	int j=1;
	p=L->next;	//p指向第一个结点
	while(p&&j<i)
	{
		p=p->next;
		j++;
	 } 
	if(!p||j>i)	//i值不合法---i超出表长，那么循环结束后p为空，i<1,j一开始就=1那么j>i 
		return ERROR;
	e=p->data;	//取出元素 
	return OK;
 } 
 
 
 //插入结点
 Status ListInsert_L(LinkList &L,int i,ElemType e)
 {
 	//i 表示要插入的位置，e表示要插入的元素
 	LinkList p,s;
 	int j=0;
 	p=L;	//p指向头结点
	while(p&&j<i-1)	//需要找到该位置的前一个结点 
	{
		p=p->next;
		j++;
	 } 
	 
	if(!p && j>i-1)//i值不合法(1<=i<=表长+1) 
		return ERROR;
		
	s=(LinkList)malloc(sizeof(LNode));
	if(!s)
		exit(OVERFLOW);
	//插入结点
	s->data=e; 
	s->next=p->next;
	p->next=s; 
	return OK; 
  } 
  

//删除表中某个元素
Status ListDelete_L(LinkList &L,int i,ElemType &e)
{
	//i 表示要删除结点的位置，由e来返回其值
	LinkList p,q;
	int j=0;
	p=L;	//p指向头结点
	while(p->next&&j<i-1)//找到第i-1个结点，并且第i个结点不能为空 
	{
		p=p->next;
		j++;
	 } 
	if(!(p->next)&&j>i-1)//i值不合法 (1<=i<=表长) 
		return ERROR;
	//删除结点 
	q=p->next;p->next=q->next;
	e=q->data;	//取出元素 
	free(q); 
	return OK;
 } 
 
 //创建一个带头结点的链表(逆位序)
 void CreatList_L1(LinkList &L,int n)
 {
 	//n 表示输入多少个元素
 	printf("\n逆位序输入\n");
 	LinkList s;
	L=(LinkList)malloc(sizeof(LNode));	//	由系统生一个LNode型的结点，同时将该节点的起始位置赋给头指针L
	if(!L)
		exit(OVERFLOW);
	L->next=NULL;	//空的单链表 
	for(int i=1;i<=n;i++)
	{
		s=(LinkList)malloc(sizeof(LNode));//生成一个结点，并将结点的地址赋给s 
		if(!s)
			exit(OVERFLOW);
		scanf("%d",&s->data);
		//逆位序---越先插入的结点在越后面
		//将新的结点插入到表头 
		s->next=L->next; 
		L->next=s; 
	 } 
 }
 
//创建链表正位序 
 void CreatList_L2(LinkList &L,int n)
 {
 	//建立带有头结点的单链表，n 表示输入多少个元素
 	printf("\n正位序输入\n");
 	LinkList s,p;
	L=(LinkList)malloc(sizeof(LNode));	//	由系统生一个LNode型的结点，同时将该节点的起始位置赋给头指针L
	if(!L)
		exit(OVERFLOW);
	L->next=NULL;	//空的单链表 
	p=L;	//p指向头结点 
	for(int i=1;i<=n;i++)
	{
		s=(LinkList)malloc(sizeof(LNode));//生成一个结点，并将结点的地址赋给s 
		if(!s)
			exit(OVERFLOW);
		scanf("%d",&(s->data));
		s->next=p->next;p->next=s;p=s;	//插入结点，然后p指向最后一个结点 
	 } 
 }
 
 
 //将两个有序链表合并为一个有序链表
 void MergeList_L(LinkList La,LinkList &Lb,LinkList &Lc)
 {
 	//La,Lb 按值非递减排列d 
 	LinkList pa,pb,pc;
	pa=La->next;	//指向第一个结点 
	pb=Lb->next;
	Lc=pc=La;	//用La的头结点作为Lc的头结点
	while(pa&&pb)
	{
		if(pa->data <= pb->data)
		{
			pc->next=pa;
			pc=pa;
			pa=pa->next;
		}
		else
		{
			pc->next=pb;
			pc=pb;
			pb=pb->next;	
		}
	 } 
	//插入剩余段 
	pc->next=pa?pa:pb;
	free(Lb);	//释放Lb的头结点 
	Lb=NULL;	//Lb不在指向任何结点 
  } 

//输出单链表中所有的元素
void PrintN(LinkList L) 
{
	LinkList p;
	p=L->next;//指向第一个结点 
	if(!p)
		printf("该单链表为空"); 
	while(p)
	{
		printf("%d ",p->data); 
		p=p->next;
	 } 
}

int main()
{
	LinkList L1,L2,L3,L4;
	ElemType e;
	
	//L1
	InitList_L(L1);	//创建一个带有头结点的空的单链表
	for(int i=1;i<=5;i++)	//向L1中插入元素 
	{
		//插入1，2，3，4，5 
		ListInsert_L(L1,i,i);
	 } 
	printf("L1:") ;
	PrintN(L1);
	
	//L2
	printf("\n"); 
	CreatList_L1(L2,6);
	printf("L2:");
	PrintN(L2);
	
	//L3
	printf("\n"); 
	CreatList_L2(L3,6);
	printf("L3:");
	PrintN(L3);
	
	
	//L4
	//L4 为L1与L3的合并
	printf("\n将L1,L3合并为L4");
	MergeList_L(L1,L3,L4);
	printf("\n");
	printf("L4:");
	PrintN(L4); 
	//对L4进行删除操作
	ListDelete_L(L4,2,e);
	printf("\n") ;
	printf("从L4中删除了:%d\n",e);
	printf("删除元素后的L4:"); 
	PrintN(L4);
	
	 
	
	
	return 0;
 } 

