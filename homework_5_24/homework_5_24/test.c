#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<string.h>

//找单身狗2
//找单身狗1：使用异或来完成，因为数组中只出现一个的数字，数组全部的数字异或最后剩下的就是单身狗
//现在是按照二进制位的不同来分组实现每组只有一个单生狗




//void Finddong(int* arr,int sz)
//{
//	//1.全部异或
//	int r = 0;
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		r = r ^ arr[i];
//	}
//	//2.计算r的第几位是1，按位或就行了，同1才为1
//	int pos = 0;
//	//每一位按位或上一个1
//	for (i = 0; i < 32;i++)
//	{
//		if (((r>>i)&1)==1)
//		{
//			pos = i;
//			break;//找到一位就行了，那就找最右边的那一位
//		}
//	}
//	//3.现在找到了二进制中为1的那一位。现在全部的数字按照这位这位二进制不同来分组
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





//模拟实现strncpy
//与strcpy的区别是有个参数n控制了要复制的字符数量
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





//模拟实现strncat
//char* strcat(char* destination, const char* source,size_t n);

//char* mystrncat(char* dest, const char* src, size_t n)
//{
//	//先找到dest的末尾先之后再拼接
//	assert(dest && src);
//
//	char* ret = dest;
//	while (*dest) {
//		dest++;
//	}
//	//拼接
//	int i = 0;
//	for (i = 0; i < n && *src; i++)
//	{
//		*dest = *src;
//		dest++;
//		src++;
//	}
//	*dest = '\0'; // 确保字符串以空字符结尾
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
//	//预期的结果是 hello worl
//	printf("%s", ret);
//	return 0;
//}





//char* mystrncat(char* dest, const char* src, size_t n)
//{
//    assert(dest && src);
//
//    char* ret = dest;
//    while (*dest) // 更正此处的循环终止条件
//    {
//        dest++;
//    }
//    // 拼接
//    int i = 0;
//    for (i = 0; i < n && *src; i++) // 修改拷贝的条件
//    {
//        *dest = *src;
//        dest++;
//        src++;
//    }
//    *dest = '\0'; // 添加终止符
//    return ret;
//}
//
//int main()
//{
//    char arr1[20] = { "hello " };
//    char arr2[] = { "world" };
//    size_t n = 4;
//    char* ret = mystrncat(arr1, arr2, n);
//    printf("%s\n", ret); // 输出：hello worl
//    return 0;
//}








//模拟实现atoi  int atoi(const char *str);

//atoi() 函数用于将字符串转换为整数。它接受一个参数，即要转换的字符串，并返回对应的整数值。
//atoi 函数会跳过字符串开头的空白字符（例如空格、制表符、换行符等）。
//atoi 函数在遇到第一个非数字字符时停止转换，这意味着它不会处理字符串中的小数点或指数部分。
//如果字符串以数字字符开始，但后面跟着非数字字符，atoi 只转换前面的数字部分。
//atoi 函数不检查字符串是否包含有效的整数范围内的值，如果字符串表示的数值超出了 int 类型的范围，结果将是不确定的。


//1.检查是不是空白字符，是就跳过
//2.遇到不是数字字符的时候就停止（意味着如果字符串以数字字符开始，但后面跟着非数字字符，atoi 只转换前面的数字部分。）
//3.如果数字大小超过了上限要设置成上限

//int myatoi(const char* str)
//{
//	assert(str);
//	int result = 0;
//	int sign = 1;
//	int i = 0;
//	//跳过空白字符
//	while (str[i] == ' ') {
//		i++;
//	}
//	//考虑正负符号
//	if (str[i] == '+' || '-')
//	{
//		sign = (str[i++] == '+') ? 1 : -1;//如果是正号就是sign是1，负号就是sign是-1，如果没有符号sign就是原来的值就是1
//	}
//
//	//将字符转换为数字  //判断条件是是否是数字，不是数字就循环停止，返会数值乘上符号
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









//qsort实现
//void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void *))

//先写一次冒泡排序

//void Swap(char* buf1, char* buf2, int size)//交换arr[j],arr[j+1]这两个元素
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
//	for (i = 0; i < sz - 1; i++)//趟数
//	{
//		//一趟比较
//			//两两相邻元素比较
//		int j = 0;
//		for (j = 0; j < sz - 1; j++)
//		{
//
//			//假设需要升序cmp返回>0，交换
//			//强制转换为char*
//			if (cmp((char*)base + j * size, (char*)base + (j + 1) * size) > 0)//两个元素比较，需要将arr[j],arr[j+1]的地址要传给cmp
//			{
//				//交换
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
//	return strcmp(((struct Stu*)p1)->name, ((struct Stu*)p2)->name);//因为是字符，使用strcmp函数来比较大小
//}
//
//int cmp_int(const void* p1, const void* p2)
//{
//	return (*(int*)p1 - *(int*)p2);
//}

//
////测试bubble_sort 排序结构体数据
//void test2()
//{
//	struct Stu arr[] = { {"zhangsan", 20}, {"lisi", 50},{"wangwu", 15} };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	bubble_sort(arr, sz, sizeof(arr[0]), cmp_stu_by_age);
//}



//杨氏矩阵
//分析矩阵就是二维数组啊
//有一个数字矩阵，矩阵的每行从左到右是递增的，矩阵从上到下是递增的，请编写程序在这样的矩阵中查找某个数字是否存在。
//要求：时间复杂度小于O(N);
//就是说不能遍历来解决

//void yangshi(int arr[3][3], int x, int y, int k )
//{
//	/*数组的右上角是一行中最大的数字，是一列中最小的数字
//		左下角是一行中最小的数，是一列中最大的数字*/
//
//	int x = 0;
//	int y = k-1;
//	while (x<=2&&y>=0) //因为去掉一行是x++,去掉一列是y--
//	{
//
//            if  (arr[x][y]<k)
//			{
//				//去掉一行
//				x++;
//			}
//			else if (arr[x][y] > k)
//			{
//				y--;
//			}
//			else
//			{
//				printf("找到了下标是：%d %d\n", x, y);
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
//实现一个函数，可以左旋字符串中的k个字符。例如：ABCD左旋一个字符得到BCDA ABCD左旋两个字符得到CDAB


//让第一个字符先放到tmp中，然后后面的字符全体向前移动空出最后一个位置给第一个字符


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
//	//要左旋k次，就把前面k个字符为一组，后面的为一组，前面逆序后面逆序，再整体逆序
//
//
//}
//
//
//void left_move(char* str, int k )
//{
//	
//	int i = 0;
//	int len = strlen(str);//长度
//	for (i = 0; i < k; i++)//旋转次数
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


//写一个函数，判断一个字符串是否为另外一个字符串旋转之后的字符串。
//最多旋转字符串长度次，每次都使用strcmp来比较，返回0则是左旋的结果

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




