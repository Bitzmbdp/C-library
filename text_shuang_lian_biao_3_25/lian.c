#include"shuang.h"
/*！！！！！！！！！！！！！！！！！！！！兜兵晒痕方議糞�屐�！！！！！！！！！！！！！！！！！！！*/
LB* ListInit()
{
	LB* phead = (LB*)malloc(sizeof(LB));
	phead->next = phead;
	phead->prev = phead;
	return phead;
}



/*！！！！！！！！！！！！！！！！！！！！昧宴峨痕方糞�屐�！！！！！！！！！！！！！！！！！！！！*/
//void suibiancha(LB* phead, LX x, LX y)
//{
//	assert(phead);
//	LB* cur = phead->next;
//	LB* cha = (LB*)malloc(sizeof(LB));
//	cha->data = y;
//	while (cur != phead)
//	{
//		if (cur->data == x)
//		{
//			LB* qcur = cur->prev;
//			qcur->next = cha;
//			cur->prev = cha;
//			cha->prev = qcur;
//			cha->next = cur;
//			//嬉咫痕方
//			ListPrintf(phead);
//			break;
//		}
//		cur = cur->next;
//	}
//	if (cur == phead)
//	{
//		printf("孀音欺峺協峨秘了崔\n");
//	}
//}


void suibiancha(LB* pos,LX x)
{
	assert(pos);
	LB* new = (LB*)malloc(sizeof(LB));
	new->data = x;
	LB* qpos = pos->prev;
	qpos->next = new;
	pos->prev = new;
	new->prev = qpos;
	new->next = pos;
}




/*！！！！！！！！！！！！！！！！！！！！遊峨痕方議糞�屐�！！！！！！！！！！！！！！！！！！！！*/
void ListPushFront(LB* phead, LX x)
{
	assert(phead);
	LB* newhead = (LB*)malloc(sizeof(LB));
	newhead->data = x;
	newhead->next = phead->next;
	phead->next->prev = newhead;
	newhead->prev = phead;
	phead->next = newhead;
}



/*！！！！！！！！！！！！！！！！！！！！遊評痕方議糞�屐�！！！！！！！！！！！！！！！！！！！！*/
void ListPopFront(LB* phead)
{
	assert(phead);
	assert(phead->next != phead);
	LB* newhead = phead->next->next;
	free(phead->next);
	phead->next->next = phead->next->prev = phead->next->data = NULL;
	phead->next = newhead;
	newhead->prev = phead;
}



/*！！！！！！！！！！！！！！！！！！！！硫峨痕方議糞�屐�！！！！！！！！！！！！！！！！！！！！*/
void ListPushBack(LB* phead, LX x)
{
	assert(phead);
	LB* mowei = phead->prev;
	LB* newmowei = (LB*)malloc(sizeof(LB));

	//蝕兵全俊
	mowei->next = newmowei;
	newmowei->prev = mowei;
	newmowei->next = phead;
	phead->prev = newmowei;

	//験峙
	newmowei->data = x;
}



/*！！！！！！！！！！！！！！！！！！！！硫峨痕方議糞�屐�！！！！！！！！！！！！！！！！！！！！*/
void ListPopBack(LB* phead)
{
	assert(phead);
	assert(phead->next != phead);

	LB* nweweibu = phead->prev->prev;
	free(phead->prev);
	phead->prev->next = NULL;
	phead->prev->prev = NULL;
	phead->prev = nweweibu;
	nweweibu->next = phead;
}



/*！！！！！！！！！！！！！！！！！！！！臥孀痕方議糞�屐�！！！！！！！！！！！！！！！！！！！！*/
LB* ListFind(LB* phead, LX x)
{
	assert(phead);

	LB* chazhao = phead->next;
	while (chazhao != phead)
	{
		if (chazhao->data == x)
		{
			return chazhao;
		}
		chazhao = chazhao->next;
	}
	return NULL;
}



/*！！！！！！！！！！！！！！！！！！！！嬉咫痕方議糞�屐�！！！！！！！！！！！！！！！！！！！！*/
void ListPrintf(LB* phead)
{
	assert(phead);
	LB* n = phead->next;
	while (n != phead)
	{
		printf("%d ", n->data);
		n = n->next;
	}
	printf("\n");
}