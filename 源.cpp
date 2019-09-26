#include<iostream>
#include<cwchar>
#include<windows.h>
#include<vector>
#include<string>
#include <fstream>
using namespace std;
class CExample
{
public:
	CExample()
	{
		cout << "构造函数被调用!!!" << endl;
		pBuffer = NULL;
		nSize = 0;
	}
	CExample(char *p)
	{
		cout << "带参数构造函数被调用!!!" << endl;
		pBuffer = NULL;

		//
		pBuffer = p;
		
		nSize = strlen(p);

	}
	~CExample()
	{
		cout << "析构函数被调用!!!" << endl;
	}
	void Print()
	{
		cout << nSize << endl;
	}
	//拷贝构造函数和赋值运算符的写法
private:
	CExample(const CExample& test)
	{
		cout << "拷贝构造函数被调用!!!" << endl;
		int length = strlen(test.pBuffer);
		pBuffer = new char[length+1];
	}
	CExample& operator =(const CExample& Rightside)
	{
		cout << "赋值函数被调用!!!" << endl;
		//不要返回临时变量的引用或者指针，不要对常量的地址使用delete
		// (1) 检查自赋值
		if (this == &Rightside)//代表的不是引用，代表的是地址
			return *this;
		// (2) 释放原有的内存资源
		delete pBuffer;
		pBuffer = NULL;
		// （3）分配新的内存资源，并复制内容
		int length = strlen(Rightside.pBuffer);
		pBuffer = new char[length + 1];
		// （4）返回本对象的引用
		return *this;
	}
private:
	char *pBuffer; //类的对象中包含指针,指向动态分配的内存资源
	int nSize;
};

int maxin(int a[100])
{
	return *a;
}

/*用指向指针的指针的方法对5个字符串排序并输出*/
#define _CRT_SECURE_NO_WARNINGS 1

	void sort(char **p)
	{
		char **q, **s, *t;
		for (q = p; q < p + 4; q++)
		{
			for (s = q + 1; s < p + 5; s++)
			{
				if (strcmp(*q, *s) > 0)
				{
					t = *q;
					*q = *s;
					*s = t;
				}
			}
		}
	}
	int max1(int a, int b)
	{
		return 12;
	}
#pragma pack(5)
	class Test
	{
	public :
		virtual  void Print()
		{
			 cout << "virtual class method" << endl;
		}
	private:
		char a;
		int b;

	};

	struct sample
	{
		char a;
		double b;
	};


	typedef struct node1
	{
		
	}S1;
#pragma pop()

	struct testclass
	{
	public:
		 testclass()
		{
		}
		~testclass()
		{
			cout << "father xigou" << endl;
		}
		virtual void print()
		{
			cout<<"I'm father"<<endl;
		}

	private:
		int a;

	};
	struct suntestclass: testclass
	{
	public:
		suntestclass()
		{
		}
		~suntestclass()
		{
			cout << "son xigou" << endl;
		}
	private:

	};

	char* my_strcpy(char* dst,const char *src )
	{
		if (dst == NULL || src == NULL)
		{
			return NULL;
		}
		while (*src != '\0')
		{
			*dst++ = *src++;
		}
		*(dst) = '\0';
		return dst;
		
	}
	/*
	char *,string ,const char* 两两转化
	*/
	/*四个函数构造函数，析构函数，拷贝构造，赋值运算符*/


	class Complex
	{
	public:
		Complex()
		{
			
		}
		Complex(double real, double img);
		~Complex();
		friend Complex operator + (Complex&c1,Complex&c2);
		friend Complex operator -(Complex&c1, Complex&c2);
		friend Complex operator *(Complex&c1, Complex&c2);
		friend Complex operator /(Complex&c1, Complex&c2);
		void display();
	private:
		double real;
		double img;

	};

	Complex::Complex(double r,double i)
	{
		this->real = r;
		this->img = i;
	}
	
	void Complex::display()
	{
		cout << "real is:" << this->real << endl;
		cout << "img  is:" << this->img  << endl;
	}

	Complex::~Complex()
	{
	}

	Complex operator + (Complex&c1, Complex&c2)
	{
		return Complex(c1.real + c2.real, c1.img + c2.img);
	}
	Complex operator -(Complex&c1, Complex&c2)
	{
		return Complex(c1.real - c2.real, c1.img - c2.img);
	}
	Complex operator *(Complex&c1, Complex&c2)
	{
		return Complex((c1.real)*c2.real - (c1.img*c2.img), (c1.real)*c2.img + (c1.img)*c2.real);
	}
	Complex operator /(Complex&c1, Complex&c2)
	{
		return Complex(((c1.real)*c2.real + (c1.img*c2.img)) / (c2.real*c2.real + c2.img*c2.img), (((c1.img)*c2.real - c1.real)*c2.img) / (c2.real*c2.real + c2.img*c2.img));
	}
	class Thing
	{
	public:
		static void  average(float sum, int n);
		static void display();
	private:
		static float discount;
		static float sum;
		static int n;
		static float ave;

	};

	 float Thing::ave=0;
	 int Thing::n = 117;
	 float Thing::discount = 0.98;
	 float Thing::sum = 5 * 23.5 + 12 * 24.56*Thing::discount + 100 * 21.5*Thing::discount;
	 void  Thing::average(float sum, int n)
	 {
		 Thing::ave = sum / n;

	 }
	 void Thing::display()
	 {
		 cout << Thing::ave << endl;
	 }
	 //定义节点数据结构，包含根节点
