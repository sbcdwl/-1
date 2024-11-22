#include<iostream>
#define MAX 1000
using namespace std;

struct Person//设计联系人{结构体}保存了联系人的[基本数据],包括姓名、性别、年龄、电话、地址
{
	string m_Name;
	int m_Gender;//1：男  2：女
	int m_Age;
	string m_Phone;
	string m_Address;
};

struct AddressBooks//设计通讯录{结构体}，用于保存"联系人结构体[数组]"和"当前保存的联系人的[个数]"
{
	struct Person personArray[MAX];
	int m_Size;
};

void showMenu()//菜单界面{函数}
{
	cout << "1、添加联系人" << endl;
	cout << "2、显示联系人" << endl;
	cout << "3、删除联系人" << endl;
	cout << "4、查找联系人" << endl;
	cout << "5、修改联系人" << endl;
	cout << "6、清空联系人" << endl;
	cout << "0、退出通讯录" << endl;
}

void addPerson(AddressBooks* abs)//添加联系人{函数}
{
	if (abs->m_Size == MAX)
	{
		cout << "满了，别加" << endl;
		return; 
	}
	else
	{
		//添加具体联系人，包括姓名、性别、年龄、电话、地址
		string name;
		cout << "请输入姓名" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;//这里是双层嵌套式的引用，所以看着很麻烦。引用结构体里面的单个数据时，格式为：（用此结构体所创建的变量名）+（->/.）+（你想要引用那个结构体的那个数据）

		int gender;
		cout << "请输入性别" << endl;
		cout << "输入1为男性，输入2为女性" << endl;
		while (true)//用户防止用户乱输数据
		{
			cin >> gender;
			if (gender == 1 || gender == 2)
			{
				abs->personArray[abs->m_Size].m_Gender = gender;
				break;
			}
			cout << "请按要求输入" << endl;//这个不在else里面也可以
		}						

		int age;
		cout << "请输入年龄" << endl;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;

		string phone;
		cout << "请输入电话号码" << endl;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		string address;
		cout << "请输入地址" << endl;
		cin >> address;
		abs->personArray[abs->m_Size].m_Address = address;

		abs->m_Size++;//用于更新通讯录成员，使每次应用的联系人数组能对应得上
		cout << "添加成功" << endl;
		system("pause");
		system("cls");
	}
}

void showPerson(AddressBooks* abs)//显示现有联系人{函数}
{
	if (abs->m_Size == 0)	//判断通讯录人数
	{
		cout << "通讯录空空如也" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "姓名:" << abs->personArray[i].m_Name << "\t\t";
			cout << "性别:" << (abs->personArray[i].m_Gender == 1 ? "男":"女") << "\t\t";//<<运算符的优先级高于三目运算符，因此不加括号，就报错了，<<就找不到自己想要的值；而有了括号，先进行三目，然后输出带引号的字符串，就能被<<接受了
			cout << "年龄:" << abs->personArray[i].m_Age << "\t\t";
			cout << "电话:" << abs->personArray[i].m_Phone << "\t\t";
			cout << "住址:" << abs->personArray[i].m_Address << endl;
		}
	}
	system("pause");
	system("cls");
}

int inExist(AddressBooks* abs, string name)////检测所的联系人是否存在的{函数}，[若存在，返回其位置，若不存在，返回-1]；参数1是存在的人名，参数2是输入的要删除的人名
{
	for (int i = 0; i < abs->m_Size; i++)//遍历数组以查询
	{
		if (abs->personArray[i].m_Name == name)
		{
			return i;
		}
	}
	return -1;
}

