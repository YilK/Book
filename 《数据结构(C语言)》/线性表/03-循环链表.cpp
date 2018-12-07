#include <stdio.h> 
#include <stdlib.h>
#define OVERFLOW -2
#define OK 1
#define ERROR -1
typedef int ElemType; 
typedef int Status;

typedef struct LNode{
	ElemType data;	//������
	struct LNode *next;	//ָ���� 
}LNode,*LinkList; 


//����һ���յ�ѭ������ 
void InitList(LinkList &L)
{
	L=(LinkList)malloc(sizeof(LNode));	//��ϵͳ����һ��LNode�͵Ľ�㣬ͬʱ��������ʼλ�ø�ֵ��ָ�����L
	if(!L)
		exit(OVERFLOW);
	L->next=L; //ͷ����ָ����ָ��ͷ��� 
}

//����ѭ������ĳ���
int ListLength_L(LinkList L)
{
	LinkList p=L->next;	//pָ��ͷ���
	int j=0;	//�� 
	while(p!=L)
	{
		p=p->next;
		j++;
	 } 
	return j;
 } 
 
//����Ԫ��
Status InsertList_L(LinkList &L,int i,ElemType e)
{
	//�ڱ��еĵ�i��λ�ò���Ԫ��e
	
	if (i<1||i>ListLength_L(L)+1)	//iֵ���Ϸ� 
	{
		return ERROR;
	}
	LinkList s,p=L->next;	//pָ��ͷ���
	int j=0;
	while(j<i-1)	//�ҵ�λ��Ϊi-1�Ľ��
	{
		p=p->next;
		j++; 
	 } 
	//������
	s=(LinkList)malloc(sizeof(LNode));
	if(!s)
		exit(OVERFLOW);
	s->data=e;
	s->next=p->next;
	p->next=s;
	if(p==L)	//��������λ�����ڱ�β
		L=s;	//βָ��ָ��ĩβ�ڵ�
	return OK; 
	 
 } 
 
//ɾ��Ԫ��
Status DeleteList_L(LinkList &L,int i,ElemType &e)
{
	//ɾ����i����㣬����ɾ����Ԫ�ظ�ֵ��e
	if(i<1||i>ListLength_L(L))	//iֵ���Ϸ� 
	{
		return ERROR; 
	 } 
	LinkList q,p=L->next;	//pָ��ͷ��� 
	int j=0;
	while(j<i-1)//�ҵ���i-1����� 
	{
		p=p->next;
		j++; 
	}
	//ɾ����� 
	q=p->next;p->next=q->next;
	e=p->data;
	if(L==q)	//���ɾ���������һ�����
		L=p;	//βָ��ָ��ĩβ�ڵ�
	return OK; 
	 
 } 
 
 
 //Ѱ�ҽ��
Status GetElem_L(LinkList L,int i,ElemType &e)
{
	//���ҵ�i��Ԫ��e
	if(i<1||i>ListLength_L(L))	//iֵ���Ϸ�
		return ERROR;
	LinkList p=L->next->next;	//ָ���һ�����
	int j=1;
	while(j<i)
	{
		j++;
		p=p->next;
	 }
	e=p->data;
	return OK; 	 
} 

//�ϲ�����ѭ������ 
void MergeList_L(LinkList &La,LinkList &Lb,LinkList &Lc)
{
	//��B���뵽A��β�� 
	LinkList pa,pb; 
	pa=La->next;	//ָ��La��ͷ���
	pb=Lb->next; 	//ָ��Lb��ͷ��� 
	//�ϲ����� 
	La->next=pb->next;	//��Laָ��B��ĵ�һ�����
	Lb->next=pa;	//Lbָ��A���ͷ���
	free(pb);	//�ͷ�B���ͷ���
	Lc=La=Lb; 
}
//��ӡ���ѭ������
void PrintN(LinkList L)
{
	LinkList p=L->next->next;	//ָ���һ����� 
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
	MergeList_L(L1,L2,L3);//�ϲ� 
	PrintN(L3);
	DeleteList_L(L3,3,e); //ɾ��
	PrintN(L3);
	GetElem_L(L3,3,e);//����Ԫ�� 
	printf("%d",e); 
	return 0; 
 } 

