#pragma warning(disable:4996)
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define N 1000
typedef int SLDataType;//����

////��̬˳���
////�ص㣺������ˣ����ܲ�����
////ȱ�㣺�����Ŀռ���ʣ��������ȷ��
//typedef struct SeList
//{
//	SLDataType arr[N];//��̬˳���
//	int size;//�洢��������
//}SL;
//
////�ӿں��� -- ����������STL�ߣ������Ժ�ѧϰSTL
//
////��ʼ����	
//void SeqListInit(SL* ps);
////ͷ��
//void SeqListPushFront(SL* ps, SLDataType x);
////β��
//void SeqListPushBack(SL* ps, SLDataType x);
////ͷ�ڵ�
//void SeqListPopFront(SL* ps);
////β�ڵ�
//void SeqListPopBack(SL* ps);



//��������ʵ�ֶ�̬
typedef struct SeList
{
	SLDataType* a;
	int size;      //��ʾ�����д洢��������
	int capacity;  //����ʵ���ܴ������ݵĿռ������Ƕ��
}SL;


//��ӡ����
SeqListprint(SL* ps);


//�ӿں��� -- ����������STL�ߣ������Ժ�ѧϰSTL

//��ʼ������	
void SeqListInit(SL* ps);
//���ٺ���
void SeqListDestory(SL* ps);
//���ݺ���
void SeqListCheckCapacity(SL* ps);
//ͷ�庯��
void SeqListPushFront(SL* ps, SLDataType x);
//β�庯��
void SeqListPushBack(SL* ps, SLDataType x);
//ͷɾ��������
void SeqListPopFront(SL* ps);
//βɾ��������
void SeqListPopBack(SL* ps);
//��Ԫ�أ��ҵ������±�x���Ҳ�������-1
int SeqListFind(SL* ps, SLDataType x);
//ָ��pos�±����x�������
void SeqListInsert(SL* ps, int pos, SLDataType x);
//ɾ��posλ�õ�����
void SeqListErase(SL* ps, int pos);