// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<string>
#define N 9//控制个数
using namespace std;
/*结构体*/
typedef struct NameInfomation
{
	char name[100];
	int num;
	NameInfomation *next;
}nameinfo;

/*声明函数*/
bool CheckIt(nameinfo *head, char searchWord[100]);
void AddName(nameinfo *head, nameinfo *last, char name[100]);

int HadItFound = 0;
int main()
{
	char temp[100];
	int max = 0;
	nameinfo *head;
	nameinfo *last;
	nameinfo *p2;
	
	head = (nameinfo*)malloc(sizeof(nameinfo));//初始化链表，分配内存给表头
	head->num = 0;
	head->next = NULL;
	last = head;
	nameinfo *temp1;
	nameinfo *ptrmax=head;

	/*读入数据，没读过的加入链表，读过的把对应计数器+1*/
	for ( int i = 0; i < N; i++)
	{
		cout << "enter:" << endl;
		cin >> temp;
;		if (i==0)
		{
	        p2 = (nameinfo*)malloc(sizeof(nameinfo));
			strcpy_s(p2->name, temp);
	        p2->num = 1;
	        p2->next = NULL;
	        head->next = p2;
			last = p2;
			i++;
			//cout << p2->name<<"/p2\n";
			continue;
		}
		else
		{
			AddName(head, last, temp);
			if (HadItFound==0)
			{
				last = last->next;
			}
			
		}
	}
	temp1 = head->next;
	/*输出每一项链表，并找出计数器最大的项*/
	for (int j = 1; j < N; j++)
	{
		cout << "name:" << temp1->name << endl << "times:" << temp1->num << endl;
		if (temp1->num>max)
		{
			max = temp1->num;
			ptrmax = temp1;
		}
		if (temp1->next!=NULL)
		{
			temp1 = temp1->next;
		}
		else
		{
			break;
		}
	}

	cout << "\nmax name:" << ptrmax->name << endl << "times:" << ptrmax->num << endl;//输出最大项
	system("pause");
}
/*检查新数据是否与已有数据重复，重复则计数器+1，不重复返回真值告知新建链表*/
bool CheckIt(nameinfo *head, char searchWord[100])
{
	nameinfo *p = head->next;
	HadItFound = 0;
	//cout <<"searchWord:"<< searchWord<<endl;
	for (int i = 0; i < N; i++) {
		if (strcmp(p->name,searchWord)==0)
		{
			p->num++;
			p = p->next;
			HadItFound++;
			//cout << "cha dao le\n";
			return false;
		}
		else
		{
			if (p->next==NULL&&HadItFound==0)
			{
				//cout << "tian jia le\n";
				return true;
			}
			else
			{
				p = p->next;
				//cout << "xiang hou cha\n";
				continue;
				
			}
		}
	}
	return false;
}

/*新建链表*/
void AddName(nameinfo *head, nameinfo *last, char name[100])
{
	nameinfo *p1;
	//cout << name<<"&";
	bool NeedAdd = CheckIt(head, name);
	if (NeedAdd)
	{
		
		p1 = (nameinfo*)malloc(sizeof(nameinfo));
		last->next = p1;
		strcpy_s(p1->name, name);
		//cout << p1->name;
		//cout << last->name;
		//system("pause");
		p1->num = 1;
		p1->next = NULL;
		
        
	}

}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息g0
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
