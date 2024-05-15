#pragma once

#define NAME_MAX 20
#define SEX_MAX 5
#define TELE_MAX 12
#define ADDR_MAX 30
#define MAX 100
#define DEFAULT_SZ 3
#define DEFAULT_INC 2



#include<assert.h>
#include<stdio.h>
#include<string.h>
#include <stdlib.h>

typedef struct PeoInfo
{
	char name[NAME_MAX];
		int age;
		char sex[SEX_MAX];
		char tele[TELE_MAX];
		char addr[ADDR_MAX];

}PeoInfo;


//typedef struct Contact
//{
//	PeoInfo data[MAX];
//	int sz;    //记录当前输入了多少个联系人//这里是声明不要赋值初始化了
//}Contact;



//动态版本
typedef struct Contact
{
	PeoInfo* data;
	int sz;//记录的是当前通讯录中存放的人的信息个数
	int capacity;//记录的时通讯录当前的最大容量

}Contact;

void InitContact(Contact* pc);
//初始化通讯录，只需要结构体的指针就可以通过指针去找到data数组来初始化

//增加联系人
void AddContact(Contact* pc);
//同样增加联系人就是修改data数组的内容，并且把sz+1；

//显示所有联系人
void ShowContact(const Contact* pc);

//删除联系人
void DelContact(Contact* pc);

//查找指定联系人
void SearchContact(Contact* pc);

//修改指定联系人
void ModifyContact(Contact* pc);

//排序联系人
void SortContact(Contact* pc);

//释放内存
void DestroyContact(Contact* pc);
//保存通讯录数据到文件
void SaveContact(Contact* pc);
//加载文件信息到通讯录
void LoadContact(Contact* pc);