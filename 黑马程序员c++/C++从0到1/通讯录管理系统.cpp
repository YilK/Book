#include <iostream>
#include <string>
#define MAX 1000//最大人数
using namespace std;
//联系人结构体
struct Person	
{
	string m_name;//姓名
	int m_sex;//性别 1男2女
	int m_age;//年龄
	string m_phone;//电话
	string m_addr;//住址
};
//通讯录结构体
struct addressbooks
{
	struct Person personArray[MAX];//联系人数组
	int m_Size;//通讯录中人员的个数 
};
//菜单界面
void showMenu()
{
	cout << "***************************" << endl;
	cout << "*****  1、添加联系人  *****" << endl;
	cout << "*****  2、显示联系人  *****" << endl;
	cout << "*****  3、删除联系人  *****" << endl;
	cout << "*****  4、查找联系人  *****" << endl;
	cout << "*****  5、修改联系人  *****" << endl;
	cout << "*****  6、清空联系人  *****" << endl;
	cout << "*****  0、退出通讯录  *****" << endl;
	cout << "***************************" << endl;
}
//1.添加联系人信息
void addperson(addressbooks& abs)
{
	if (abs.m_Size == MAX)
	{
		cout << "通讯录已满，无法添加" << endl;
		return;
	}
	else
	{
		cout << "请输入姓名：" << endl;
		cin >> abs.personArray[abs.m_Size].m_name;

		cout << "请输入性别\n1 -- 男\n2 -- 女" << endl;
		cin >> abs.personArray[abs.m_Size].m_sex;

		cout << "请输入年龄：" << endl;
		cin >> abs.personArray[abs.m_Size].m_age;

		cout << "请输入电话：" << endl;
		cin >> abs.personArray[abs.m_Size].m_phone;

		cout << "请输入住址" << endl;
		cin >> abs.personArray[abs.m_Size].m_addr;

		//更新通讯录中的人数
		abs.m_Size++;
		
		cout << "添加成功" << endl;
		system("pause");//请按任意键继续
		system("cls");//清屏
	}
}

//2.显示联系人
void showPerson(addressbooks *abs)
{
	//首先判断通讯录中的人数是否为0；
	if (abs->m_Size == 0)
		cout << "当前人数为0" << endl;
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
			//cout << abs->personArray[i].m_name << " " << abs->personArray[i].m_sex << " " << abs->personArray[i].m_age << " " << abs->personArray[i].m_phone << " " << abs->personArray[i].m_addr<<endl;
		{
			cout << "姓名:" << abs->personArray[i].m_name << "\t";
			if (abs->personArray[i].m_sex == 1)
				cout << "性别:男" << "\t";
			else
				cout<< "性别:女" << "\t";
			cout << "年龄:" << abs->personArray[i].m_age << "\t";
			cout << "电话号码:" << abs->personArray[i].m_phone << "\t";
			cout<<"地址:"<< abs->personArray[i].m_addr << endl;
		}
	}
	system("pause");//请按任意键继续
	system("cls");//清屏
}
//检测联系人是否存在
int isExist(addressbooks* abs, string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArray[i].m_name == name)
			return i;
	}
	return -1;
}
//3.删除联系人
void deletePerson(addressbooks* abs)
{
	cout << "请输入你要删除的联系人：" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		for (int i = ret + 1; i < abs->m_Size; i++)
		{
			abs->personArray[i - 1] = abs->personArray[i];
		}
		abs->m_Size--;
	}
	else
		cout << "查无此人" << endl;
	system("pause");//请按任意键继续
	system("cls");//清屏
}
//4.查找联系人
void findPerson(addressbooks *abs)
{
	cout << "请输入你要查找的联系人：" << endl;
	string name;
	cin >> name;
	//判断指定的联系人是否存在通讯录中
	int i = isExist(abs, name);
	if (i != -1)
	{
		cout << "姓名:" << abs->personArray[i].m_name << "\t";
		if (abs->personArray[i].m_sex == 1)
			cout << "性别:男" << "\t";
		else
			cout << "性别:女" << "\t";
		cout << "年龄:" << abs->personArray[i].m_age << "\t";
		cout << "电话号码:" << abs->personArray[i].m_phone << "\t";
		cout << "地址:" << abs->personArray[i].m_addr << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");//请按任意键继续
	system("cls");//清屏
}
//5.修改联系人
void modifyPerson(addressbooks* abs)
{
	cout << "请输入你要修改的联系人：" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "请输入姓名：" << endl;
		cin >> abs->personArray[ret].m_name;

		cout << "请输入性别\n1 -- 男\n2 -- 女" << endl;
		cin >> abs->personArray[ret].m_sex;

		cout << "请输入年龄：" << endl;
		cin >> abs->personArray[ret].m_age;

		cout << "请输入电话：" << endl;
		cin >> abs->personArray[ret].m_phone;

		cout << "请输入住址" << endl;
		cin >> abs->personArray[ret].m_addr;

		cout << "修改成功！" << endl;
	}
	else
		cout << "查无此人" << endl;
	system("pause");//请按任意键继续
	system("cls");//清屏
}
//6.清空联系人
void cleanPerson(addressbooks* abs)
{
	abs->m_Size = 0;
	cout << "通讯录已清空！" << endl;
	system("pause");//请按任意键继续
	system("cls");//清屏
}
int main()
{
	//创建通讯录的结构体变量
	addressbooks abs;
	//初始化通讯录中人数
	abs.m_Size = 0;
	int select = 0;//创建用户选择输入的变量
	while (true)
	{
		//菜单调用
		showMenu();
		cin >> select;
		switch (select)
		{
		case 1://1、添加联系人
			addperson(abs);
			break;
		case 2://2、显示联系人
			showPerson(&abs);
			break;
		case 3://3、删除联系人
			deletePerson(&abs);
			break;
		case 4://4、查找联系人 
			findPerson(&abs);
			break;
		case 5://5、修改联系人
			modifyPerson(&abs);
			break;
		case 6://6、清空联系人
			cleanPerson(&abs);
			break;
		case 0://0、退出通讯录
			cout << "欢迎下次使用" << endl;
			return 0;//直接退出
			break;
		}
	}
	return 0;
}