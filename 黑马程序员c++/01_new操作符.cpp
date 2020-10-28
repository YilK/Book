#include <iostream>

using namespace std;
//1.new的基本语法
int* func()
{
	//在堆区创建整型的数据
	//new返回是该数据类型的指针
	int *p=new int(10);
	return p;
}
void test01()
{
	int *p=func();
	cout<<*p<<endl;
	delete p;//释放堆区的数据

}
//2.在堆区利用new开辟数组
void test02()
{
	int* arr=new int[10];
	for(int i=0;i<10;i++)
	{
		arr[i]=i+100;
	}
	for(int i=0;i<10;i++)
		cout<<arr[i]<<endl;
	//释放数组delete后加[]
	delete[] arr;
}

int main(int argc, char *argv[]) {
	test01();
}