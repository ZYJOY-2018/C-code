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

// �����ݵĹ���:��ɾ��� 
void SeqListInit(SL* ps);
void SeqListDestroy(SL* ps);

void SeqListPrint(SL* ps);
void SeqListPushBack(SL* ps, SLDateType x);
void SeqListPushFront(SL* ps, SLDateType x);
void SeqListPopFront(SL* ps);
void SeqListPopBack(SL* ps);

// ˳������
int SeqListFind(SL* ps, SLDateType x);
// ˳�����posλ�ò���x
void SeqListInsert(SL* ps, int pos, SLDateType x);
// ˳���ɾ��posλ�õ�ֵ
void SeqListErase(SL* ps, int pos);