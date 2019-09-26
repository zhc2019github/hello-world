#include<iostream>
#include<cwchar>
#include<windows.h>
#include<vector>
#include<string>
#include <fstream>
using namespace std;


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
练习结构体数组指针的使用
定义一个学生结构体，里面有姓名，年龄，性别，学号
*/
struct strStudent
{
	char name[20];
	int age;
	char sex;
	int num;
};

	 /*结构体指针数组的操作*/
	 int main()
	 {
		 struct strStudent stu[3] = { {"zhangchao",30,'M',12}, {"liliang",31,'F',24}, {"kebi",33,'M',46}};
		 struct strStudent *p = stu;
		 for (; p < stu + 3; p++)
		 {
			 printf("name:%s,age:%d,sex:%c,num:%d\n", p->name, p->age, p->sex, p->num);
		 }
		 return 0;
	 }