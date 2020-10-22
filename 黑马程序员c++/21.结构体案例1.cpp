#include <iostream>
#include <string>
using namespace std;
struct student{
	string name;//学生名字
	double score;//考试分数
};
struct teacher{
	string name;	//老师的名字
	student stu[5];	//学生的结构体数组
};
void allocatespace(teacher tarr[],int len)
{
	string tname="老师";
	string sname="学生";
	string nameseed="abcde";
	for(int i=0;i<len;i++)//每一位老师
	{
		tarr[i].name=tname+nameseed[i];
		for(int j=0;j<5;j++)//每一位老师中的每一位学生
		{
			tarr[i].stu[j].name=sname+nameseed[j];
			tarr[i].stu[j].score=j;
		}
	}
}
int main(int argc, char *argv[]) {
	teacher tea[3];//定义了3名老师
	allocatespace(tea,3);
	return 0;
}