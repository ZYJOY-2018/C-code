#define _CRT_SECURE_NO_WARNINGS 1
#include"seqlist.h"


//����β��ͷ��
void TestSL1()
{
	SL sl;
	SeqListInit(&sl);
	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 4);
	SeqListPushBack(&sl, 5);
	SeqListPushBack(&sl, 6);
	SeqListPushBack(&sl, 7);
	SeqListPushBack(&sl, 8);
	SeqListPushBack(&sl, 9);
	SeqListPrint(&sl);

	SeqListPushFront(&sl, 10);
	SeqListPushFront(&sl, 20);
	SeqListPushFront(&sl, 30);
	SeqListPushFront(&sl, 40);
	SeqListPrint(&sl);

	SeqListDestroy(&sl);
}

//���Ե���popbackβɾ
void TestSL2()
{
	SL sl;
	SeqListInit(&sl);
	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 4);
	SeqListPushBack(&sl, 5);
	SeqListPrint(&sl);

	SeqListPopBack(&sl);
	SeqListPrint(&sl);

	SeqListPopBack(&sl);
	SeqListPopBack(&sl);
	SeqListPopBack(&sl);
	SeqListPopBack(&sl);
	SeqListPrint(&sl);

	//SLPopBack(&sl);
	//SLPrint(&sl);

	SeqListPushFront(&sl, 10);
	SeqListPushFront(&sl, 20);
	SeqListPushFront(&sl, 30);
	SeqListPushFront(&sl, 40);
	SeqListPrint(&sl);

	SeqListDestroy(&sl);
}

//����ͷɾ��ɾ��һ�δ�ӡһ��
void TestSL3()
{
	SL sl;
	SeqListInit(&sl);
	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 4);
	SeqListPushBack(&sl, 5);
	SeqListPrint(&sl);

	SeqListPopFront(&sl);
	SeqListPrint(&sl);

	SeqListPopFront(&sl);
	SeqListPrint(&sl);

	SeqListPopFront(&sl);
	SeqListPrint(&sl);

	SeqListPopFront(&sl);
	SeqListPrint(&sl);

	SeqListPopFront(&sl);
	SeqListPrint(&sl);

	//SLPopFront(&sl);
	//SLPrint(&sl);
}

//��������λ�õĲ���
void TestSL4()
{
	//SL* ptr = NULL;
	//SLInit(ptr);

	SL sl;
	SeqListInit(&sl);
	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 4);
	SeqListPushBack(&sl, 5);
	SeqListPrint(&sl);

	SeqListInsert(&sl, 2, 20);
	SeqListPrint(&sl);

	SeqListInsert(&sl, 6, 20);
	SeqListPrint(&sl);

	SeqListInsert(&sl, 0, 20);
	SeqListPrint(&sl);

	SeqListInsert(&sl, 10, 20);//���ڲ��Բ���λ�ò��Ϸ�
	SeqListPrint(&sl);

	SeqListDestroy(&sl);
}

//��������λ�õ�ɾ��
void TestSL5()
{
	SL sl;
	SeqListInit(&sl);
	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 4);
	SeqListPushBack(&sl, 5);
	SeqListPrint(&sl);

	SeqListErase(&sl, 3);
	SeqListPrint(&sl);

	SeqListErase(&sl, 3);
	SeqListPrint(&sl);

	int pos = SeqListFind(&sl, 2);
	if (pos != -1)
	{
		SeqListErase(&sl, pos);
	}
	SeqListPrint(&sl);
	//SLErase(&sl, 3);
	//SLPrint(&sl);
}

int main()
{
	
	TestSL5();

}