#include"shuang.h"

void test()
{
	//��ʼ������
	LB* plist = ListInit();

	//β��
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	//��ӡ����
	ListPrintf(plist);

	//βɾ
	ListPopBack(plist);
	ListPopBack(plist);
	//��ӡ����
	ListPrintf(plist);

	//ͷ��
	ListPushFront(plist, 12);
	ListPushFront(plist, 13);
	ListPushFront(plist, 14);
	ListPushFront(plist, 15);
	//��ӡ����
	ListPrintf(plist);

	//ͷɾ
	ListPopFront(plist);
	ListPopFront(plist);
	ListPopFront(plist);
	//��ӡ����
	ListPrintf(plist);

	//���Һ���
	LB* dizhi = ListFind(plist, 2);
	printf("%p\n", dizhi);

	//���庯��(1)
	//suibiancha(plist, 2, 14);//2����2֮ǰ���룬14������14
	//���庯��(2)
	suibiancha(dizhi,14);//����Ҫ����ĵ�ַ����ȥ������ǰһ������
	//��ӡ����
	ListPrintf(plist);

}


int main()
{
	test();
	return 0;
}