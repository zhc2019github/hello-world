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
������Ĳ����ɾ���ȽϿ죬�����Ƚ���
���ڽ��е�����Ľ�����������Ϊ���ַ���
ͷ���뷨����β���뷨
*/

//��������ݽṹ���Ͱ����������ָ����
struct Node
{
	int data;
	struct Node *next;
};
/*ΪɶҪ�õ�����ָ���ԭ����
����˵���޸�ͷָ������봫��ͷָ��ĵ�ַ�����򴫵�ͷָ��ֵ���ɣ���ͷָ�뱾����
������ͨ�������ƣ�����Ҫ�޸���ͨ������ֵ���贫�����ַ�����򴫵���ͨ������ֵ����
������������Ŀ�������ʹ�ö���ָ�룬�ܷ�����޸��˴���Ľ��һ��ָ���ֵ�� �����
һ��ָ�룬��ֻ��ͨ��ָ���޸�ָ����ָ���ݣ�ȴ�޷��޸�ָ���ֵ��Ҳ����ָ����ָ���ڴ�顣
���Դ������������������Ҫ����ָ�����һ��ָ������
���ߺ�������Ϊ�գ���ֱ��ʹ�ú�������ֵ����ʽ�������Ļ��Ϳ��Է���һ��ָ�룬��̷������
�����������ġ�
*/

/*
ͷ�巨��������Ĳ�����Ҫ���£�
1.����һ��ͷ�ڵ㣬�������������򲻸�ֵ��ָ����ֵΪ�ա�
2.�½���һ���ڵ㣬����ͷ�ڵ�󣬾���Ĳ����ǣ��½����ڵ�
��ָ������ͷ�ڵ��ָ����ֵ��Ȼ��ͷ�ڵ��ָ�������½���
�ڵ�ĵ�ַ���и�ֵ������2�ظ�ִ��n�Σ�����n���ڵ�
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
		p = (struct Node *) malloc(sizeof (Node));//�ڴ�����½���һ���ڵ�
		p->data = rand() % 100 + 1;//Ϊ�½ڵ��������ֵ
		p->next = (*L)->next;//Ϊ�½ڵ��ָ����ֵ��ָ��ͷ�ڵ����һ���ڵ�
		(*L)->next = p;      //���뵽��ͷ
	}
}
/*β�巨�����������Ҫ��������
β�巨��˼·�ܺ���⣬����ÿһ���½�����Ԫ���и������󵽣�
�½�����Ԫ�ز��ܲ���ͷ����Ӧ�÷���β�ʹ�
1.����һ��ͷ�ڵ㣬�������������򲻸�ֵ��ָ����ֵΪ�ա�
2.�½���һ���ڵ㣬�������һ���ڵ�󣬾���Ĳ����ǣ��½�����
�ڵ�����ն˽ڵ��Ȼ���ڰ��ն˽ڵ���ƶ���ָ���½����Ľڵ�
������2�ظ�ִ��n�Σ�����n���ڵ�
*/


void CreateListTail(struct Node * *L, int n)
{
	struct Node *p, *r;
	int i;
	srand(time(0));/*��ʼ�����������*/
	*L = (struct Node *)malloc(sizeof(Node));/*Ϊ�������Ա��ͷָ��*/
	r = *L;/*rΪָ��β���Ľڵ�*/
	for (i = 0; i < n; i++)
	{
		p = (Node*)malloc(sizeof(Node));/*�½����ڵ�*/
		p->data = rand() % 100 + 1;/*���½����ڵ�����ݸ�ֵ*/
		r->next = p;/*���½ڵ�����ն˽ڵ��*/
		r = p;/*�ն˽ڵ���ƶ�*/

	}
	r->next = NULL;//�����ڵ���ϣ��ն˽ڵ�ָ��������Ϊ��
}


/*�����������
����������������˼·����
1.�ҵ�ͷָ�룬ָ��ͷ�ڵ��ָ��
2.ʹ��whileѭ����ѭ����ֹ�����ǵ�ǰ�ڵ��ָ����Ϊ��
ǰ���Ǻ���ͷ�ڵ�������
ѭ������䣬�����ǰ�ڵ�ָ�����ڵ�ַ�ռ����ֵ��Ҳ������һ���ڵ��������
����ѭ������һ���ڵ��ʱ�򣬵�ǰ�ڵ��Ѿ������ϣ�Ȼ����������һ����
���Ըô���������ͷ�ڵ������²�����ȷ�ġ�
*/

//����û�ж����µı��������գ�ֱ����L������������ģ�����*L���ı��ˡ�
//��������ʹ��*L�ĵط����Ѿ�������ͷ���λ���ˡ�
void OutputList(struct Node**L)
{
	struct Node*p = (*L)->next;
	while (p != NULL)
	{
		cout << p->data << endl;
		p = p->next;
	}
}

/*����ڵ��������Ҫ����ָ�룬��Ϊ����ı�ָ�������ֵ����ֻ���������ָ�����*/
void OutputList_Pointer(struct Node*L)
{
	while (L->next != NULL)
	{
		cout << (L->next)->data << endl;

		L = L->next;
	}
}

/*�����Ԫ�ػ�ȡ*/
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
/*����Ĳ���
��ʼ������˳�����Ա�L�Ѿ����ڣ�1<=i<=ListLength(L)
�����������L�е�i���ڵ�֮ǰ�����µ�����Ԫ��e,L�ĳ��ȼ�1
*/

int ListInsert(struct Node**L, int i, int e)
{
	int j = 1;
	struct Node* p = *L;/*������Ҫע������ǲ��뵽i������*/
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
	struct Node* p = L;/*������Ҫע������ǲ��뵽i������*/
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

/*�������ɾ��Ԫ��
��ʼ������˳�����Ա�L�Ѿ����ڣ�1<=i<=ListLength(L)
���������ɾ��L�е�i���ڵ�֮ǰ������Ԫ��e,L�ĳ��ȼ�1.
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
		//ɾ����һ��Ԫ��
		if (0 == ListDelete(p2, 1, &a))
		{
			cout << "delete success!!! " << a << endl;
		}
		OutputList(p2);
		return 0;
}




