#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"

//静态版本
//void InitContact(Contact* pc)//用结构体指针来访问data数组实现初始化
//{
//	assert(pc);//别忘记了assert一下养成好习惯
//
//	pc->sz= 0;
//	//想要吧结构体初始化使用memst函数需要三个参数 指针 值 多少个字节
//	memset(pc->data, 0, sizeof(pc->data));//这里的指针不是pc而是pc指向的data，数组名就是指针
//
//}
void CheckCapacity(Contact* pc);   //声明



 void CheckCapacity(Contact* pc)
{
	if (pc->sz == pc->capacity)
	{
		PeoInfo* ptr = (PeoInfo*)realloc(pc->data, (pc->capacity + DEFAULT_INC) * sizeof(PeoInfo));
		if (ptr != NULL)
		{
			pc->data = ptr;
			pc->capacity += DEFAULT_INC;  //#define DEFAULT_INC 2
			printf("增容成功\n");
		}
		else
		{
			perror("CheckCapacity->realloc");
			return;
		}
	}
}

 void LoadContact(Contact* pc)
 {
	 FILE* pf = fopen("contact.txt", "rb");
	 if (pf == NULL)
	 {
		 perror("LoadContact");
		 return;
	 }
	 //读文件
	 PeoInfo tmp = { 0 };
	 while (fread(&tmp, sizeof(PeoInfo), 1, pf))
	 {
		 CheckCapacity(pc);  //检测增容
		 pc->data[pc->sz] = tmp;
		 pc->sz++;
	 }

	 fclose(pf);
	 pf = NULL;
 }
//动态版本//动态版本--文件版本
void InitContact(Contact* pc)
{
	assert(pc);
	pc->sz = 0;
	pc->capacity = DEFAULT_SZ; //3
	pc->data = (PeoInfo*)calloc(pc->capacity, sizeof(PeoInfo));//calloc函数这里需要的大小就是容量乘一个peopinfo类型的大小
	//检查calloc开辟是否成功
	if (pc->data == NULL)
	{
		perror("InitContact->calloc");
			return;
	}
	//加载文件中的信息到通讯录
	LoadContact(pc);
}

void DestroyContact(Contact* pc)
{
	free(pc->data);
	pc->data = NULL;
	pc->sz = 0;
	pc->capacity = 0;
}

//静态版本
//void AddContact(Contact* pc)//要输入一个联系人的name，sex，age，tele，addre
//{
//	assert(pc);
//	printf("增加联系人\n");
//	printf("请输入名子\n");
//	scanf("%s", pc->data[pc->sz].name);//注意这里要是date数组的第几个就是是第几个联系人
//
//	printf("请输入年龄\n");
//	scanf("%d", &(pc->data[pc->sz].age));//为什么要是&，因为其他的是数组，所以不用取地址
//
//	printf("请输入性别\n");
//	scanf("%s", pc->data[pc->sz].sex);
//
//	printf("请输入电话:");
//	scanf("%s", pc->data[pc->sz].tele);
//	printf("请输入地址:");
//	scanf("%s", pc->data[pc->sz].addr);
//
//	pc->sz++;
//	printf("增加成功\n");
//
//}

//动态版本
void AddContact(Contact* pc)
{
	assert(pc);
	CheckCapacity(pc);

	printf("请输入名字:");
	scanf("%s", pc->data[pc->sz].name);
	printf("请输入年龄:");
	scanf("%d", &(pc->data[pc->sz].age));
	printf("请输入性别:");
	scanf("%s", pc->data[pc->sz].sex);
	printf("请输入电话:");
	scanf("%s", pc->data[pc->sz].tele);
	printf("请输入地址:");
	scanf("%s", pc->data[pc->sz].addr);

	pc->sz++;
	printf("增加成功\n");

}

