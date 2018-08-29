// yangshiMatrix.cpp : 定义控制台应用程序的入口点。
//杨氏矩阵指的是向右和向上增加的矩阵，这里，为了方便，排序矩阵设置为向右和向下是增加的矩阵，求其中第K小的元素

#include "stdafx.h"
#include <iostream>
#include <queue>
using namespace std;





//查找某个值在不在该矩阵中
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





//以下为通用第k最小值的返回方法，因为没有使用到该矩阵的特点
class cmp//定义比较函数，优先队列按照由小到大排列
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

	//构建最小堆，然后pop()k-1次，最后top的元素即为第K小元素
	priority_queue<int,vector<int>,cmp> q;
	for (int i = 0; i < m*n; i++)
		q.push(data[i]);
	while (!q.empty()&&--k)
		q.pop();
	return q.top();
}



//以下算法使用矩阵排列的特点进行设计，因为数据是向右增加的
int findKth2(int *data, int k, int m, int n)
{
	if (data == NULL || k <= 0 || m <= 0 || n <= 0)
		throw exception("Invalid parameters");

	//放置每一行中当前小的数对应的列号
	int *rows = new int[m];
	for (int i = 0; i < m; i++)
		rows[i] = 0;

	int result = INT_MAX;

	while (k--)
	{
		result = INT_MAX;
		int tip = 0;//当前小值所在行
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
		rows[tip]++;//下一次的比较，在比较tip行的时候，使用下一列的数据
	}
	return result;
}


//以下算法使用矩阵排列的特点进行设计，因为数据是向下增加的
int findKth3(int *data, int k, int m, int n)
{
	if (data == NULL || k <= 0 || m <= 0 || n <= 0)
		throw exception("Invalid parameters");

	//放置每一列中当前小的数对应的行号
	int *cols = new int[n];
	for (int i = 0; i < n; i++)
		cols[i] = 0;

	int result = INT_MAX;

	while (k--)
	{
		result = INT_MAX;
		int tip = 0;//当前小值所在列
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
		cols[tip]++;//下一次的比较，在比较tip列的时候，使用下一行的数据
	}
	return result;
}



int main()
{
	int k, c, h;//k值、列数、行数
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

