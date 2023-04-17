#include "da.h"

/*����������������������������������������������ʼ������������������������������������������������*/
void ChuShiHua(DD* pead)
{
	assert(pead);
	pead->a = (LX*)malloc(sizeof(LX) * 4);
	if (pead->a == NULL)
	{
		printf("����ʧ��!!!");
		exit(-1);
	}
	pead->mowei = 4;
	pead->size = 0;
}



/*������������������������������������������������������������������������������������������������*/
void jiaohuan(LX* e, LX* f)
{
	LX top = *e;
	*e = *f;
	*f = top;
}



/*�����������������������������������������������ƺ�����������������������������������������������*/
void shangyi(LX* a, int erzi)
{
	int fuqin = (erzi - 1) / 2;
	while (erzi > 0)
	{
		if (a[erzi] > a[fuqin])
		{
			jiaohuan(&a[erzi], &a[fuqin]);

			erzi = fuqin;
			fuqin = (erzi - 1) / 2;
		}
		else
		{
			break;
		}
	}
}



/*�����������������������������������������������뺯����������������������������������������������*/
void ChaRu(DD* pead, LX x)
{
	assert(pead);
	//�ж��Ƿ���Ҫ����
	if (pead->size == pead->mowei)
	{
		LX* tmp = (LX*)realloc((pead->a), (sizeof(LX) * (pead->mowei) * 2));
		if (tmp == NULL)
		{
			printf("����ʧ��!!!");
			exit(-1);
		}
		pead->a = tmp;
		pead->mowei *= 2;
	}
	//������ɣ���ʼ��ֵ
	pead->a[pead->size] = x;
	(pead->size)++;

	//�ж��Ƿ���Ҫ����
	shangyi(pead->a, pead->size - 1);
}



/*�����������������������������������������������ƺ�����������������������������������������������*/
void xiayi(LX* a, int jici, int fuqin)
{
	int erzi = (fuqin * 2) + 1;
	while (fuqin < jici)
	{
		if (erzi + 1 < jici && a[erzi + 1] > a[erzi])
		{
			++erzi;
		}

		if (a[fuqin] < a[erzi])
		{
			jiaohuan(&a[fuqin], &a[erzi]);
			fuqin = erzi;
			erzi = fuqin * 2 + 1;
		}
		else
		{
			break;
		}
	}
}



/*��������������������������������������������ɾ��������������������������������������������������*/
void shanchu(DD* pead)
{
	assert(pead);
	assert(!panduan(pead));
	
	//ɾ������
	jiaohuan(&(pead->a[0]), &(pead->a[pead->size - 1]));
	pead->size--;

	xiayi(pead->a, pead->size, 0);
}



/*��������������������������������������������ȡ��������������������������������������������������*/
int quding(DD* pead)
{
	assert(pead);
	return pead->a[0];
}



/*���������������������������������������������жϺ�����������������������������������������������*/
bool panduan(DD* pead)
{
	assert(pead);

	return pead->size == 0;
}




/*���������������������������������������������жϺ�����������������������������������������������*/
int sizef(DD* pead)
{
	assert(pead);
	return pead->size;
}
