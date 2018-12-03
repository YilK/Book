#include <stdio.h>
#include <stdlib.h>
#define LIST_INIT_SIZE 100	//线性表存储空间的初始分配量
#define LISTINCREMENT 20	//线性表存储空间的分配增量
#define OVERFLOW -2 
#define ERROR 0
#define OK 1
typedef int ElemType;
typedef int Status;

//线性表的动态分配顺序存储结构 
typedef struct{
	ElemType *elem;	//存储空间基址
	int length;	//表长
	int listsize;	//当前分配的存储容量 
}SqList;


//顺序表初始化
void InitList_Sq(SqList &L)
{
	L.elem=(ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));	//申请内存空间
	if(!L.elem)	//内存空间申请失败
	{
		exit(OVERFLOW); 
	} 
	L.length=0;	//表长为0
	L.listsize=LIST_INIT_SIZE;	//初始存储容量 
 } 


//向顺序表中插入元素
Status InsertList_Sq(SqList &L,int i,ElemType e)
{
	// i 表示要插入的位置，e 表示要插入的元素
	
	ElemType *newbase,*q,*p;
	//先判断i值合不合法
	if(i<1||i>L.length+1)
		return ERROR;
	//判断顺序表空间是否已满,已满则增加内存分配空间 
	if(L.listsize==L.length)
	{
		/*
		当*ptr非空：若new_size < size,即缩小*ptr所指向的内存空间，该内存块尾部的部分内存被拿掉，
		剩余部分内存的原先内容依然保留；
		若new_size > size,即扩大*ptr所指向的内存空间，如果原先的内存尾部有足够的扩大空间，
		则直接在原先的内存块尾部新增内存，如果原先的内存尾部空间不足，或原先的内存块无法改变大小，
		realloc将重新分配另一块new_size大小的内存，并把原先那块内存的内容复制到新的内存块上。
		*/
		newbase=(ElemType *)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(ElemType));
		L.elem=newbase;
		L.listsize=L.listsize+LISTINCREMENT;	
	 } 
	 q=L.elem+i-1;	//指向要插入的位置
	 p=L.elem+L.length-1;	//最后一个元素的位置
	 for(p;p>=q;p--)
	 {
	 	*(p+1)=*p;//元素向后移动 
	  } 
	 *q=e;	//插入元素
	 L.length++;	//表长加1
	 return OK; 
 } 
 

//删除顺序表中的元素
Status DeleteList_Sq(SqList &L,int i ,ElemType &e)
{
	// i 代表要删除第几个元素，用e返回要删除的元素
	
	ElemType *p,*q;
	//判断i值是否合法
	if(i<1||i>L.length)
	{
		return ERROR;
	}
	q=L.elem+i-1;	//要删除元素的位置
	p=L.elem+L.length-1;
	for(q;q<p;q++)
	{
		*(q)=*(q+1);	
	}
	L.length--;	//表长-1
	return OK; 
 } 


// 查找元素的位置
int LocateElem_Sq(SqList L,ElemType e)
{
	// e 代表了需要查找的元素
	for(int i=1;i<=L.length;i++)
	{
		if(e==*(L.elem+i-1))
		{
			return i;//返回元素所在的位置 
		}
	 }
	return 0;//没有找到则返回0； 
 } 


//合并两个有序的顺序表
void MergeList_Sq(SqList La,SqList Lb,SqList &Lc)
{
	//La,Lb 是两个有序的按值非递减的顺序表
	ElemType *pa,*pb,*pc,*pa_last,*pb_last;
	pc=Lc.elem=(ElemType *)malloc((La.length+Lb.length)*sizeof(ElemType));//分配内存空间 
	if(!Lc.elem)
		exit(OVERFLOW);
	Lc.listsize=Lc.length=La.length+Lb.length;//设置存储容量
	pa=La.elem;//指向第一个元素 
	pb=Lb.elem;//指向第一个元素 
	pa_last=La.elem+La.length-1;//指向最后一个元素 
	pb_last=Lb.elem+Lb.length-1;//指向最后一个元素 
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
	} //循环结束，表明其中有一个顺序表中元素已经全部添加到Lc中了 pa>*pc++=*pb++ 或 pb>Lb.elem+Lb.length-1
	
	//将剩下的元素添加加入顺序表中 
	while(pa<=pa_last)
	{
		*pc++=*pa++;
	}
	while(pb<=pb_last)
	{
		*pc++=*pb++;
	}
 } 


//查找第i个元素
Status GetElem_Sq(SqList L,int i,ElemType &e)
{
	// i 代表查找的是第几个元素，将查找到的元素存储在变量e中
	
	//判断i值是否合法
	if(i<1||i>L.length)
	{
		return ERROR;
	 } 
	e=*(L.elem+i-1);
	return OK;
 } 
 
 
//输出表中所有的数据
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
	InitList_Sq(L1);//初始化L1 
	for(i=1;i<=5;i++)	//插入元素1,2,3,4,5至L1中 
	{
		InsertList_Sq(L1,i,i);
	}
	printf("L1:");
	Print(L1);
	printf("\n");
	
	InitList_Sq(L2);//初始化L2 
	for(i=1;i<=5;i++)//插入元素 2,4,6,8,10至L2中 
	{
		InsertList_Sq(L2,i,i*2);
	 } 
	printf("L2:");
	Print(L2);//输出L2中所有的元素 

	
	//合并两个顺序表
	MergeList_Sq(L1,L2,L3);
	printf("\n合并L1,L2->L3:");
	Print(L3); 
	
	//删除L3中的末尾元素
	DeleteList_Sq(L3,10,e) ;
	printf("\n删除末L3尾元素:");
	Print(L3);
	
	//查找L3第3个元素
	GetElem_Sq(L3,3,f);
	printf("\n第三个元素是:%d",f); 
	
	return 0;
 } 
 
 
 
 
 
 
 
 
 
 
 
 
 