//#pragma pack(1)
//	 typedef char TElemType ;
//	 typedef struct strBitNode
//	 {
//		 TElemType data;
//		 struct strBitNode *lchild, *rchild;
//	 }BiTNode, *BiTree;
//
//	 /* 按前序输入二叉树中节点的值（一个字符）
//	 #表示空树，构造的二叉链表 表示二叉树T.
//	 BiTree是指针变量，指向结构体的指针
//	 */
//
//	 void CreateBiTree(BiTree *T)
//	 {
//		 cout << "CreateBiTree start" << endl;
//		 /*T是指向指针的指针*/
//		 TElemType ch;
//		 scanf("%c",&ch);
//		 if (ch == '#')
//		 {
//			 *T = NULL;
//		 }
//		 //else if (ch == '$')
//		 //{
//			// cout << "二叉树输入完毕" << endl;
//			// return;
//		 //}
//		 else
//		 {
//			 *T = (BiTree)malloc(sizeof(BiTNode));
//			 if (!*T)
//			 {
//				 exit(1);
//			 }
//			 (*T)->data = ch;
//			 CreateBiTree(&(*T)->lchild);
//			 CreateBiTree(&(*T)->rchild);
//		 }
//		 cout << "CreateBiTree end" << endl;
//	 }
//	 /*二叉树的前序遍历递归算法*/
//	 void PreOrderTraverse(BiTree T)
//	 {
//		 if (NULL == T)
//		 {
//			 return;
//		 }
//		 printf("%c\n",T->data);
//		 PreOrderTraverse(T->lchild);
//		 PreOrderTraverse(T->rchild);
//		 return;
//	 }
//
//	int main()
//	{
//		/*strBitNode temp;
//		strBitNode *p = &temp;
//		strBitNode * *T=&p;*/
//		BiTree T;
//
//		CreateBiTree(&T);
//		cout << "creat bit tree finished!!!" << endl;
//		//调用输出函数
//		PreOrderTraverse(T);
//
//
//		
//		
//		return 0;
//	}
#include<stdio.h>
#include<stdlib.h>
	 //typedef struct BiTNode
	 //{
		// char data;
		// struct BiTNode *lchild, *rchild;
	 //}BiTNode, *BiTree;
	 //void PreOrderTraverse(BiTree T)//二叉树的先序遍历
	 //{
		// cout << "PreOrderTraverse start" << endl;
		// if (T == NULL)
		// {
		//	 cout << "# PreOrderTraverse end" << endl;
		//	 return;
		// }
		//	 
		// printf("%c ", T->data);
		// PreOrderTraverse(T->lchild);
		// PreOrderTraverse(T->rchild);
		// cout << "PreOrderTraverse end" << endl;
	 //}
	 //void InOrderTraverse(BiTree T)//二叉树的中序遍历
	 //{
		// if (T == NULL)
		//	 return;
		// InOrderTraverse(T->lchild);
		// printf("%c ", T->data);
		// InOrderTraverse(T->rchild);
	 //}
	 //void PostOrderTraverse(BiTree T)//后序遍历
	 //{
		// if (T == NULL)
		//	 return;
		// PostOrderTraverse(T->lchild);
		// PostOrderTraverse(T->rchild);
		// printf("%c ", T->data);
	 //}
	 //int i = 0;
	 //void CreateBiTree(BiTree *T)
	 //{
		// printf("CreateBiTree start 第%d次\n",++i);
		// char ch;
		// scanf("%c", &ch);
		// if (ch == '#')
		//	 *T = NULL;
		// else if (ch ==13||ch==10)
		// {
		//	 
		// }
		// else
		// {
		//	 *T = (BiTree)malloc(sizeof(BiTNode));
		//	 if (!*T)
		//		 exit(-1);
		//	 (*T)->data = ch;
		//	 CreateBiTree(&(*T)->lchild);
		//	 CreateBiTree(&(*T)->rchild);
		// }
		// cout << "CreateBiTree end" << endl;
	 //}
	 //int main()
	 //{

		// BiTree T;
		// CreateBiTree(&T);
		// PreOrderTraverse(T);
		// //InOrderTraverse(T);
		// //PostOrderTraverse(T);
		// return 0;
	 //}

