#include<iostream>
using namespace std; 
typedef int SElemtype;
typedef struct
{
	int top[2], bot[2];//栈顶和栈底指针
	SElemtype* V;     //栈数组
	int m;            //栈最大可容纳元索个数

}DblStack;
bool initDblStack(DblStack& s, int m)
{
	s.V = new SElemtype[m];
	if (s.V == NULL)
	{
		return false;
	}
	s.top[0] = -1;
	s.bot[0] = -1;
	s.top[1] = m;
	s.bot[1] = m;
	return true;
}
bool isEmpty(DblStack &s, int dir)
{
	if (s.bot[dir] == s.top[dir])
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool isFull(DblStack &s)
{
	if (s.top[1] == s.top[0] + 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool pushDblStack(DblStack& s, int dir, SElemtype& elem)
{
	if (isFull(s))
	{
		return false;
	}
	if (dir == 0)
	{
		s.V[++s.top[0]] = elem;
	}
	else
	{
		s.V[--s.top[1]] = elem;
	}
	return true;
}
bool popDblStack(DblStack& s, int dir, SElemtype& elem)
{
	if (isEmpty(s, dir))
	{
		return false;
	}
	if (dir == 0)
	{
		elem = s.V[s.top[0]--];
	}
	else
	{
		elem = s.V[s.top[1]++];
	}
}
int main()
{
	DblStack s;
	int select;
	while (true)
	{
		cout << "1、初始化双栈表" << endl;
		cout << "2、判断双栈表空" << endl;
		cout << "3、判断双栈表满" << endl;
		cout << "4、入        栈" << endl;
		cout << "5、出        栈" << endl;
		cout << "0、退        出" << endl;
		cout << "请输入你的选项：" << endl;
		cin >> select;
		switch (select)
		{
		case 1:
		{
			cout << "你想创建最大容纳多少元素的栈？" << endl;
			int size;
			cin >> size;
			if (initDblStack(s, size))
			{
				cout << "创建成功！" << endl;
			}
			else
			{
				cout << "创建失败！" << endl;
			}
			system("pause");
			system("cls");
		}
			break;
		case 2:
		{
			cout << "你想判断左栈表0，还是右栈表1？" << endl;
			int dir;
			while (true)
			{
				cin >> dir;
				if (dir == 0 || dir == 1)
					break;
				cout << "请重新输入" << endl;
			}
			if (isEmpty(s, dir))
			{
				cout << "栈表为空！" << endl;
			}
			else
			{
				cout << "栈表不为空！" << endl;
			}
			system("pause");
			system("cls");
		}
			break;
		case 3:
		{
			if (isFull(s))
			{
				cout << "栈表已满！" << endl;
			}
			else
			{
				cout << "栈表未满！" << endl;
			}
			system("pause");
			system("cls");
		}
			break;
		case 4:
		{
			cout << "请输入入栈的数据和入哪个栈表（0或1）" << endl;
			SElemtype elem;
			int dir;
			cin >> elem;
			while (true)
			{
				cin >> dir;
				if (dir == 0 || dir == 1)
					break;
				cout << "栈表选择有误！请输入0或1" << endl;
			}
			if (pushDblStack(s, dir, elem))
			{
				cout << elem << "已入" << dir << "栈" << endl;
			}
			else
			{
				cout << "入栈失败！" << endl;
			}
			system("pause");
			system("cls");
		}
			break;
		case 5:
		{
			cout << "你想对哪个栈表进行出栈操作（0或者1）" << endl;
			int dir;
			SElemtype elem;
			while (true)
			{
				cin >> dir;
				if (dir == 1||dir==0)
					break;
				cout << "请输入0或者1" << endl;
			}
			if (popDblStack(s, dir, elem))
			{
				cout << elem << "已出" << dir << "栈" << endl;
			}
			else
			{
				cout << "出栈失败!" << endl;
			}
			system("pause");
			system("cls");
		}
			break;
		default:
			cout << "欢迎下次使用！" << endl;
			system("pause");
			system("cls");
			return 0;
			break;
		}

	}
}