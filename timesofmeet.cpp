// timesofmeet.cpp : �������̨Ӧ�ó������ڵ㡣
//����һ���ʱ�䣬�����ʱ�������Ĵ���
//ʱ��Ľ��ٶȣ�30��ÿСʱ  ����Ľ��ٶȣ�360��ÿСʱ
//����������֮��Ϊ360�ı���

#include "stdafx.h"
#include <cstdlib>

int main()
{
	int i = 0;
	int count = 0;
	while (count <= 24)//�ٶ������Ĵ������Ϊ24
	{
		
		if (360 * count / 330  >= 24)
			break;
		printf("��%d������ʱ�䣺%.3f\n", count + 1, (float)360 * count / (float)330);
		count++;
			
	}
	printf("����Ϊ��%d", count);
	system("pause");
    return 0;
}
