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
//	int sz;    //��¼��ǰ�����˶��ٸ���ϵ��//������������Ҫ��ֵ��ʼ����
//}Contact;



//��̬�汾
typedef struct Contact
{
	PeoInfo* data;
	int sz;//��¼���ǵ�ǰͨѶ¼�д�ŵ��˵���Ϣ����
	int capacity;//��¼��ʱͨѶ¼��ǰ���������

}Contact;

void InitContact(Contact* pc);
//��ʼ��ͨѶ¼��ֻ��Ҫ�ṹ���ָ��Ϳ���ͨ��ָ��ȥ�ҵ�data��������ʼ��

//������ϵ��
void AddContact(Contact* pc);
//ͬ��������ϵ�˾����޸�data��������ݣ����Ұ�sz+1��

//��ʾ������ϵ��
void ShowContact(const Contact* pc);

//ɾ����ϵ��
void DelContact(Contact* pc);

//����ָ����ϵ��
void SearchContact(Contact* pc);

//�޸�ָ����ϵ��
void ModifyContact(Contact* pc);

//������ϵ��
void SortContact(Contact* pc);

//�ͷ��ڴ�
void DestroyContact(Contact* pc);
//����ͨѶ¼���ݵ��ļ�
void SaveContact(Contact* pc);
//�����ļ���Ϣ��ͨѶ¼
void LoadContact(Contact* pc);