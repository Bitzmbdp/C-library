#pragma warning(disable:4996)
#pragma once
#include<Assert.h>
#include<stdio.h>
#include<stdlib.h>//mallocͷ�ļ�
typedef int SLTDateType;

typedef struct SListNode//SListNode�����������
{
	SLTDateType data;//data�����������
	struct SListNode* next;//nest��������׵�ַ
}SLT;


//����
void SListInsert(SLT** pphead, SLTDateType x, SLTDateType s);
//���ɾ
void SListErase(SLT** pphead, SLTDateType x);

//���
void SListPushBack(SLT** pphead, SLTDateType x);
//��ӡ����
void SListPrint(SLT* phead);
//���ٺ���
void SListDestory(SLT** pphead);
//���Һ���
SLTDateType* chazhao_and_xiugai(SLT* pphead, SLTDateType x);
//ɾ������
void SListDestory(SLT **pphead);