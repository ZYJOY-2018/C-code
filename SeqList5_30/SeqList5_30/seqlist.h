#pragma once
#include<assert.h>
#include<stdio.h>
#include<stdlib.h>

typedef int SLDateType;
typedef struct SeqList
{
	SLDateType* a;
	int size;
	int capacity;
}SL;

// 对数据的管理:增删查改 
void SeqListInit(SL* ps);
void SeqListDestroy(SL* ps);

void SeqListPrint(SL* ps);
void SeqListPushBack(SL* ps, SLDateType x);
void SeqListPushFront(SL* ps, SLDateType x);
void SeqListPopFront(SL* ps);
void SeqListPopBack(SL* ps);

// 顺序表查找
int SeqListFind(SL* ps, SLDateType x);
// 顺序表在pos位置插入x
void SeqListInsert(SL* ps, int pos, SLDateType x);
// 顺序表删除pos位置的值
void SeqListErase(SL* ps, int pos);