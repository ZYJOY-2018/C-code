#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<string.h>

//�ҵ���2
//�ҵ���1��ʹ���������ɣ���Ϊ������ֻ����һ�������֣�����ȫ��������������ʣ�µľ��ǵ���
//�����ǰ��ն�����λ�Ĳ�ͬ������ʵ��ÿ��ֻ��һ��������




//void Finddong(int* arr,int sz)
//{
//	//1.ȫ�����
//	int r = 0;
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		r = r ^ arr[i];
//	}
//	//2.����r�ĵڼ�λ��1����λ������ˣ�ͬ1��Ϊ1
//	int pos = 0;
//	//ÿһλ��λ����һ��1
//	for (i = 0; i < 32;i++)
//	{
//		if (((r>>i)&1)==1)
//		{
//			pos = i;
//			break;//�ҵ�һλ�����ˣ��Ǿ������ұߵ���һλ
//		}
//	}
//	//3.�����ҵ��˶�������Ϊ1����һλ������ȫ�������ְ�����λ��λ�����Ʋ�ͬ������
//	int s1 = 0;
//	int s2 = 0;
//	for (i = 0; i < sz; i++)
//	{
//		if (((arr[i] >> pos) & 1) == 1)
//		{
//			s1 ^= arr[i];
//		}
//		else
//		{
//			s2 ^= arr[i];
//		}
//	}
//	printf("s1 =%d s2 = %d\n", s1,s2);
//
//}
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,1,2,3,4,6 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//  Finddong(arr,sz);
//
//
//	return 0;
//}





//ģ��ʵ��strncpy
//��strcpy���������и�����n������Ҫ���Ƶ��ַ�����
//char* strcpy(char* destination, const char* source);
//char *strncpy(char *dest, const char *src, size_t n);

//char* mystrncpy(char* dest, const char* src, size_t n)
//{
//	assert(dest);
//	assert(src);
//	char* ret = dest;
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		*dest = *src;
//		dest++;
//		src++;
//	}
//	return ret;
//}
//
//int main()
//{
//	char arr1[] = { "hello" };
//	char arr2[] = { "world" };
//	size_t n = 4;
//	char* ret =mystrncpy(arr1, arr2,n);
//
//	printf("%s", ret);
//	return 0;
//}





//ģ��ʵ��strncat
//char* strcat(char* destination, const char* source,size_t n);

//char* mystrncat(char* dest, const char* src, size_t n)
//{
//	//���ҵ�dest��ĩβ��֮����ƴ��
//	assert(dest && src);
//
//	char* ret = dest;
//	while (*dest) {
//		dest++;
//	}
//	//ƴ��
//	int i = 0;
//	for (i = 0; i < n && *src; i++)
//	{
//		*dest = *src;
//		dest++;
//		src++;
//	}
//	*dest = '\0'; // ȷ���ַ����Կ��ַ���β
//	return ret;
//
//}
//
//
//int main()
//{
//	char arr1[] = { "hello " };
//	char arr2[] = { "world" };
//	size_t n = 4;
//    char* ret =mystrncat(arr1, arr2,n);
//	//Ԥ�ڵĽ���� hello worl
//	printf("%s", ret);
//	return 0;
//}





//char* mystrncat(char* dest, const char* src, size_t n)
//{
//    assert(dest && src);
//
//    char* ret = dest;
//    while (*dest) // �����˴���ѭ����ֹ����
//    {
//        dest++;
//    }
//    // ƴ��
//    int i = 0;
//    for (i = 0; i < n && *src; i++) // �޸Ŀ���������
//    {
//        *dest = *src;
//        dest++;
//        src++;
//    }
//    *dest = '\0'; // �����ֹ��
//    return ret;
//}
//
//int main()
//{
//    char arr1[20] = { "hello " };
//    char arr2[] = { "world" };
//    size_t n = 4;
//    char* ret = mystrncat(arr1, arr2, n);
//    printf("%s\n", ret); // �����hello worl
//    return 0;
//}








