#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>


//���������������в�ͬλ�ĸ���
//���ʵ�֣�����int��32λ������m��n�Ķ����Ʊ���У��ж��ٸ�λ(bit)��ͬ��
//�������� :
//1999 2299
//������� : 7
int number_of_1(int m)//��m����m-����Ϊ��2���ƣ�-1���ͻ����ұ�����ĵ�һλ1ȥ�������涼��Ϊ1��ѭ����������m������1��ȥ��֮������ж���1��
	{
		int count = 0;
		while (m)
		{
			m = m & (m - 1);
			count++;
		}
	}
//int number_of_2(int m)//��ÿһλ��λ��1��������Ϊ1����count++
//{
//	int count = 0;
//	for (int i = 1; i < 32; i++)
//	{
//		if ((m >> i) & 1 == 1)
//			count++;
//	}
//	return count;
//}
//int number_of_3(int m)//֮ǰ���ǻ������õ�ÿһλ�ķ�����10����Ϊ��������ȡ�����õ�ĩλ��Ȼ���ȥ��ĩλ�ظ��ù���
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
//	//�������ͬΪ0����ͬΪ1�������֮���ٿ����ж���1��
//	int m, n;
//	scanf("%d %d", &m, &n);
//	int ret = number_of_1(m ^ n);
//	
//	printf("%d", ret);
//	return 0;
//}

//��ӡ���������Ƶ�����λ��ż��λ
//
//��ҵ����
//��ȡһ���������������������е�ż��λ������λ���ֱ��ӡ������������

//int main()
//{
//	int num = 0;
//	scanf("%d", &num);
//	//��λ��1�ͺ���ӦΪ��ͬΪ1����ͬΪ0��
//	int i = 0;
//	printf("\n��ӡ����λ��");
//	for (i = 31; i > 0; i -= 2)
//		printf("%d ", (num >> i) & 1);
//	printf("\n��ӡż��λ��");
//	for (i = 30; i >= 0; i -= 2)
//		printf("%d ", (num >> i) & 1);
//	return 0;
//}

//ͳ�ƶ�������1�ĸ���
//��ҵ����
//дһ���������ز����������� 1 �ĸ�����
//���磺 15    0000 1111    4 �� 1

//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//
//	int ret =number_of_1(n);
//	printf("%d", ret);
//	return 0;
//}

//����������������������ʱ������
//
//��ҵ����
//����������ʱ������������������������


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
    //�ݹ���������������ʣ��һλ����
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
        //�ж��ǲ���ˮ�ɻ�����
        //�����ֲ�����,�о��ݹ��������
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