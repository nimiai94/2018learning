// timesofmeet.cpp : 定义控制台应用程序的入口点。
//计算一天的时间，分针和时针相遇的次数
//时针的角速度：30度每小时  分针的角速度：360度每小时
//相遇：距离之差为360的倍数

#include "stdafx.h"
#include <cstdlib>

int main()
{
	int i = 0;
	int count = 0;
	while (count <= 24)//假定相遇的次数最多为24
	{
		
		if (360 * count / 330  >= 24)
			break;
		printf("第%d次相遇时间：%.3f\n", count + 1, (float)360 * count / (float)330);
		count++;
			
	}
	printf("次数为：%d", count);
	system("pause");
    return 0;
}

