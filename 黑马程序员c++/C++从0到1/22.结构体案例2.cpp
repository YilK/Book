#include <iostream>
#include <string>
using namespace std;
struct hero{
	string name;
	int age;
	string sex;	
};
void sort(hero arr[],int len)
{
	for(int i=len-1;i>0;i--)
	{
		int flag=1;
		for(int j=0;j<i;j++)
		{
			if(arr[j].age>arr[j+1].age)
			{
				hero temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
				flag=0;
			}
		}
		if(flag==1)
			break;
	}
}
void printhero(const hero arr[],int len)
{
	for(int i=0;i<len;i++)
	{
		cout<<arr[i].name<<" "<<arr[i].age<<" "<<arr[i].sex<<endl;
	}
}
int main(int argc, char *argv[]) {
	hero h[5]=
	{
		{"刘备",23,"男"},
		{"关羽",22,"男"},
		{"张飞",20,"男"},
		{"赵云",21,"男"},
		{"貂蝉",19,"女"},
	};
	int len=sizeof(h)/sizeof(h[0]);
	cout<<len<<endl;
	sort(h,len);
	printhero(h, len);
	return 0;
}