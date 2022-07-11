核心代码
bool Merge(SeqList A, SeqList B, SeqList &C)
{//C为合并后的顺序表
	if (A.length + B.length > C.MaxSize) return false;//超出最大存储空间
	int i = 0, j = 0, k = 0;
	while( i < A.length && j < B.length)
	{
		if (A.data[i] <= B.data[j])
			C.data[k++] = A.data[i++];
		else
			C.data[k++] = B.data[j++];
	}
	while (i < A.length) C.data[k++] = A.data[i++];
	while (j < B.length) C.data[k++] = B.data[j++];
	C.length = k;
	return true;
}




完整代码（C++）
//函数功能：
//将两个有序顺序表合并为一个新的有序顺序表，并由函数返回结果

#include<iostream>
using namespace std;

#define InitSize 50
typedef int ElemType;
typedef struct{
	ElemType *data;
	int length, MaxSize;
}SeqList;

void InitList(SeqList &L)
{
	L.data = new ElemType[InitSize];
	if (!L.data){ cout << "存储空间申请失败！"; return; }
	L.length = 0;
	L.MaxSize = InitSize;
}

bool Merge(SeqList A, SeqList B, SeqList &C)
{
	if (A.length + B.length > C.MaxSize) return false;//超出最大存储空间
	int i = 0, j = 0, k = 0;
	while( i < A.length && j < B.length)
	{
		if (A.data[i] <= B.data[j])
			C.data[k++] = A.data[i++];
		else
			C.data[k++] = B.data[j++];
	}
	while (i < A.length) C.data[k++] = A.data[i++];
	while (j < B.length) C.data[k++] = B.data[j++];
	C.length = k;
	return true;
}

void printList(SeqList L)
{
	for (int i = 0; i < L.length; i++)
		cout << L.data[i] << "  ";
	cout << endl;
}

void main()
{
	//定义并生成两个顺序表
	SeqList A; InitList(A);
	SeqList B; InitList(B);
	A.length = 4; B.length = 5;
	for (int i = 0; i < A.length; i++)
		A.data[i] = 2 * i + 1;
	for (int i = 0; i < B.length; i++)
		B.data[i] = 2 * (i + 1);
	 
	SeqList C; InitList(C);
	printList(A);
	printList(B);
	 if (Merge(A,B,C)) printList(C);
}

