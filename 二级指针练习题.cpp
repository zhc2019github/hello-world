#include<iostream>
#include<cwchar>
#include<windows.h>
#include<vector>
#include<string>
#include <fstream>
using namespace std;


	 //����ڵ����ݽṹ���������ڵ�
//#pragma pack(1)
//	 typedef char TElemType ;
//	 typedef struct strBitNode
//	 {
//		 TElemType data;
//		 struct strBitNode *lchild, *rchild;
//	 }BiTNode, *BiTree;
//
//	 /* ��ǰ������������нڵ��ֵ��һ���ַ���
//	 #��ʾ����������Ķ������� ��ʾ������T.
//	 BiTree��ָ�������ָ��ṹ���ָ��
//	 */
//
//	 void CreateBiTree(BiTree *T)
//	 {
//		 cout << "CreateBiTree start" << endl;
//		 /*T��ָ��ָ���ָ��*/
//		 TElemType ch;
//		 scanf("%c",&ch);
//		 if (ch == '#')
//		 {
//			 *T = NULL;
//		 }
//		 //else if (ch == '$')
//		 //{
//			// cout << "�������������" << endl;
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
//	 /*��������ǰ������ݹ��㷨*/
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
//		//�����������
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
	 //void PreOrderTraverse(BiTree T)//���������������
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
	 //void InOrderTraverse(BiTree T)//���������������
	 //{
		// if (T == NULL)
		//	 return;
		// InOrderTraverse(T->lchild);
		// printf("%c ", T->data);
		// InOrderTraverse(T->rchild);
	 //}
	 //void PostOrderTraverse(BiTree T)//�������
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
		// printf("CreateBiTree start ��%d��\n",++i);
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

/*���Դ���
��ϰ����ָ�룬����ָ��ָ���ָ��
�ñ������ַ�������ֱ�ӷ��ʣ���ָ������ѱ����ĵ�ַ�洢������Ȼ����ָ������������ڼ�ӷ���
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


