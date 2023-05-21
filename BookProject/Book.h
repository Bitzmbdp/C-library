#pragma warning(disable:4996)
#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 20
typedef int Status;

//�����鱾����
typedef struct {
	char* name;//����
	char* author;//����
	char* press;//������
	char* ISBN;//���
	double price;//�۸�
	char* time;//����ʱ��
	char* type;//����
}Book;

//�������
typedef struct {
	Book book[999];
	int length;//��ܵĳ���
	int size;//ʵ�ʵ��鱾
}bookshelf;

void InitList(bookshelf* L, Book* book1, Book* book2, Book* book3, Book* book4); //��ʼ��
void LocateElem(bookshelf* L, char* ISBN, char* name);//���� 
void Listinsert(bookshelf* L); //����
void ListDelete(bookshelf* L); //ɾ��
void ListAlter(bookshelf* L); //�޸�
void ListOrder(bookshelf* L); //����
void showbook(bookshelf* L);//��ӡ�鼮����
void save_bookshelf(bookshelf* L);//׷��д���ļ�
void ove_bookshelf(bookshelf* L);//����д��
void retBooks(bookshelf* L);//�ͷ��ڴ