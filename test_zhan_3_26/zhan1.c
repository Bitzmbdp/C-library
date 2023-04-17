#include"zhan.h"
/*������������������������������������������ʼ����������������������������������������������������*/
void chushihua(zhan* lb)
{
	assert(lb);
	lb->a = NULL;
	lb->capacity = 0;
	lb->top = 0;
}



/*���������������������������������������������뺯������������������������������������������������*/
void charu(zhan* lb, LX x)
{
	assert(lb);
	if (lb->top == lb->capacity)
	{
		int newcapacity = lb->capacity == 0 ? 4 : lb->capacity * 2;
		LX* kongjian = realloc(lb->a, sizeof(LX) * newcapacity);
		if (kongjian == NULL)
		{
			printf("����ʧ�ܣ�����");
			exit(-1);
		}
		lb->a = kongjian;
		lb->capacity = newcapacity;
	}
	lb->a[lb->top] = x;
	lb->top++;
}



/*������������������������������������������βɾ��������������������������������������������������*/
void shanchu(zhan* lb)
{
	assert(lb);
	assert(!panduankongbukong(lb));
	lb->top--;
}



/*����������������������������������������ȡջ�����ݺ���������������������������������������������*/
LX quzhanding(zhan* lb)
{
	assert(lb);
	assert(!panduankongbukong(lb));
	return lb->a[lb->top - 1];
}



/*�����������������������������������������ж��Ƿ�Ϊ�պ�������������������������������������������*/
bool panduankongbukong(zhan* lb)
{
	return lb->top == 0;
}



/*�������������������������������������������ͷź�������������������������������������������������*/
void shifang(zhan* lb)
{
	assert(lb);
	free(lb->a);
	lb->a = NULL;
	lb->capacity = 0;
	lb->top = 0;
}