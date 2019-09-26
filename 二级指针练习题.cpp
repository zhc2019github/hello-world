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
练习二级指针，就是指向指针的指针
用变量名字访问属于直接访问，用指针变量把变量的地址存储起来，然后用指针变量访问属于间接访问
*/
#include <stdio.h>

int main(){
	int a = 100;
	int *p1 = &a;
	int **p2 = &p1;
	int ***p3 = &p2;

	printf("%d, %d, %d, %d\n", a, *p1, **p2, ***p3);
	printf("&p2 = %#X, p3 = %#X\n", &p2, p3);
	printf("&p1 = %#X, p2 = %#X, *p3 = %#X\n", &p1, p2, *p3);
	printf(" &a = %#X, p1 = %#X, *p2 = %#X, **p3 = %#X\n", &a, p1, *p2, **p3);
	return 0;
}


