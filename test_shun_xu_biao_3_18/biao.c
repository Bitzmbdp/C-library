#include"shun.h"
#define N 100;

void TestSeqList1(int q)
{
	SL sl;
	//��ʼ������
	SeqListInit(&sl);

	if (q > 0 && q < 8)
	{
		int g = 0;
		//��β����һЩ����
		printf("�����5������->");
		for(int u=0;u<5;u++)
		{
			scanf("%d", &g);
			SeqListPushBack(&sl, g);
		}
		printf("\nԭ��˳���:\n");
		SeqListprint(&sl);
	}

	//ͷ�庯��
	if (q == 1)
	{
		//ͷ�庯��
		int x = 0;
		int w = 0;
		int i = 0;
		printf("��������ͷ�弸�Σ�->");
		scanf("%d", &w);//����
		printf("��������ͷ��ʲô����->");
		for (i = 0;i < w;i++)
		{
			scanf("%d", &x);//��������
			SeqListPushFront(&sl, x);
		}
		printf("\nͷ��֮��:\n");
		//��ӡ��Ч��
		SeqListprint(&sl);
	}

	//ͷɾ����
	if (q == 2)
	{
		int x = 0;
		printf("��������ͷɾ������->");
		scanf("%d", &x);
		//ͷɾ����
		for (int i = 0;i < x;i++)
		{
			SeqListPopFront(&sl);
		}
		printf("\nͷɾ֮��:\n");
		//��ӡ��Ч��
		SeqListprint(&sl);
	}

	//β�庯��
	if(q==3)
	{
		//β�屾��
		int y = 0;
		int w = 0;
		int i = 0;
		printf("��������弸�Σ�->");
		scanf("%d", &w);//����
		printf("���������ʲô����->");
		for (i = 0;i < w ;i++)
		{
			scanf("%d", &y);//��������
			SeqListPushBack(&sl, y);
		}
		printf("\nβ��֮��\n");
		//��ӡ����
		SeqListprint(&sl);
	}

	//βɾ����
	if(q==4)
	{
		int s = 0;
		printf("��������βɾ������->");
		scanf("%d", &s);
		for (int i = 0;i < s;i++)
		{
			//βɾ����
			SeqListPopBack(&sl);
		}
		printf("\nβɾ֮��:\n");
		//��ӡ��Ч��
		SeqListprint(&sl);
	}

	//����Ԫ�غ���
	if(q==5)
	{
		//����Ԫ�غ�������
		int x = 0;
		printf("������Ҫ����ʲô���֣�->");
		do
		{
			scanf("%d", &x);
			int f = SeqListFind(&sl, x);
			if (f != (-1))
			{
				printf("��������ڵ�%d��\n", (f + 1));
				break;
			}
			else
			{
				printf("�ܱ�Ǹ�������������,������->");
			}
		} while (x);
	}

	//����x��pos�±꺯��
	if (q == 6)
	{
		int x = 0;//�±�
		int y = 0;//Ԫ��
		//���뺯������
		printf("\n���ڼ�����->");
		scanf("%d", &x);
		printf("���ʲô���֣�->");
		scanf("%d", &y);
		SeqListInsert(&sl, (x - 1), y);
		if (x >= 0 && x <= (sl.size))
		{
			printf("\n����֮��:\n");
			SeqListprint(&sl);
		}
	}

	//ɾ���±�Ϊpos��Ԫ��
	if (q == 7)
	{
		int b = 0;
		//ɾ����������
		printf("������ɾ���ڼ���Ԫ�أ�->");
		scanf("%d", &b);
		SeqListErase(&sl, (b - 1));

		printf("\nɾ��֮��\n");
		SeqListprint(&sl);
	}

	//���ٺ���
	SeqListDestory(&sl);
}

//�˵�����
void caidan()
{
	printf("****************************************\n");
	printf("****1��ͷ��                  2��ͷɾ****\n");
	printf("****3��β��                  4��βɾ****\n");
	printf("***5������Ԫ��            6������Ԫ��***\n");
	printf("***7��ɾ��Ԫ��               0���˳�****\n");
	printf("****************************************\n");
}

int main()
{
	int q = 0;
	caidan();
	do
	{
		do
		{
			printf("\n�����������ʲô��->");
			break;
		} while (q > 0 && q < 8);

		scanf("%d", &q);
		if(q > 7)
		{
			printf("ѡ�����������ѡ��->");
		}
		if (q == 0)
		{
			printf("\n�˳��ɹ���\n");
		}
		TestSeqList1(q);
	} while (q);
	return 0;
}