//ģ��ʵ��atoi  int atoi(const char *str);

//atoi() �������ڽ��ַ���ת��Ϊ������������һ����������Ҫת�����ַ����������ض�Ӧ������ֵ��
//atoi �����������ַ�����ͷ�Ŀհ��ַ�������ո��Ʊ�������з��ȣ���
//atoi ������������һ���������ַ�ʱֹͣת��������ζ�������ᴦ���ַ����е�С�����ָ�����֡�
//����ַ����������ַ���ʼ����������ŷ������ַ���atoi ֻת��ǰ������ֲ��֡�
//atoi ����������ַ����Ƿ������Ч��������Χ�ڵ�ֵ������ַ�����ʾ����ֵ������ int ���͵ķ�Χ��������ǲ�ȷ���ġ�


//1.����ǲ��ǿհ��ַ����Ǿ�����
//2.�������������ַ���ʱ���ֹͣ����ζ������ַ����������ַ���ʼ����������ŷ������ַ���atoi ֻת��ǰ������ֲ��֡���
//3.������ִ�С����������Ҫ���ó�����

//int myatoi(const char* str)
//{
//	assert(str);
//	int result = 0;
//	int sign = 1;
//	int i = 0;
//	//�����հ��ַ�
//	while (str[i] == ' ') {
//		i++;
//	}
//	//������������
//	if (str[i] == '+' || '-')
//	{
//		sign = (str[i++] == '+') ? 1 : -1;//��������ž���sign��1�����ž���sign��-1�����û�з���sign����ԭ����ֵ����1
//	}
//
//	//���ַ�ת��Ϊ����  //�ж��������Ƿ������֣��������־�ѭ��ֹͣ��������ֵ���Ϸ���
//	while (str[i] >= '0' && str[i] <= '9') {
//		result = result * 10 + (str[i++] - '0');
//	}
//
//	return result * sign;
//
//}
//
//
//int main() {
//	const char* str = "12345";
//	int num = atoi(str);
//
//	printf("Converted number: %d\n", num);
//
//	return 0;
//}









//qsortʵ��
//void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void *))

//��дһ��ð������

//void Swap(char* buf1, char* buf2, int size)//����arr[j],arr[j+1]������Ԫ��
//{
//	int i = 0;
//	char tmp = 0;
//	for (i = 0; i < size; i++)
//	{
//		tmp = *buf1;
//		*buf1 = *buf2;
//		*buf2 = tmp;
//		buf1++;
//		buf2++;
//	}
//}
//
//void bubble_sort(void* base, int num, int size, int (*cmp)(const void*, const void*))
//{
//	int i = 0;
//	for (i = 0; i < sz - 1; i++)//����
//	{
//		//һ�˱Ƚ�
//			//��������Ԫ�رȽ�
//		int j = 0;
//		for (j = 0; j < sz - 1; j++)
//		{
//
//			//������Ҫ����cmp����>0������
//			//ǿ��ת��Ϊchar*
//			if (cmp((char*)base + j * size, (char*)base + (j + 1) * size) > 0)//����Ԫ�رȽϣ���Ҫ��arr[j],arr[j+1]�ĵ�ַҪ����cmp
//			{
//				//����
//				Swap((char*)base + j * size, (char*)base + (j + 1) * size, size);
//			}
//
//		}
//	}
//}
//
//
//
//
//
//
//struct Stu
//{
//	char name[20];
//	int age;
//};
//
//
//int cmp_stu_by_age(const void* p1, const void* p2)
//{
//	return ((struct Stu*)p1)->age - ((struct Stu*)p2)->age;
//}
//int cmp_stu_by_name(const void* p1, const void* p2)
//{
//	return strcmp(((struct Stu*)p1)->name, ((struct Stu*)p2)->name);//��Ϊ���ַ���ʹ��strcmp�������Ƚϴ�С
//}
//
//int cmp_int(const void* p1, const void* p2)
//{
//	return (*(int*)p1 - *(int*)p2);
//}

