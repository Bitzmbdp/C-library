#include"dan.h"


/*���������������������������������������������Ҳ庯��������������������������������������������*/
void SListInsert(SLT** pphead, SLTDateType x, SLTDateType s)//x�±꣬s����
{
	SLT* newjiedian = (SLT*)malloc(sizeof(SLT));
	if (newjiedian == NULL)
	{
		printf("�ڴ�����ʧ�ܣ�\n�����˳�������\n");
		exit(-1);
	}
	newjiedian->data = s;
	SLT* tali = (*pphead);
	if (x == 0)
	{
		newjiedian->next = tali;
		(*pphead) = newjiedian;
		return 0;
	}
	else
	{
		int i = 0;
		for (i = 0;i < x;i++)
		{
			tali = tali->next;
		}

		//�ҵ�Ŀ����
		newjiedian->next = tali;

		tali = (*pphead);

		for (i = 0;i < x - 1;i++)
		{
			tali = tali->next;
		}
		tali->next = newjiedian;
	}
}



/*����������������������������������������������ɾ����������������������������������������������*/
void SListErase(SLT** pphead, SLTDateType x)//x�±�
{
	int i = 0;
	SLT* tali = (*pphead);
	SLT* Tali = (*pphead);

	//�±�Ϊ0ʱ
	if (x == 0)
	{
		//����һ���µĽṹ�壬��ڶ�����ʼ�ĵ�ַ
		SLT* newpphead = tali->next;
		//�ͷŵ�һ���ռ�
		free(*pphead);
		(*pphead) = NULL;
		//���µ�ͷ�ռ丳���ϵ�
		(*pphead) = newpphead;
	}


	//���������
	else
	{
		for (i = 0;i < (x - 1);i++)
		{
			Tali = Tali->next;//�ҳ�x��ǰһ����ַ
		}
		for (i = 0;i <= x;i++)
		{
			tali = (tali->next);//�ҳ�x��һ����ַ
		}
		Tali->next = tali;
	}
}



/*����������������������������������������������庯��������������������������������������������*/
void SListPushBack(SLT* (*pphead), SLTDateType x)
{
	//�����½ڵ�ĵ�ַ
	SLT* newnode = (SLT*)malloc(sizeof(SLT));
	(newnode->data) = x;
	(newnode->next) = NULL;

	//�ж��Ƿ�Ϊ��һָ��//�ж��Ƿ���Ҫ����
	if ((*pphead) == NULL)
	{
		(*pphead) = newnode;//newnode�������½ڵ�ĵ�ַ
	}
	else
	{
		//������һ����ʱ��������������β�ڵ�
		SLT* tail = (*pphead);//SLT* (...)������˼���Ǵ���һ���µ�STL������
		//�ҵ�β�ڵ㣬Ȼ���new��ֵ������
		while ((tail->next) != NULL)
		{
			tail = (tail->next);
		}
		//��ʼ�Խ�
		(tail->next) = newnode;
	}
}



/*����������������������������������������������ӡ����������������������������������������������*/
void SListPrint(SLT* phead)
{
	SLT* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", (cur->data));
		cur = (cur->next);
	}
	printf("\n");
}




/*�����������������������������������������������Һ���������������������������������������������*/
SLTDateType* chazhao_and_xiugai(SLT* pphead, SLTDateType x)
{
	SLT*xunzhao = pphead;
	while (xunzhao != NULL)
	{
		if ((xunzhao->data) == x)
		{
			return xunzhao;
		}
		else
		{
			xunzhao = xunzhao->next;
		}
	}
	return NULL;
}



/*�����������������������������������������������ٺ���������������������������������������������*/
void SListDestory(SLT** pphead)
{
	SLT* shan = (*pphead);
	while (shan != NULL)
	{
		assert(pphead);
		SLT* new = shan->next;
		free(shan);
		shan = new;
	}
	(*pphead) = NULL;
}
