#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int LX;

typedef struct ListNode
{
	LX data;
	struct ListNode* next;
	struct ListNode* prev;
}LB;

//��ʼ��
LB* ListInit();
//����(1)
//void suibiancha(LB* phead, LX x, LX y);
//����(2)
void suibiancha(LB* pos, LX x);
//���ɾ

//ͷ��
void ListPushFront(LB* phead, LX x);
//ͷɾ
void ListPopFront(LB* phead);
//β��
void ListPushBack(LB* phead, LX x);
//βɾ
void ListPopBack(LB* phead);
//Ѱ������
LB* ListFind(LB* phead, LX x);
//��ӡ����
void ListPrintf(LB* phead);