//
////����bubble_sort ����ṹ������
//void test2()
//{
//	struct Stu arr[] = { {"zhangsan", 20}, {"lisi", 50},{"wangwu", 15} };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	bubble_sort(arr, sz, sizeof(arr[0]), cmp_stu_by_age);
//}



//���Ͼ���
//����������Ƕ�ά���鰡
//��һ�����־��󣬾����ÿ�д������ǵ����ģ�������ϵ����ǵ����ģ����д�����������ľ����в���ĳ�������Ƿ���ڡ�
//Ҫ��ʱ�临�Ӷ�С��O(N);
//����˵���ܱ��������

//void yangshi(int arr[3][3], int x, int y, int k )
//{
//	/*��������Ͻ���һ�����������֣���һ������С������
//		���½���һ������С��������һ������������*/
//
//	int x = 0;
//	int y = k-1;
//	while (x<=2&&y>=0) //��Ϊȥ��һ����x++,ȥ��һ����y--
//	{
//
//            if  (arr[x][y]<k)
//			{
//				//ȥ��һ��
//				x++;
//			}
//			else if (arr[x][y] > k)
//			{
//				y--;
//			}
//			else
//			{
//				printf("�ҵ����±��ǣ�%d %d\n", x, y);
//			}
//	}
//
//			
//
//}
//int main()
//{
//	int arr[3][3] = { 1,2,3, 4,5,6, 7,8,9 };
//	int k = 0;
//	scnaf("%d", &k);
//	int x = 3;
//	int y = 3;
//
//	yangshi(arr, x, y,k);
//
//	return 0;
//}

//
//ʵ��һ�����������������ַ����е�k���ַ������磺ABCD����һ���ַ��õ�BCDA ABCD���������ַ��õ�CDAB


//�õ�һ���ַ��ȷŵ�tmp�У�Ȼ�������ַ�ȫ����ǰ�ƶ��ճ����һ��λ�ø���һ���ַ�


//void reverse(char* left, char* right)
//{
//	assert(left && right);
//	while (left < right)
//	{
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}
//
//void left_move2(char* str, int k)
//{
//	//Ҫ����k�Σ��Ͱ�ǰ��k���ַ�Ϊһ�飬�����Ϊһ�飬ǰ�����������������������
//
//
//}
//
//
//void left_move(char* str, int k )
//{
//	
//	int i = 0;
//	int len = strlen(str);//����
//	for (i = 0; i < k; i++)//��ת����
//	{
//     char tmp = *str;
//	 
//	 
//	 int j = 0;
//	 for (j = 0; j < len - 1; j++)
//	 {
//       *(str + j) = *(str + j + 1);
//	 }
//	 
//	 *(str + len - 1) = tmp;
//
//	}
//	
//
//}
//
//int main()
//{
//	char arr[] = { "ABCD" };
//	int k = 0;
//	
//	scanf("%d", &k);
//
//	left_move(arr, k);
//	printf("%s", arr);
//	return 0;
//}


//дһ���������ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����
//�����ת�ַ������ȴΣ�ÿ�ζ�ʹ��strcmp���Ƚϣ�����0���������Ľ��

//int if_left_move(char* s1, char* s2)
//{
//	int len = strlen(s1);
//	int i = 0;
//	
//	for (i = 0; i < len; i++)
//	{
//		int j = 0;
//		if (strcmp(s1, s2) == 0)
//		{
//			
//			return 1;
//		}
//		char tmp = *s1;
//		for (j = 0; j < len - 1; j++)
//		{
//			*(s1 + j) = *(s1 + j + 1);
//		}
//		*(s1 + len - 1) = tmp;
//	}
//	return 0;
//}
//
//int main()
//{
//	char s1[] =  "AABCD" ;
//	char s2[] =  "BCDAA" ;
//	int ret = if_left_move(s1, s2);
//	printf("%d", ret);
//	return 0;
//}




