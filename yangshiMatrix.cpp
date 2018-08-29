// yangshiMatrix.cpp : �������̨Ӧ�ó������ڵ㡣
//���Ͼ���ָ�������Һ��������ӵľ������Ϊ�˷��㣬�����������Ϊ���Һ����������ӵľ��������е�KС��Ԫ��

#include "stdafx.h"
#include <iostream>
#include <queue>
using namespace std;





//����ĳ��ֵ�ڲ��ڸþ�����
bool findM(int *data, int k, int m, int n) {
	if (data == NULL || m <= 0 || n <= 0)
		throw exception("Invalid parameters");

	bool result = false;
	int row = 0;
	int col = n-1;
	while (row < m&&col >= 0)
	{
		if (k == data[row*n + col])
		{
			result = true;
			break;
		}
		else if (k > data[row*n + col])
			row++;
		else
			col--;
	}
	return result;
}





//����Ϊͨ�õ�k��Сֵ�ķ��ط�������Ϊû��ʹ�õ��þ�����ص�
class cmp//����ȽϺ��������ȶ��а�����С��������
{
public:
	bool operator()(const int a, const int b)
	{
		return a > b;
	}
};
int findKth(int *data, int k,int m,int n)
{
	if (data == NULL || k <= 0 || m <= 0 || n <= 0)
		throw exception("Invalid parameters");

	//������С�ѣ�Ȼ��pop()k-1�Σ����top��Ԫ�ؼ�Ϊ��KСԪ��
	priority_queue<int,vector<int>,cmp> q;
	for (int i = 0; i < m*n; i++)
		q.push(data[i]);
	while (!q.empty()&&--k)
		q.pop();
	return q.top();
}



//�����㷨ʹ�þ������е��ص������ƣ���Ϊ�������������ӵ�
int findKth2(int *data, int k, int m, int n)
{
	if (data == NULL || k <= 0 || m <= 0 || n <= 0)
		throw exception("Invalid parameters");

	//����ÿһ���е�ǰС������Ӧ���к�
	int *rows = new int[m];
	for (int i = 0; i < m; i++)
		rows[i] = 0;

	int result = INT_MAX;

	while (k--)
	{
		result = INT_MAX;
		int tip = 0;//��ǰСֵ������
		for (int i = 0; i < m; i++)
		{
			if (rows[i] < n)
			{
				if (data[i*n + rows[i]] < result)
				{
					result = data[i*n + rows[i]];
					tip = i;
				}
			}
		}
		rows[tip]++;//��һ�εıȽϣ��ڱȽ�tip�е�ʱ��ʹ����һ�е�����
	}
	return result;
}


//�����㷨ʹ�þ������е��ص������ƣ���Ϊ�������������ӵ�
int findKth3(int *data, int k, int m, int n)
{
	if (data == NULL || k <= 0 || m <= 0 || n <= 0)
		throw exception("Invalid parameters");

	//����ÿһ���е�ǰС������Ӧ���к�
	int *cols = new int[n];
	for (int i = 0; i < n; i++)
		cols[i] = 0;

	int result = INT_MAX;

	while (k--)
	{
		result = INT_MAX;
		int tip = 0;//��ǰСֵ������
		for (int i = 0; i < n; i++)
		{
			if (cols[i] < m)
			{
				if (data[cols[i] *n + i] < result)
				{
					result = data[cols[i] * n + i];
					tip = i;
				}
			}
		}
		cols[tip]++;//��һ�εıȽϣ��ڱȽ�tip�е�ʱ��ʹ����һ�е�����
	}
	return result;
}



int main()
{
	int k, c, h;//kֵ������������
	cin >> k >> c >> h;

	int *data = new int[c*h];
	for (int i = 0; i < h; i++)
		for (int j = 0; j < c; j++)
			cin >> data[i*c+j];
	cout << boolalpha <<findM(data, k, h, c) << endl;
	cout<< findKth3(data, k, h, c)<<endl;
	system("pause");
    return 0;
}
