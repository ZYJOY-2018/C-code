#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"
//ʵ��һ��ͨѶ¼��
//
//ͨѶ¼���������洢1000���˵���Ϣ��ÿ���˵���Ϣ�������������Ա����䡢�绰��סַ
//
//�ṩ������
//
//�����ϵ����Ϣ
//ɾ��ָ����ϵ����Ϣ
//����ָ����ϵ����Ϣ
//�޸�ָ����ϵ����Ϣ
//��ʾ������ϵ����Ϣ
//���������ϵ��
//����������������ϵ��

//��ʵ��һ���˵�

void menu()
{
	printf("***********************************\n");
	printf("******  1.add      2.del     ******\n");
	printf("******  3.search   4.modify  ******\n");
	printf("******  5.show     6.sort    ******\n");
	printf("******  0.exit               ******\n");
	printf("***********************************\n");
}
//ö�����Ϳ���ȡֵʹ�ö��Ÿ���,���һ�����ö���
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
	InitContact(&con);//��ʼ��ͨѶ¼

	int input = 0;
	do 
	{
		menu();
		printf("���������ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case EXIT:
			SaveContact(&con);//����ͨѶ¼���ݵ��ļ�
			DestroyContact(&con); //����ͨѶ¼
			printf("�˳�ͨѶ¼\n");
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
			SortContact(&con);			//������������
			break;
			//������дdefault
		default:
			printf("ѡ���������ѡ��\n");

		}
	} while (input);



	return 0;
}


