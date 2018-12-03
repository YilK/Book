#include <stdio.h>
#include <stdlib.h>
#define LIST_INIT_SIZE 100	//���Ա�洢�ռ�ĳ�ʼ������
#define LISTINCREMENT 20	//���Ա�洢�ռ�ķ�������
#define OVERFLOW -2 
#define ERROR 0
#define OK 1
typedef int ElemType;
typedef int Status;

//���Ա�Ķ�̬����˳��洢�ṹ 
typedef struct{
	ElemType *elem;	//�洢�ռ��ַ
	int length;	//��
	int listsize;	//��ǰ����Ĵ洢���� 
}SqList;


//˳����ʼ��
void InitList_Sq(SqList &L)
{
	L.elem=(ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));	//�����ڴ�ռ�
	if(!L.elem)	//�ڴ�ռ�����ʧ��
	{
		exit(OVERFLOW); 
	} 
	L.length=0;	//��Ϊ0
	L.listsize=LIST_INIT_SIZE;	//��ʼ�洢���� 
 } 


//��˳����в���Ԫ��
Status InsertList_Sq(SqList &L,int i,ElemType e)
{
	// i ��ʾҪ�����λ�ã�e ��ʾҪ�����Ԫ��
	
	ElemType *newbase,*q,*p;
	//���ж�iֵ�ϲ��Ϸ�
	if(i<1||i>L.length+1)
		return ERROR;
	//�ж�˳���ռ��Ƿ�����,�����������ڴ����ռ� 
	if(L.listsize==L.length)
	{
		/*
		��*ptr�ǿգ���new_size < size,����С*ptr��ָ����ڴ�ռ䣬���ڴ��β���Ĳ����ڴ汻�õ���
		ʣ�ಿ���ڴ��ԭ��������Ȼ������
		��new_size > size,������*ptr��ָ����ڴ�ռ䣬���ԭ�ȵ��ڴ�β�����㹻������ռ䣬
		��ֱ����ԭ�ȵ��ڴ��β�������ڴ棬���ԭ�ȵ��ڴ�β���ռ䲻�㣬��ԭ�ȵ��ڴ���޷��ı��С��
		realloc�����·�����һ��new_size��С���ڴ棬����ԭ���ǿ��ڴ�����ݸ��Ƶ��µ��ڴ���ϡ�
		*/
		newbase=(ElemType *)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(ElemType));
		L.elem=newbase;
		L.listsize=L.listsize+LISTINCREMENT;	
	 } 
	 q=L.elem+i-1;	//ָ��Ҫ�����λ��
	 p=L.elem+L.length-1;	//���һ��Ԫ�ص�λ��
	 for(p;p>=q;p--)
	 {
	 	*(p+1)=*p;//Ԫ������ƶ� 
	  } 
	 *q=e;	//����Ԫ��
	 L.length++;	//����1
	 return OK; 
 } 
 

//ɾ��˳����е�Ԫ��
Status DeleteList_Sq(SqList &L,int i ,ElemType &e)
{
	// i ����Ҫɾ���ڼ���Ԫ�أ���e����Ҫɾ����Ԫ��
	
	ElemType *p,*q;
	//�ж�iֵ�Ƿ�Ϸ�
	if(i<1||i>L.length)
	{
		return ERROR;
	}
	q=L.elem+i-1;	//Ҫɾ��Ԫ�ص�λ��
	p=L.elem+L.length-1;
	for(q;q<p;q++)
	{
		*(q)=*(q+1);	
	}
	L.length--;	//��-1
	return OK; 
 } 


// ����Ԫ�ص�λ��
int LocateElem_Sq(SqList L,ElemType e)
{
	// e ��������Ҫ���ҵ�Ԫ��
	for(int i=1;i<=L.length;i++)
	{
		if(e==*(L.elem+i-1))
		{
			return i;//����Ԫ�����ڵ�λ�� 
		}
	 }
	return 0;//û���ҵ��򷵻�0�� 
 } 


//�ϲ����������˳���
void MergeList_Sq(SqList La,SqList Lb,SqList &Lc)
{
	//La,Lb ����������İ�ֵ�ǵݼ���˳���
	ElemType *pa,*pb,*pc,*pa_last,*pb_last;
	pc=Lc.elem=(ElemType *)malloc((La.length+Lb.length)*sizeof(ElemType));//�����ڴ�ռ� 
	if(!Lc.elem)
		exit(OVERFLOW);
	Lc.listsize=Lc.length=La.length+Lb.length;//���ô洢����
	pa=La.elem;//ָ���һ��Ԫ�� 
	pb=Lb.elem;//ָ���һ��Ԫ�� 
	pa_last=La.elem+La.length-1;//ָ�����һ��Ԫ�� 
	pb_last=Lb.elem+Lb.length-1;//ָ�����һ��Ԫ�� 
	while(pa<=pa_last && pb<=pb_last)
	{
		if(*pa <= *pb)
		{
			*pc++=*pa++; 
		}
		else
		{
			*pc++=*pb++;
		}
	} //ѭ������������������һ��˳�����Ԫ���Ѿ�ȫ����ӵ�Lc���� pa>*pc++=*pb++ �� pb>Lb.elem+Lb.length-1
	
	//��ʣ�µ�Ԫ����Ӽ���˳����� 
	while(pa<=pa_last)
	{
		*pc++=*pa++;
	}
	while(pb<=pb_last)
	{
		*pc++=*pb++;
	}
 } 


//���ҵ�i��Ԫ��
Status GetElem_Sq(SqList L,int i,ElemType &e)
{
	// i ������ҵ��ǵڼ���Ԫ�أ������ҵ���Ԫ�ش洢�ڱ���e��
	
	//�ж�iֵ�Ƿ�Ϸ�
	if(i<1||i>L.length)
	{
		return ERROR;
	 } 
	e=*(L.elem+i-1);
	return OK;
 } 
 
 
//����������е�����
void Print(SqList L)
{
	int i;
	for(i=0;i<L.length;i++)
	{
		printf("%d ",*(L.elem+i)); 
	} 
	 
}


int main()
{
	int i;
	ElemType e,f;
	SqList L1,L2,L3;
	InitList_Sq(L1);//��ʼ��L1 
	for(i=1;i<=5;i++)	//����Ԫ��1,2,3,4,5��L1�� 
	{
		InsertList_Sq(L1,i,i);
	}
	printf("L1:");
	Print(L1);
	printf("\n");
	
	InitList_Sq(L2);//��ʼ��L2 
	for(i=1;i<=5;i++)//����Ԫ�� 2,4,6,8,10��L2�� 
	{
		InsertList_Sq(L2,i,i*2);
	 } 
	printf("L2:");
	Print(L2);//���L2�����е�Ԫ�� 

	
	//�ϲ�����˳���
	MergeList_Sq(L1,L2,L3);
	printf("\n�ϲ�L1,L2->L3:");
	Print(L3); 
	
	//ɾ��L3�е�ĩβԪ��
	DeleteList_Sq(L3,10,e) ;
	printf("\nɾ��ĩL3βԪ��:");
	Print(L3);
	
	//����L3��3��Ԫ��
	GetElem_Sq(L3,3,f);
	printf("\n������Ԫ����:%d",f); 
	
	return 0;
 } 
 
 
 
 
 
 
 
 
 
 
 
 
 
