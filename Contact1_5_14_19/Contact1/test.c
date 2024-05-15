#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"
//实现一个通讯录；
//
//通讯录可以用来存储1000个人的信息，每个人的信息包括：姓名、性别、年龄、电话、住址
//
//提供方法：
//
//添加联系人信息
//删除指定联系人信息
//查找指定联系人信息
//修改指定联系人信息
//显示所有联系人信息
//清空所有联系人
//以名字排序所有联系人

//先实现一个菜单

void menu()
{
	printf("***********************************\n");
	printf("******  1.add      2.del     ******\n");
	printf("******  3.search   4.modify  ******\n");
	printf("******  5.show     6.sort    ******\n");
	printf("******  0.exit               ******\n");
	printf("***********************************\n");
}
//枚举类型可能取值使用逗号隔开,最后一个不用逗号
enum Option
{
	EXIT,
	ADD,
	DEL,
	SREACH,
	MODIFY,
	SHOW,
	SORT

};

int main()
{
	Contact con;
	InitContact(&con);//初始化通讯录

	int input = 0;
	do 
	{
		menu();
		printf("请输入你的选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case EXIT:
			SaveContact(&con);//保存通讯录数据到文件
			DestroyContact(&con); //销毁通讯录
			printf("退出通讯录\n");
			break;
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SREACH:
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case SORT:
			SortContact(&con);			//按照年龄排序
			break;
			//别忘记写default
		default:
			printf("选择错误，重新选择\n");

		}
	} while (input);



	return 0;
}


