#include<iostream>
#include<cwchar>
#include<windows.h>
#include<vector>
#include<string>
#include <fstream>
#include <set>
#include <time.h>
using namespace std;
	
/*
单链表的插入和删除比较快，遍历比较慢
现在进行单链表的建立，建立分为两种方法
头插入法，和尾插入法
*/

//链表的数据结构类型包括数据域和指针域
struct Node
{
	int data;
	struct Node *next;
};
/*为啥要用到二级指针的原因是
简单来说，修改头指针则必须传递头指针的地址，否则传递头指针值即可（即头指针本身）。
这与普通变量类似，当需要修改普通变量的值，需传递其地址，否则传递普通变量的值即可
（即这个变量的拷贝）。使用二级指针，很方便就修改了传入的结点一级指针的值。 如果用
一级指针，则只能通过指针修改指针所指内容，却无法修改指针的值，也就是指针所指的内存块。
所以创建链表和销毁链表需要二级指针或者一级指针引用
或者函数参数为空，而直接使用函数返回值的形式，这样的话就可以返回一级指针，老谭的书上
就是这样做的。
*/

/*
头插法建立链表的步骤主要如下：
1.建立一个头节点，并且让其数据域不赋值，指针域赋值为空。
2.新建立一个节点，插在头节点后，具体的操作是，新建立节点
的指针域，用头节点的指针域赋值，然后头节点的指针域用新建立
节点的地址进行赋值。步骤2重复执行n次，建立n个节点
*/
void CreateListHead(struct Node * *L, int n)
{
	struct Node *p;
	int i;
	srand(time(0));
	*L = (struct Node *) malloc(sizeof(Node));
	(*L)->next = NULL;
	for (int i = 0; i < n; i++)
	{
		p = (struct Node *) malloc(sizeof (Node));//内存分配新建立一个节点
		p->data = rand() % 100 + 1;//为新节点的数据域赋值
		p->next = (*L)->next;//为新节点的指针域赋值，指向头节点的下一个节点
		(*L)->next = p;      //插入到表头
	}
}
/*尾插法建立链表的主要步骤如下
尾插法的思路很好理解，就是每一个新建立的元素有个先来后到，
新建立的元素不能插入头部，应该放在尾巴处
1.建立一个头节点，并且让其数据域不赋值，指针域赋值为空。
2.新建立一个节点，插在最后一个节点后，具体的操作是，新建立的
节点放在终端节点后，然后在把终端节点后移动，指向新建立的节点
。步骤2重复执行n次，建立n个节点
*/


void CreateListTail(struct Node * *L, int n)
{
	struct Node *p, *r;
	int i;
	srand(time(0));/*初始化随机数种子*/
	*L = (struct Node *)malloc(sizeof(Node));/*为整个线性表的头指针*/
	r = *L;/*r为指向尾部的节点*/
	for (i = 0; i < n; i++)
	{
		p = (Node*)malloc(sizeof(Node));/*新建立节点*/
		p->data = rand() % 100 + 1;/*对新建立节点的数据赋值*/
		r->next = p;/*将新节点放在终端节点后*/
		r = p;/*终端节点后移动*/

	}
	r->next = NULL;//建立节点完毕，终端节点指针域设置为空
}


/*输出整个链表
输出整个链表的整体思路如下
1.找到头指针，指向头节点的指针
2.使用while循环，循环终止条件是当前节点的指针域为空
前提是含有头节点的情况，
循环体语句，输出当前节点指针域内地址空间的数值，也就是下一个节点的数据域，
所以循环到下一个节点的时候，当前节点已经输出完毕，然后继续输出下一个，
所以该代码是在有头节点的情况下才是正确的。
*/

//这种没有定义新的变量来接收，直接用L变量是有问题的，导致*L被改变了。
//下面再有使用*L的地方，已经不是在头结点位置了。
void OutputList(struct Node**L)
{
	struct Node*p = (*L)->next;
	while (p != NULL)
	{
		cout << p->data << endl;
		p = p->next;
	}
}

/*输出节点参数不需要二重指针，因为不想改变指针变量的值，而只是引用这个指针变量*/
void OutputList_Pointer(struct Node*L)
{
	while (L->next != NULL)
	{
		cout << (L->next)->data << endl;

		L = L->next;
	}
}

/*链表的元素获取*/
int GetElem(struct Node*L, int i, int *e)
{
	struct Node*p = L->next;
	int j = 1;
	while (j < i&&p)
	{
		p = p->next;
		j++;
	}
	if (!p || j>i)
	{
		return -1;
	}
	*e = p->data;
	return 0;
}
/*链表的插入
初始条件：顺序线性表L已经存在，1<=i<=ListLength(L)
操作结果：在L中第i个节点之前插入新的数据元素e,L的长度加1
*/

int ListInsert(struct Node**L, int i, int e)
{
	int j = 1;
	struct Node* p = *L;/*这里需要注意如果是插入到i结点后则*/
	while (j < i&&p)
	{
		p = p->next;
		j++;
	}
	if (!p || j>i)
	{
		cout << "insert failed!!!" << endl;
		return -1;
	}
	struct Node* s = (struct Node*)malloc(sizeof(Node));
	s->data = e;
	s->next = p->next;
	p->next = s;
	cout << "insert success!!!" << endl;
	return 0;
}

int ListInsert_Pointer(struct Node*L, int i, int e)
{
	int j = 1;
	struct Node* p = L;/*这里需要注意如果是插入到i结点后则*/
	while (j < i&&p)
	{
		p = p->next;
		j++;
	}
	if (!p || j>i)
	{
		cout << "insert failed!!!" << endl;
		return -1;
	}
	struct Node* s = (struct Node*)malloc(sizeof(Node));
	s->data = e;
	s->next = p->next;
	p->next = s;
	cout << "insert success!!!" << endl;
	return 0;
}

/*链表进行删除元素
初始条件：顺序线性表L已经存在，1<=i<=ListLength(L)
操作结果：删除L中第i个节点之前的数据元素e,L的长度减1.
*/
int ListDelete(struct Node **L, int i, int *e)
{
	int j;
	struct Node* p;
	struct Node* q;
	p = *L;
	j = 1;
	while (p&&j < i)
	{
		p = p->next;
		j++;
	}
	if (!p || j>i)
	{
		return -1;
	}
	q = p->next;
	p->next = q->next;
	*e = q->data;
	free(q);
	return 0;
}

	int main()
{
		struct Node p;
		struct Node *p1 = &p;
		struct Node **p2 = &p1;
		CreateListHead(p2,5);
		OutputList(p2);
		int a=0;
		if (0 == GetElem(*p2, 2, &a))
		{
			cout << "GetElem Success " <<a<<endl;
		}
		else
		{
			cout << "GetElem Failed!!!" << endl;
		}
		ListInsert(p2, 1, 100);
		ListInsert_Pointer(*p2,1,101);
		OutputList(p2);
		//删除第一个元素
		if (0 == ListDelete(p2, 1, &a))
		{
			cout << "delete success!!! " << a << endl;
		}
		OutputList(p2);
		return 0;
}