void ShowContact(const Contact* pc)//使用printf函数完成。还要判断通讯录是不是为空的
{
	assert(pc);
	if (pc->sz == 0)//使用sz来判断，
	{
		printf("通讯录为空，无需打印\n");
		return;
	}
	int i = 0;
	printf("%-20s%-5d%-5s%-12s%-30s\n", "名字", "年龄", "性别", "电话", "地址");
	for (i = 0; i < pc->sz; i++)//循环sz次
	{
		printf("%-20s%-5s%-5s%-12s%-30s\n", 
			pc->data[i].name, pc->data[i].age, pc->data[i].sex, pc->data[i].tele, pc->data[i].addr);
	}
	//%-加上数字是左对齐
}

void SearchContact(Contact* pc)
{
	char name[NAME_MAX];
	assert(pc);
	printf("请输入要查找人的名字:");
	scanf("%s", name);

	int ret = FindByName(pc, name);
	if (ret == -1)
	{
		printf("要查找的人不存在\n");
		return;
	}
	//显示查查找到的信息

	printf("%-20s%-5s%-5s%-12s%-30s\n", "名字", "年龄", "性别", "电话", "地址");
	printf("%-20s%-5d%-5s%-12s%-30s\n",
		pc->data[ret].name, pc->data[ret].age, pc->data[ret].sex, pc->data[ret].tele, pc->data[ret].addr);


}

static int FindByName(Contact* pc, char name[])
{
	assert(pc);
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)  //两个字符串比较用strcmp
			return i;
	}
	return -1;
   

}


void DelContact(Contact* pc)//把目前这个联系人后面的r部分整体向前移动一位
{

	assert(pc);

	//首先要找到这个你要删除的联系人才可以，比如采用用名字来搜索
	char name[NAME_MAX];
	//先要判断通讯录是不是空的
	if (pc->sz = 0)
	{
		printf("通讯录为空，无法删除\n");
		return;
	}
	//代码到这里说明通讯录不为空
	//通过函数来找你想要的那个联系人
	printf("请输入要删除人的名字:");
	scanf("%s", name);

	int ret = FindByName(pc,name);//用ret接收返回值（就是想要找到那个联系人是第几个元素）
	if (ret == -1)
	{
		printf("要删除的人不存在\n");
		return;
	}
	int i = 0;
	for (i = 0; i < pc->sz - 1;i++)
	{
		pc->data[i] = pc->data[i + 1];
	}

	pc->sz--;
	printf("删除成功\n");
}




void ModifyContact(Contact* pc)
{
	char name[NAME_MAX];
	assert(pc);
	printf("请输入要修改人的名字:");
	scanf("%s", name);

	int ret = FindByName(pc, name);
	if (ret == -1)
	{
		printf("要修改的人不存在\n");
		return;
	}
	//修改
	printf("请输入名字:");
	scanf("%s", pc->data[ret].name);
	printf("请输入年龄:");
	scanf("%d", &(pc->data[ret].age));
	printf("请输入性别:");
	scanf("%s", pc->data[ret].sex);
	printf("请输入电话:");
	scanf("%s", pc->data[ret].tele);
	printf("请输入地址:");
	scanf("%s", pc->data[ret].addr);
	
	
}


int cmp_age(const void* e1, const void* e2)
{
	return ((PeoInfo*)e1)->age - ((PeoInfo*)e2)->age;
}

void SortContact(Contact* pc)
{
	assert(pc);
	if (pc->sz == 0)
	{
		printf("通讯录为空，无需排序\n");
		return;
	}
	qsort(pc, pc->sz, sizeof(PeoInfo), cmp_age);
	printf("排序成功\n");
}







void SaveContact(Contact* pc)
{
	FILE* pf = fopen("contact.txt", "wb");
	if (pf == NULL)
	{
		perror("SaveContact");
		return;
	}
	//写数据
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		fwrite(pc->data + i, sizeof(PeoInfo), 1, pf);
	}

	fclose(pf);
	pf = NULL;
}