#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>


//求两个数二进制中不同位的个数
//编程实现：两个int（32位）整数m和n的二进制表达中，有多少个位(bit)不同？
//输入例子 :
//1999 2299
//输出例子 : 7
int number_of_1(int m)//让m与上m-，因为是2进制，-1，就会让右边往左的第一位1去掉，后面都变为1；循环条件就是m当所以1都去掉之后就是有多少1；
	{
		int count = 0;
		while (m)
		{
			m = m & (m - 1);
			count++;
		}
	}
//int number_of_2(int m)//让每一位按位与1，如果结果为1，则count++
//{
//	int count = 0;
//	for (int i = 1; i < 32; i++)
//	{
//		if ((m >> i) & 1 == 1)
//			count++;
//	}
//	return count;
//}
//int number_of_3(int m)//之前我们还见过得到每一位的方法：10进制为例，是先取余数得到末位，然后除去掉末位重复该过程
//{
//
//	int count = 0;
//	while (m)
//	{
//		if (m % 2 == 1)
//		{
//			count++;
//			m /= 2;
//		}
//	}
//	
//}
//int main()
//{
//	//异或是相同为0，不同为1，先异或之后再看看有多少1；
//	int m, n;
//	scanf("%d %d", &m, &n);
//	int ret = number_of_1(m ^ n);
//	
//	printf("%d", ret);
//	return 0;
//}

//打印整数二进制的奇数位和偶数位
//
//作业内容
//获取一个整数二进制序列中所有的偶数位和奇数位，分别打印出二进制序列

//int main()
//{
//	int num = 0;
//	scanf("%d", &num);
//	//按位与1就好了应为相同为1，不同为0；
//	int i = 0;
//	printf("\n打印奇数位：");
//	for (i = 31; i > 0; i -= 2)
//		printf("%d ", (num >> i) & 1);
//	printf("\n打印偶数位：");
//	for (i = 30; i >= 0; i -= 2)
//		printf("%d ", (num >> i) & 1);
//	return 0;
//}

//统计二进制中1的个数
//作业内容
//写一个函数返回参数二进制中 1 的个数。
//比如： 15    0000 1111    4 个 1

//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//
//	int ret =number_of_1(n);
//	printf("%d", ret);
//	return 0;
//}

//交换两个变量（不创建临时变量）
//
//作业内容
//不允许创建临时变量，交换两个整数的内容


//int main() {
//	int a = 5, b = 7;
//
//	a = a + b;
//	b = a - b;
//	a = a - b;
//
//	printf("a = %d, b = %d\n", a, b);
//	return 0;
//}

int LilyNumber(int n)
{
    //递归结束的条件是最后剩下一位数字
    if (n < 10)
    {
        return 0;
    }
    return (n % 10) * (n / 10) + LilyNumber(n / 10);
}
int main() {
    int i;
    for (i = 10000; i <= 100000; i++)
    {
        //判断是不是水仙花数；
        //把数字拆下来,感觉递归可以做？
        int ret = LilyNumber(i);
        if (ret == i)
        {
            printf("%d ", i);
        }
    }
    return 0;
}

int LilyNumber(int n)
{
    int i;
    int sum = 0;

    if (n < 10)
    {
        return 0;
    }

    for (i = 1; i < n; i++)
    {
        int left = n / (int)pow(10, i);
        int right = n % (int)pow(10, i);
        sum += left * right;
    }

    return sum;
}

int main() {
    int i;

    for (i = 10000; i <= 99999; i++)
    {
        int ret = LilyNumber(i);
        if (ret == i)
        {
            printf("%d ", i);
        }
    }

    return 0;
}