#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"

//��̬�汾
//void InitContact(Contact* pc)//�ýṹ��ָ��������data����ʵ�ֳ�ʼ��
//{
//	assert(pc);//��������assertһ�����ɺ�ϰ��
//
//	pc->sz= 0;
//	//��Ҫ�ɽṹ���ʼ��ʹ��memst������Ҫ�������� ָ�� ֵ ���ٸ��ֽ�
//	memset(pc->data, 0, sizeof(pc->data));//�����ָ�벻��pc����pcָ���data������������ָ��
//
//}
void CheckCapacity(Contact* pc);   //����



 void CheckCapacity(Contact* pc)
{
	if (pc->sz == pc->capacity)
	{
		PeoInfo* ptr = (PeoInfo*)realloc(pc->data, (pc->capacity + DEFAULT_INC) * sizeof(PeoInfo));
		if (ptr != NULL)
		{
			pc->data = ptr;
			pc->capacity += DEFAULT_INC;  //#define DEFAULT_INC 2
			printf("���ݳɹ�\n");
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
	 //���ļ�
	 PeoInfo tmp = { 0 };
	 while (fread(&tmp, sizeof(PeoInfo), 1, pf))
	 {
		 CheckCapacity(pc);  //�������
		 pc->data[pc->sz] = tmp;
		 pc->sz++;
	 }

	 fclose(pf);
	 pf = NULL;
 }
//��̬�汾//��̬�汾--�ļ��汾
void InitContact(Contact* pc)
{
	assert(pc);
	pc->sz = 0;
	pc->capacity = DEFAULT_SZ; //3
	pc->data = (PeoInfo*)calloc(pc->capacity, sizeof(PeoInfo));//calloc����������Ҫ�Ĵ�С����������һ��peopinfo���͵Ĵ�С
	//���calloc�����Ƿ�ɹ�
	if (pc->data == NULL)
	{
		perror("InitContact->calloc");
			return;
	}
	//�����ļ��е���Ϣ��ͨѶ¼
	LoadContact(pc);
}

void DestroyContact(Contact* pc)
{
	free(pc->data);
	pc->data = NULL;
	pc->sz = 0;
	pc->capacity = 0;
}

//��̬�汾
//void AddContact(Contact* pc)//Ҫ����һ����ϵ�˵�name��sex��age��tele��addre
//{
//	assert(pc);
//	printf("������ϵ��\n");
//	printf("����������\n");
//	scanf("%s", pc->data[pc->sz].name);//ע������Ҫ��date����ĵڼ��������ǵڼ�����ϵ��
//
//	printf("����������\n");
//	scanf("%d", &(pc->data[pc->sz].age));//ΪʲôҪ��&����Ϊ�����������飬���Բ���ȡ��ַ
//
//	printf("�������Ա�\n");
//	scanf("%s", pc->data[pc->sz].sex);
//
//	printf("������绰:");
//	scanf("%s", pc->data[pc->sz].tele);
//	printf("�������ַ:");
//	scanf("%s", pc->data[pc->sz].addr);
//
//	pc->sz++;
//	printf("���ӳɹ�\n");
//
//}

//��̬�汾
void AddContact(Contact* pc)
{
	assert(pc);
	CheckCapacity(pc);

	printf("����������:");
	scanf("%s", pc->data[pc->sz].name);
	printf("����������:");
	scanf("%d", &(pc->data[pc->sz].age));
	printf("�������Ա�:");
	scanf("%s", pc->data[pc->sz].sex);
	printf("������绰:");
	scanf("%s", pc->data[pc->sz].tele);
	printf("�������ַ:");
	scanf("%s", pc->data[pc->sz].addr);

	pc->sz++;
	printf("���ӳɹ�\n");

}

void ShowContact(const Contact* pc)//ʹ��printf������ɡ���Ҫ�ж�ͨѶ¼�ǲ���Ϊ�յ�
{
	assert(pc);
	if (pc->sz == 0)//ʹ��sz���жϣ�
	{
		printf("ͨѶ¼Ϊ�գ������ӡ\n");
		return;
	}
	int i = 0;
	printf("%-20s%-5d%-5s%-12s%-30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
	for (i = 0; i < pc->sz; i++)//ѭ��sz��
	{
		printf("%-20s%-5s%-5s%-12s%-30s\n", 
			pc->data[i].name, pc->data[i].age, pc->data[i].sex, pc->data[i].tele, pc->data[i].addr);
	}
	//%-���������������
}

void SearchContact(Contact* pc)
{
	char name[NAME_MAX];
	assert(pc);
	printf("������Ҫ�����˵�����:");
	scanf("%s", name);

	int ret = FindByName(pc, name);
	if (ret == -1)
	{
		printf("Ҫ���ҵ��˲�����\n");
		return;
	}
	//��ʾ����ҵ�����Ϣ

	printf("%-20s%-5s%-5s%-12s%-30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
	printf("%-20s%-5d%-5s%-12s%-30s\n",
		pc->data[ret].name, pc->data[ret].age, pc->data[ret].sex, pc->data[ret].tele, pc->data[ret].addr);


}

static int FindByName(Contact* pc, char name[])
{
	assert(pc);
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)  //�����ַ����Ƚ���strcmp
			return i;
	}
	return -1;
   

}


void DelContact(Contact* pc)//��Ŀǰ�����ϵ�˺����r����������ǰ�ƶ�һλ
{

	assert(pc);

	//����Ҫ�ҵ������Ҫɾ������ϵ�˲ſ��ԣ��������������������
	char name[NAME_MAX];
	//��Ҫ�ж�ͨѶ¼�ǲ��ǿյ�
	if (pc->sz = 0)
	{
		printf("ͨѶ¼Ϊ�գ��޷�ɾ��\n");
		return;
	}
	//���뵽����˵��ͨѶ¼��Ϊ��
	//ͨ��������������Ҫ���Ǹ���ϵ��
	printf("������Ҫɾ���˵�����:");
	scanf("%s", name);

	int ret = FindByName(pc,name);//��ret���շ���ֵ��������Ҫ�ҵ��Ǹ���ϵ���ǵڼ���Ԫ�أ�
	if (ret == -1)
	{
		printf("Ҫɾ�����˲�����\n");
		return;
	}
	int i = 0;
	for (i = 0; i < pc->sz - 1;i++)
	{
		pc->data[i] = pc->data[i + 1];
	}

	pc->sz--;
	printf("ɾ���ɹ�\n");
}




void ModifyContact(Contact* pc)
{
	char name[NAME_MAX];
	assert(pc);
	printf("������Ҫ�޸��˵�����:");
	scanf("%s", name);

	int ret = FindByName(pc, name);
	if (ret == -1)
	{
		printf("Ҫ�޸ĵ��˲�����\n");
		return;
	}
	//�޸�
	printf("����������:");
	scanf("%s", pc->data[ret].name);
	printf("����������:");
	scanf("%d", &(pc->data[ret].age));
	printf("�������Ա�:");
	scanf("%s", pc->data[ret].sex);
	printf("������绰:");
	scanf("%s", pc->data[ret].tele);
	printf("�������ַ:");
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
		printf("ͨѶ¼Ϊ�գ���������\n");
		return;
	}
	qsort(pc, pc->sz, sizeof(PeoInfo), cmp_age);
	printf("����ɹ�\n");
}







void SaveContact(Contact* pc)
{
	FILE* pf = fopen("contact.txt", "wb");
	if (pf == NULL)
	{
		perror("SaveContact");
		return;
	}
	//д����
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		fwrite(pc->data + i, sizeof(PeoInfo), 1, pf);
	}

	fclose(pf);
	pf = NULL;
}