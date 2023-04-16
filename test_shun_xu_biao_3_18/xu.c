#include"shun.h"


/*������������������������������������������������ʼ��ʵ�֡�������������������������������������������*/
void SeqListInit(SL* ps)
{
	(*ps).a = NULL;
	(*ps).size = (*ps).capacity = 0;
}



/*�����������������������������������������������ݺ���ʵ�֡�������������������������������������������*/
void SeqListCheckCapacity(SL* ps)
{
	if ((ps->size) == (ps->capacity))
	{
		int newcapacity = (ps->capacity) == 0 ? 4 : (ps->capacity) * 2;
		//SLDataTypeָ�������ͣ�����int��Щ
		SLDataType* tmp = (SLDataType*)realloc((ps->a), (sizeof(SLDataType) * newcapacity));
		if (tmp == NULL)
		{
			printf("ʧ�ܣ�\n");
			exit(-1);//��ֹ����
		}
		(ps->a) = tmp;
		(ps->capacity) = newcapacity;
	}
}



/*������������������������������������������������ͷ��ʵ�֡�������������������������������������������*/
void SeqListPushFront(SL* ps, SLDataType x)
{
	//����Ƿ���Ҫ����
	SeqListCheckCapacity(ps);

	//�������֮��ʼŲ��
	int end = (ps->size) - 1;
	for (;end >= 0;end--)
	{
		ps->a[end + 1] = ps->a[end];
	}
	(ps->a[0]) = x;
	(ps->size)++;
}



/*������������������������������������������������β��ʵ�֡�������������������������������������������*/
void SeqListPushBack(SL* ps, SLDataType x)
{
	//����Ƿ���Ҫ����
	SeqListCheckCapacity(ps);

	//�ռ��㹻֮�󣬾Ϳ��Է�����ȥ��
	(ps->a[ps->size]) = x;
	(ps->size)++;
}



/*��������������������������������������������ͷɾ����ʵ�֡�������������������������������������������*/
void SeqListPopFront(SL* ps)
{
	int i = 0;
	for (i = 0;i < ((ps->size) - 1);i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	assert((ps->size) > 0);
	(ps->size)--;
}



/*��������������������������������������������βɾ����ʵ�֡�������������������������������������������*/
void SeqListPopBack(SL* ps)
{
	//if ((ps->size) > 0)
	//{
	//	//(ps->a[ps->size]) = 0;
	//	(ps->size)--;
	//}
	assert((ps->size) > 0);
	(ps->size)--;
}



/*��������������������������������������������xԪ�غ���ʵ�֡�����������������������������������������*/
int SeqListFind(SL* ps, SLDataType x)
{
	int i = 0;
	while (i < (ps->size))
	{
		if (ps->a[i] == x)
		{
			return i;
		}
		i++;
	}
	return -1;
}



/*��������������������������������������������x��pos�±꺯��ʵ�֡�������������������������������������*/
void SeqListInsert(SL* ps, int pos, SLDataType x)
{
	if (pos > (ps->size) || pos < 0)
	{
		printf("�±���󣬲���ʧ�ܣ�\n");
		return;
	}
	SeqListCheckCapacity(ps);
	int i = 0;
	int j = 0;
	int arr[100] = { 0 };
	while (i <= (ps->size))
	{
		if (i == pos)
		{
			arr[i] = x;
			i++;
		}
		else
		{
			arr[i] = (ps->a[j]);
			j++;
			i++;
		}
	}
	for (i = 0;i <= (ps->size);i++)
	{
		(ps->a[i]) = arr[i];
	}
	(ps->size)++;
}



/*����������������������������������������ɾ��pos�±�������ʵ�֡�������������������������������������*/
void SeqListErase(SL* ps, int pos)
{
	int arr[9999] = { 0 };
	int i = 0;//arr
	int j = 0;//ps.a
	for (i = 0;i < (ps->size);i++)
	{
		if (j == pos)
		{
			j++;
			i--;
		}
		else
		{
			arr[i] = (ps->a[j]);
			j++;
		}
	}
	for (i = 0;i < ((ps->size) - 1);i++)
	{
		(ps->a[i]) = arr[i];
	}
	(ps->size)--;
}



/*����������������������������������������������ӡ����ʵ�֡�������������������������������������������*/
SeqListprint(SL* ps)
{
	for (int i = 0;i < ps->size;i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}



/*�����������������������������������������������ٺ���ʵ�֡�������������������������������������������*/
void SeqListDestory(SL* ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->size = 0;
}