#define _CRT_SECURE_NO_WARNINGS 1
#include"seqlist.h"



void SeqListInit(SL* ps)
{
	assert(ps);
	ps->a = NULL;//初始化为空指针
	ps->capacity = 0;
	ps->size = 0;
}

void SLCheckCapacity(SL* ps1)
{
	//判断是否需要扩容
	if (ps1->size == ps1->capacity)
	{
		int newcapacity = ps1->capacity == 0 ? 4 : ps1->capacity * 2;
		SLDateType* tmp = (SLDateType*)realloc(ps1->a, sizeof(SLDateType)*newcapacity);//类型大小乘上 数量 为总大小
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

//尾插。逻辑就是先判断空间满没满，满了就扩容，
//就是插入下标为size的位置
void SeqListPushBack(SL* ps, SLDateType x)
{
	assert(ps);
	SLCheckCapacity(ps);

	//扩容之后
	ps->a[ps->size] = x;
	ps->size++;

}

//头插
//逻辑是
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
	//移动完之后end为-1
	ps->a[0] = x;
	ps->size++;//别忘记了插入之后有效数据变多要加加

}

//实现头删，让后面的元素覆盖掉前面的元素，size--,那就是从前面开始让元素往前，begin初始为1
void SeqListPopFront(SL* ps)
{
	assert(ps);
	//删除就不需要考虑是否要扩容的问题
	int begin = 1;
	for (begin = 0; begin < ps->size; begin++)
	{
		ps->a[begin] = ps->a[begin + 1];
	}
	//完成头删之后就是要size-1
	ps->size--;

}

//实现尾删：size--就好
void SeqListPopBack(SL* ps)
{
	assert(ps);
	ps->size--;
}



void SeqListDestroy(SL* ps1)
{
	if (ps1->a != NULL)
	{
		free(ps1->a);//只有a的空间是动态开辟来的
		ps1->a = NULL;//free之后置为空指针
		ps1->capacity = 0;
		ps1->size = 0;
	}
}

//任意位置插入 
void SeqListInsert(SL* ps, int pos, SLDateType x)
{
	assert(ps);
	//判断插入位置合理
	assert(pos >= 0 && pos <= ps->size);
	//插入之前把pos以及后面的元素都往后移动
	int end = ps->size - 1;
	while (end >= pos)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	//插入
	ps->a[pos] = x;
	//插入之后有效的数据增加所以size++
	ps->size++;
}

//任意位置的删除
//
void SeqListErase(SL* ps, int pos)
{
	assert(ps);
	assert(pos>=0 && pos <= ps->size);
	//实现删除用后面的元素来覆盖掉前面的
	int begin = pos + 1;
	while (begin < ps->size)
	{
		ps->a[begin-1] = ps->a[begin];//用后面覆盖掉前面前一个的下表应该是begin-1为妙，防止越界
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