void deletePerson(AddressBooks* abs)//删除指定联系人{函数}
{
	cout << "请输入要删除之人的名字" << endl;
	string name;
	cin >> name;
	//函数中调用函数,并用result接收返回值,返回值为要删除的那个人的那个的数组下标；返回值为-1为没查到，反之查到了
	int result = inExist(abs, name);
	if (result != -1)
	{
		//查找到人后，要进行删除操作
		for (int i = result; i < abs->m_Size; i++)
		{
			//数据迁移
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;//用于更新通讯录统计的人数
		cout << "删除成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

void findPerson(AddressBooks* abs)//查找联系人{函数}
{
	string name;
	cout << "请输入要查找的联系人" << endl;
	cin >> name;
	
	int result = inExist(abs, name);//用之前封装好的函数来判断联系人是否存在
	if (result != -1)//找到了
	{
		cout << "姓名:" << abs->personArray[result].m_Name << "\t\t";
		cout << "性别:" << (abs->personArray[result].m_Gender == 1 ? "男" : "女") << "\t\t";
		cout << "年龄:" << abs->personArray[result].m_Age << "\t\t";
		cout << "电话:" << abs->personArray[result].m_Phone << "\t\t";
		cout << "住址:" << abs->personArray[result].m_Address << endl;
	}
	else
	{
		cout << "查找之人不存在" << endl;
	}
	system("pause");
	system("cls");
}

void modifyPerson(AddressBooks* abs)//修改联系人的{函数}
{
	string name;
	cout << "输入你要修改的联系人" << endl;
	cin >> name;

	int result = inExist(abs, name);
	if (result != -1)//找到了要修改的联系人
	{
		cout << "姓名:" << abs->personArray[result].m_Name << "\t\t";//先把找到的那个人的信息打印出来，给用户知道一下
		cout << "性别:" << (abs->personArray[result].m_Gender == 1 ? "男" : "女") << "\t\t";
		cout << "年龄:" << abs->personArray[result].m_Age << "\t\t";
		cout << "电话:" << abs->personArray[result].m_Phone << "\t\t";
		cout << "住址:" << abs->personArray[result].m_Address << endl;

		cout << "请输入你要修改的人的姓名" << endl;
		string name;
		cin >> name;
		abs->personArray[result].m_Name = name;

		cout << "请输入你要修改的人的性别,男1，女2" << endl;
		int gender;
		while (true)//防止用户乱输
		{
			cin >> gender;
			if (gender == 1 || gender == 2)
			{
				abs->personArray[result].m_Gender = gender;
				break;
			}
			else { cout << "请输入正确格式" << endl; }
		}
		abs->personArray[result].m_Gender = gender;

		cout << "请输入你要修改的人的年龄" << endl;
		int age;
		cin >> age;
		abs->personArray[result].m_Age = age;

		cout << "请输入你要修改的人的电话" << endl;
		string phone;
		cin >> phone;
		abs->personArray[result].m_Phone = phone;

		cout << "请输入你要修改的人的住址" << endl;
		string address;
		cin >> address;
		abs->personArray[result].m_Address = address;

		cout << "修改完毕" << endl;;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

void cleanPerson(AddressBooks* abs)//清空联系人函数
{
	abs->m_Size = 0;
	cout << "清除完毕" << endl;
	system("pause");
	system("cls");
}

int main()
{
	AddressBooks abs;	//创建通讯录结构体变量,其中"AddressBooks",是前面创建的结构体，是种[类型]，而"abs"是变量名
	abs.m_Size = 0;	//初始化通讯录中当前人员个数

	int select = 0;//初始化用来放用户选择的数字的地方
	while (true)
	{
		showMenu();//菜单调用
		cin >> select;
		switch (select)
		{
		case 1://添加联系人
			addPerson(&abs);//利用地址传递能改变实参
			break;
		case 2://显示联系人
			showPerson(&abs);
			break;
		case 3://删除联系人
			deletePerson(&abs);
			break;
		case 4://查找联系人
			findPerson(&abs);
			break;
		case 5://修改联系人
			modifyPerson(&abs);
			break;
		case 6://清空联系人
			cleanPerson(&abs);
			break;
		case 0://退出
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	
	system("pause");
	return 0;
}