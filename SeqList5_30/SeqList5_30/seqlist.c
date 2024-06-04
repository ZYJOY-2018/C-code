#define _CRT_SECURE_NO_WARNINGS 1
#include"seqlist.h"



void SeqListInit(SL* ps)
{
	assert(ps);
	ps->a = NULL;//��ʼ��Ϊ��ָ��
	ps->capacity = 0;
	ps->size = 0;
}

void SLCheckCapacity(SL* ps1)
{
	//�ж��Ƿ���Ҫ����
	if (ps1->size == ps1->capacity)
	{
		int newcapacity = ps1->capacity == 0 ? 4 : ps1->capacity * 2;
		SLDateType* tmp = (SLDateType*)realloc(ps1->a, sizeof(SLDateType)*newcapacity);//���ʹ�С���� ���� Ϊ�ܴ�С
		if (tmp == NULL)
		{
			perror("realloc fail");
		}
		ps1->a = tmp;
		ps1->capacity = newcapacity;
	}

}
void SeqListPrint(SL* ps)
{
	assert(ps);
	int i = 0;
	int size = ps->size;
	for (i = 0; i < size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");

}

//β�塣�߼��������жϿռ���û�������˾����ݣ�
//���ǲ����±�Ϊsize��λ��
void SeqListPushBack(SL* ps, SLDateType x)
{
	assert(ps);
	SLCheckCapacity(ps);

	//����֮��
	ps->a[ps->size] = x;
	ps->size++;

}

//ͷ��
//�߼���
void SeqListPushFront(SL* ps, SLDateType x)
{
	assert(ps);
	SLCheckCapacity(ps);
	int end = ps->size - 1;
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		ps->a[end+1] = ps->a[end];
		--end;
	}
	//�ƶ���֮��endΪ-1
	ps->a[0] = x;
	ps->size++;//�������˲���֮����Ч���ݱ��Ҫ�Ӽ�

}

//ʵ��ͷɾ���ú����Ԫ�ظ��ǵ�ǰ���Ԫ�أ�size--,�Ǿ��Ǵ�ǰ�濪ʼ��Ԫ����ǰ��begin��ʼΪ1
void SeqListPopFront(SL* ps)
{
	assert(ps);
	//ɾ���Ͳ���Ҫ�����Ƿ�Ҫ���ݵ�����
	int begin = 1;
	for (begin = 0; begin < ps->size; begin++)
	{
		ps->a[begin] = ps->a[begin + 1];
	}
	//���ͷɾ֮�����Ҫsize-1
	ps->size--;

}

//ʵ��βɾ��size--�ͺ�
void SeqListPopBack(SL* ps)
{
	assert(ps);
	ps->size--;
}



void SeqListDestroy(SL* ps1)
{
	if (ps1->a != NULL)
	{
		free(ps1->a);//ֻ��a�Ŀռ��Ƕ�̬��������
		ps1->a = NULL;//free֮����Ϊ��ָ��
		ps1->capacity = 0;
		ps1->size = 0;
	}
}

//����λ�ò��� 
void SeqListInsert(SL* ps, int pos, SLDateType x)
{
	assert(ps);
	//�жϲ���λ�ú���
	assert(pos >= 0 && pos <= ps->size);
	//����֮ǰ��pos�Լ������Ԫ�ض������ƶ�
	int end = ps->size - 1;
	while (end >= pos)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	//����
	ps->a[pos] = x;
	//����֮����Ч��������������size++
	ps->size++;
}

//����λ�õ�ɾ��
//
void SeqListErase(SL* ps, int pos)
{
	assert(ps);
	assert(pos>=0 && pos <= ps->size);
	//ʵ��ɾ���ú����Ԫ�������ǵ�ǰ���
	int begin = pos + 1;
	while (begin < ps->size)
	{
		ps->a[begin-1] = ps->a[begin];//�ú��渲�ǵ�ǰ��ǰһ�����±�Ӧ����begin-1Ϊ���ֹԽ��
		begin++;
	}
	ps->size--;

}





int SeqListFind(SL* psl, SLDateType x)
{
	assert(psl);

	for (int i = 0; i < psl->size; i++)
	{
		if (psl->a[i] == x)
		{
			return i;
		}
	}

	return -1;
}