/*测试代码
练习结构体指针的使用
定义一个学生结构体，里面有姓名，学号，成绩，生日，生日本身又是一个结构体
*/
	 struct strAge
	 {
		 int year;
		 int month;
		 int day;
	 };
	 struct strStudent
	 {
		 char name[20];
		 int number;
		 float score;
		 struct strAge stuAge;
	 };
	 int main()
	 {
		 strStudent zhc;
		 strStudent *p = NULL;
		 p = &zhc;
		 strcpy(p->name,"zhanghuaichao");
		 p->number = 160718874;
		 p->score = 100;
		 p->stuAge.year = 1990;
		 p->stuAge.month = 5;
		 p->stuAge.day = 4;
		 //输出对应的值
		 printf("name:%s\n", p->name);
		 printf("number:%d\n", p->number);
		 printf("score:%f\n", p->score);
		 printf("age:%d-%d-%d\n", p->stuAge.year, p->stuAge.month, p->stuAge.day);
		 return 0;
	 }



//typedef struct _RECODER_VALUE_STRU
//{
//	int Id;
//	int Age;
//}RECODER_VALUE_STRU;
//
//class recorder
//{
//public:
//		recorder()
//		{
//			m_stru_RecValue.Id = -1;
//			m_stru_RecValue.Age = -1;
//			m_pRecValue = &m_stru_RecValue;
//
//			m_paddr = new char[100];
//			memset(m_paddr, 0x00, 100);
//
//			printf("默认 construct recorder->&m_stru_RecValue: %x,\t m_pRecValue: %x\t m_paddr: %x\n", &m_stru_RecValue, m_pRecVa
//				lue, m_paddr);
//		}
//
//	//拷贝构造函数
//recorder(const recorder &recorder)
//{
//	m_stru_RecValue.Id = -1;
//	m_stru_RecValue.Age = -1;
//	m_stru_RecValue = recorder.m_stru_RecValue;
//	m_pRecValue = &m_stru_RecValue;
//																																　　
//	m_paddr = new char[100];
//	memset(m_paddr, 0x00 ,100);
//	memcpy(m_paddr, recorder.m_paddr, strlen(recorder.m_paddr));
//																																																				　　
//	printf("拷贝 construct recorder->&m_stru_RecValue: %x\t m_pRecValue: %x\t m_paddr: %x\n",&m_stru_RecValue, m_pRecValue, m_paddr);
//}
//																																																																　　
//	//构造函数
//	recorder(int iId, int iAge)
//	{
//		m_stru_RecValue.Id = iId;
//		m_stru_RecValue.Age = iAge;
//		m_pRecValue = &m_stru_RecValue;
//
//		m_paddr = new char[100];
//		memset(m_paddr, 0x00, 100);
//		memcpy(m_paddr, &iAge, sizeof(int));
//
//		printf("construct recorder->&m_stru_RecValue: %x \t m_pRecValue: %x\t m_paddr: %x\n", &m_stru_RecValue, m_pRecValue,m_paddr);
//	}
//
//	~recorder()
//	{
//		cout<<"recorder 析构"<<endl;
//		if(m_paddr != NULL)
//		{
//			delete m_paddr;
//			m_paddr =NULL;
//		}
//	}
//
//public:
//	RECODER_VALUE_STRU m_stru_RecValue;//存储记录信息的结构体 
//	void* m_pRecValue;//每条记录的值
//	char *m_paddr;
//};
//
//int main()
//{
//	cout << "测试默认构造函数" << endl << endl;
//	recorder btest;
//	recorder btest1(btest);
//
//	printf("非参：btest ->&m_stru_RecValue: %x\t addr: %x\t m_paddr: %x\n", &btest.m_stru_RecValue, btest.m_pRecValue, btest.m_paddr);
//	printf("非参：btest1->&m_stru_RecValue: %x\t addr: %x\t m_paddr: %x\n", &btest1.m_stru_RecValue, btest1.m_pRecValue, btest1.m_paddr);
//
//
//	cout << endl << "测试带参数的构造函数" << endl << endl;
//
//
//	recorder btest2(1, 100);
//	recorder btest3(btest2);
//	printf("带参：btest2->m_stru_RecValue: %x\t m_pRecValue: %x\t, m_paddr: %x\n", &btest2.m_stru_RecValue, btest2.m_pRecValue, btest2.m_
//		paddr);
//	printf("带参：btest3->m_stru_RecValue: %x\t m_pRecValue: %x\t, m_paddr: %x\n", &btest3.m_stru_RecValue, btest3.m_pRecValue, btest3.m_
//		paddr);
//
//
//	return 0;
//}