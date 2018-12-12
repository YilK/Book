//˫������
//һ�����Ƕ�����˫��ѭ������
#include <stdio.h>
#include <stdlib.h>
#define OVERFLOW -2
#define ERROR 0
#define OK 1
typedef int Status;
typedef int ElemType;
typedef struct DuLNode
{
	ElemType data;	//������
	struct DuLNode *next;	//ָ���̽��
	struct DuLNode *prior;	//ָ��ǰ����� 
}DuLNode,*DuLinkList;


//����һ���յ�˫������ 
void  InitList_Du(DuLinkList &L)
{
	L=(DuLinkList)malloc(sizeof(DuLNode));	//��ϵͳ����һ��DuLNodex�͵Ľ�㣬��������ʼλ�ø���ָ����� 
	if(!L)	
		exit(OVERFLOW); 
	L->next=L->prior=L;		//ָ��ͷ��� 
}


//����˫������ĳ��� 
int ListLength(DuLinkList L)
{
	int i=0;
	DuLinkList p=L->next;	//pָ���һ�����
	while(p!=L)	//��Ϊʱ˫��ѭ��������p��ָ��ͷ���ʱ����ѭ�� 
	{
		i++;
		p=p->next; 
	 } 
	return i;	//����˫������ĳ��� 
}


//�������в���Ԫ��
Status InsertList_Du(DuLinkList &L,int i,ElemType e)
{
	//�ڵ�i��λ�ò���Ԫ��e
	DuLinkList s;
	if(i<1||i>ListLength(L)+1)
		return ERROR; 
	int j=0;
	DuLinkList p=L;	//ָ��ͷ���
	while(j<i)	//ֱ���ҵ���i����� 
	{
		j++;
		p=p->next;
	 } 
	s=(DuLNode*)malloc(sizeof(DuLNode));
	if(!s)
		exit(OVERFLOW);
	//����ڵ� 
	s->data=e;
	p->prior->next=s;
	s->prior=p->prior;
	p->prior=s;
	s->next=p;
	return OK; 
}


//ɾ�������е�ĳ�����
Status DeleteList_Du(DuLinkList &L,int i,ElemType e)
{
	//ɾ�����еĵ�i����㣬�������ݸ�ֵ��e
	if(i<1||i>ListLength(L)) 	//iֵ���Ϸ�
		return ERROR;
	int j=0;
	DuLinkList p=L;	//pָ��ͷ���
	while(j<i)	//�ҵ���i����� 
	{
		j++;
		p=p->next; 
	 } 
	//ɾ����� 
	p->prior->next=p->next;
	p->next->prior=p->prior;
	free(p);	//�ͷŴ˽�� 
	return OK; 
 } 

//��ӡ�����еĽ�� 
void PrintN(DuLinkList L)
{
	if(L->next==L)
		printf("NULL");
	else
	{
		DuLinkList p=L->next;	//ָ���һ�����
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
	InitList_Du(L);	//��ʼ�� 
	for(int i=1;i<=5;i++)
	{
		InsertList_Du(L,i,i*2);
	}
	len=ListLength(L);	//���Գ��� 
	printf("%d\n",len);
	PrintN(L); 	//��ӡ������
	//ɾ�����е�ĳЩ����
	DeleteList_Du(L,5,e);
	PrintN(L); 

	return OK;

 } 
