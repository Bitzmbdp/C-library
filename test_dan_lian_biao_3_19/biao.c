#include"dan.h"

//β��
void test1()
{
	SLTDateType* plist = NULL;
	int x = 0;//shuzi
	int i = 0;
	int q = 0;//cishi
	printf("�����������뼸�����֣�->");
	scanf("%d", &q);
	printf("���������->");
	for(i-0;i<q;i++)
	{
		scanf("%d", &x);
		SListPushBack(&plist, x);
	}
	SListPrint(plist);
}


//�Ҳ�
void test2()
{
	SLTDateType* plist = NULL;
	int y = 0;//shuzi
	int i = 0;
	int q = 0;//cishi
	printf("\n�����������뼸�����֣�->");
	scanf("%d", &q);
	printf("\n���������->");
	for (i = 0;i < q;i++)
	{
		scanf("%d", &y);
		SListPushBack(&plist, y);
	}
	SListPrint(plist);

	int x = 0;//�±�
	int s = 0;//����
	printf("\n���������ڼ�����->");
qu:
	scanf("%d", &x);
	if (x > 0 && x <= q+1)
	{
		printf("\n����������->");
		scanf("%d", &s);
		SListInsert(&plist, (x - 1), s);//x:�±꣬s������
		SListPrint(plist);
	}
	else
	{
		printf("�����������������->");
		goto qu;//���������������
	}

	//���ٺ���
	SListDestory(&plist);
}


//��ɾ
void test3()
{
	SLTDateType* plist = NULL;
	int y = 0;//shuzi
	int i = 0;
	int q = 0;//cishi
	printf("\n�����������뼸�����֣�->");//q:һ����������
	scanf("%d", &q);
	printf("\n���������->");
	for (i = 0;i < q;i++)
	{
		scanf("%d", &y);
		SListPushBack(&plist, y);
	}
	SListPrint(plist);
	int pow = 0;
	printf("\n��������ɾ���ڼ�����");
qu:
	scanf("%d", &pow);//pow��ɾ���ڼ���
	if (pow <= q && pow >= 1)
	{
		SListErase(&plist, (pow - 1));
		SListPrint(plist);
	}
	else
	{
		printf("�����������������->");
		goto qu;
	}

	//���ٺ���
	SListDestory(&plist);
}


//���Һ���
void test4()
{
	SLTDateType* plist = NULL;
	int y = 0;//shuzi
	int i = 0;
	int q = 0;//cishi
	printf("\n�����������뼸�����֣�->");
	scanf("%d", &q);
	printf("\n���������->");
	for (i = 0;i < q;i++)
	{
		scanf("%d", &y);
		SListPushBack(&plist, y);
	}
	SListPrint(plist);

	//���Һ�������
	int x = 0;
	i = 1;
	printf("\n������Ҫ����ʲô���֣�->");
	scanf("%d", &x);
	//���ص�ַ�����ò�����Щ
	SLT* newplist = chazhao_and_xiugai(plist, x);
	while(newplist != NULL)
	{
		printf("\n��%d��%d�ĵ�ַ��%p", i++, (newplist->data), newplist);
		newplist = chazhao_and_xiugai((newplist->next), x);
	}


	//�޸�����
	printf("\n������Ҫ�޸�����ô��(�޸��밴1)->");
	scanf("%d", &q);
	if(q==1)
	{
		printf("\n��������Ҫ�޸�ʲô���֣�->");
		scanf("%d", &x);
		printf("\n��������Ҫ�޸ĳɶ��٣�->");
		scanf("%d", &y);
		newplist = chazhao_and_xiugai(plist, x);
		while (newplist != NULL)
		{
			(newplist->data) = y;
			newplist = chazhao_and_xiugai((newplist->next), x);
			q = -1;
		}
		if (q != -1 && newplist == NULL)
		{
			printf("δ�ҵ���\n");
		}
	}
	SListPrint(plist);

	//���ٺ���
	SListDestory(&plist);

}


//�˵�����
void caidan()
{
	printf("\n********************************************\n");
	printf("*****   1������              2��ɾ��   *****\n");
	printf("*****   3������              0���˳�   *****\n");
	printf("********************************************\n");
}


//ѡ����
void xuanze()
{
	int q = 0;
	int f = 0;
lai:
	caidan();
	printf("\n��ѡ��->");
	scanf("%d", &q);
	switch (q)
	{
	case 0:
		printf("�˳��ɹ���");
		break;
	case 1:
		test2();
		printf("\n������Ҫ������(��1����)->");
		scanf("%d", &f);
		if(f == 1)
		{
			printf("\n");
			goto lai;
		}
		else
		{
			printf("�˳��ɹ�");
			break;
		}
	case 2:
		test3();
		printf("\n������Ҫ������(��1����)->");
		scanf("%d", &f);
		if (f == 1)
		{
			printf("\n");
			goto lai;
		}
		else
		{
			printf("�˳��ɹ�");
			break;
		}
	case 3:
		test4();
		printf("\n������Ҫ������(��1����)->");
		scanf("%d", &f);
		if (f == 1)
		{
			printf("\n");
			goto lai;
		}
		else
		{
			printf("�˳��ɹ�");
			break;
		}
	default:
		printf("�����������������->");
		goto lai;
	}
}


int main()
{
	xuanze();
	return 0;
}