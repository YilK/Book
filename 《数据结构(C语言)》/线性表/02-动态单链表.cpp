#include <stdio.h>
#include <stdlib.h>
#define OVERFLOW -2
#define ERROR -1 
#define OK 1
typedef int ElemType; 
typedef int Status; 
//���Ա�Ķ�̬������洢�ṹ
typedef struct LNode{
	ElemType data;	//������
	struct LNode *next;	//ָ���� 
}LNode,*LinkList;
//	typedef struct LNode LNode; //����LNode���൱��struct LNode
//	typedef struct LNode * LinkList; //ͬ��LinkList���൱��struct LNode * ��һ��struct LNode���͵�ָ�룩 


//��������ͷ���Ŀյĵ����� 
void InitList_L(LinkList &L)
{
	L=(LinkList)malloc(sizeof(LNode));	//��ϵͳ��һ��LNode�͵Ľ�㣬ͬʱ���ýڵ����ʼλ�ø���ͷָ��L
	if(!L)
		exit(OVERFLOW); 
	L->next=NULL;	//ͷ����ָ����Ϊ�� 
 } 
 
 
 //���ҵ�i���ڵ�
Status GetElem_L(LinkList L,int i,ElemType &e)
{
	//��ͷ�ڵ�ĵ����� 
	// i ��ʾ�ڼ���Ԫ�أ���ֵ����e
	 
	LinkList p;
	int j=1;
	p=L->next;	//pָ���һ�����
	while(p&&j<i)
	{
		p=p->next;
		j++;
	 } 
	if(!p||j>i)	//iֵ���Ϸ�---i����������ôѭ��������pΪ�գ�i<1,jһ��ʼ��=1��ôj>i 
		return ERROR;
	e=p->data;	//ȡ��Ԫ�� 
	return OK;
 } 
 
 
 //������
 Status ListInsert_L(LinkList &L,int i,ElemType e)
 {
 	//i ��ʾҪ�����λ�ã�e��ʾҪ�����Ԫ��
 	LinkList p,s;
 	int j=0;
 	p=L;	//pָ��ͷ���
	while(p&&j<i-1)	//��Ҫ�ҵ���λ�õ�ǰһ����� 
	{
		p=p->next;
		j++;
	 } 
	 
	if(!p && j>i-1)//iֵ���Ϸ�(1<=i<=��+1) 
		return ERROR;
		
	s=(LinkList)malloc(sizeof(LNode));
	if(!s)
		exit(OVERFLOW);
	//������
	s->data=e; 
	s->next=p->next;
	p->next=s; 
	return OK; 
  } 
  

//ɾ������ĳ��Ԫ��
Status ListDelete_L(LinkList &L,int i,ElemType &e)
{
	//i ��ʾҪɾ������λ�ã���e��������ֵ
	LinkList p,q;
	int j=0;
	p=L;	//pָ��ͷ���
	while(p->next&&j<i-1)//�ҵ���i-1����㣬���ҵ�i����㲻��Ϊ�� 
	{
		p=p->next;
		j++;
	 } 
	if(!(p->next)&&j>i-1)//iֵ���Ϸ� (1<=i<=��) 
		return ERROR;
	//ɾ����� 
	q=p->next;p->next=q->next;
	e=q->data;	//ȡ��Ԫ�� 
	free(q); 
	return OK;
 } 
 
 //����һ����ͷ��������(��λ��)
 void CreatList_L1(LinkList &L,int n)
 {
 	//n ��ʾ������ٸ�Ԫ��
 	printf("\n��λ������\n");
 	LinkList s;
	L=(LinkList)malloc(sizeof(LNode));	//	��ϵͳ��һ��LNode�͵Ľ�㣬ͬʱ���ýڵ����ʼλ�ø���ͷָ��L
	if(!L)
		exit(OVERFLOW);
	L->next=NULL;	//�յĵ����� 
	for(int i=1;i<=n;i++)
	{
		s=(LinkList)malloc(sizeof(LNode));//����һ����㣬�������ĵ�ַ����s 
		if(!s)
			exit(OVERFLOW);
		scanf("%d",&s->data);
		//��λ��---Խ�Ȳ���Ľ����Խ����
		//���µĽ����뵽��ͷ 
		s->next=L->next; 
		L->next=s; 
	 } 
 }
 
//����������λ�� 
 void CreatList_L2(LinkList &L,int n)
 {
 	//��������ͷ���ĵ�����n ��ʾ������ٸ�Ԫ��
 	printf("\n��λ������\n");
 	LinkList s,p;
	L=(LinkList)malloc(sizeof(LNode));	//	��ϵͳ��һ��LNode�͵Ľ�㣬ͬʱ���ýڵ����ʼλ�ø���ͷָ��L
	if(!L)
		exit(OVERFLOW);
	L->next=NULL;	//�յĵ����� 
	p=L;	//pָ��ͷ��� 
	for(int i=1;i<=n;i++)
	{
		s=(LinkList)malloc(sizeof(LNode));//����һ����㣬�������ĵ�ַ����s 
		if(!s)
			exit(OVERFLOW);
		scanf("%d",&(s->data));
		s->next=p->next;p->next=s;p=s;	//�����㣬Ȼ��pָ�����һ����� 
	 } 
 }
 
 
 //��������������ϲ�Ϊһ����������
 void MergeList_L(LinkList La,LinkList &Lb,LinkList &Lc)
 {
 	//La,Lb ��ֵ�ǵݼ�����d 
 	LinkList pa,pb,pc;
	pa=La->next;	//ָ���һ����� 
	pb=Lb->next;
	Lc=pc=La;	//��La��ͷ�����ΪLc��ͷ���
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
	//����ʣ��� 
	pc->next=pa?pa:pb;
	free(Lb);	//�ͷ�Lb��ͷ��� 
	Lb=NULL;	//Lb����ָ���κν�� 
  } 

//��������������е�Ԫ��
void PrintN(LinkList L) 
{
	LinkList p;
	p=L->next;//ָ���һ����� 
	if(!p)
		printf("�õ�����Ϊ��"); 
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
	InitList_L(L1);	//����һ������ͷ���Ŀյĵ�����
	for(int i=1;i<=5;i++)	//��L1�в���Ԫ�� 
	{
		//����1��2��3��4��5 
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
	//L4 ΪL1��L3�ĺϲ�
	printf("\n��L1,L3�ϲ�ΪL4");
	MergeList_L(L1,L3,L4);
	printf("\n");
	printf("L4:");
	PrintN(L4); 
	//��L4����ɾ������
	ListDelete_L(L4,2,e);
	printf("\n") ;
	printf("��L4��ɾ����:%d\n",e);
	printf("ɾ��Ԫ�غ��L4:"); 
	PrintN(L4);
	
	 
	
	
	return 0;
 } 

