#include "Book.h";
void menu()
{
	printf("=============================================================================\n");
	printf("=========            1.�����鼮              2.ɾ���鼮            ==========\n");
	printf("=========            3.�����鼮            4.�޸��鼮����          ==========\n");
	printf("=========         5.��ʾ�����鼮              6.��������           ==========\n");
	printf("===================                 0.exit                ===================\n");
}
int main()
{
	bookshelf books;
	Book book1;
	book1.name = "��������";
	book1.author = "�޹���";
	book1.press = "�Ϻ���������������";
	book1.ISBN = "2220423-1";
	book1.price = 69.9;
	book1.time = "Ԫĩ����";
	book1.type = "�Ĵ�����";
	Book book2;
	book2.name = "ˮ䰴�";
	book2.author = "ʩ����";
	book2.press = "�Ϻ���������������";
	book2.ISBN = "2220423-2";
	book2.price = 69.9;
	book2.time = "Ԫĩ����";
	book2.type = "�Ĵ�����";
	Book book3;
	book3.name = "��¥��";
	book3.author = "��ѩ��";
	book3.press = "�Ϻ���������������";
	book3.ISBN = "2220423-3";
	book3.price = 69.9;
	book3.time = "��Ǭ¡��ʮ���� (��Ԫ1784��)";
	book3.type = "�Ĵ�����";
	Book book4;
	book4.name = "���μ�";
	book4.author = "��ж�";
	book4.press = "�ӱ�����������";
	book4.ISBN = "2220423-4";
	book4.price = 69.9;
	book4.time = "����";
	book4.type = "�Ĵ�����";
	//��ʼ��
	InitList(&books, &book1, &book2, &book3, &book4);
	menu();
	printf("\n==================++++++++********��ӭ����ͼ��С��ϰ********++++++++==================\n");
	printf("\n��ѡ��->");
	int choose = 0;
	scanf("%d", &choose);
	while (1)
	{
		if (choose == 0)//��
		{
			printf("\n�˳��ɹ�!!!");
			break;
		}
		if (choose == 1)//��
		{
			Listinsert(&books);
		}
		if (choose == 2)//ɾ
		{
			//ɾ��
			ListDelete(&books);
			showbook(&books);
		}
		if (choose == 3)//��
		{
			//����
			char* ISBN = (char*)malloc(100 * sizeof(char));
			printf("\n��������Ҫ�����鼮ISBN->");
			scanf("%s", ISBN);
			char* name = (char*)malloc(100 * sizeof(char));
			printf("\n��������Ҫ�����鼮������->");
			scanf("%s", name);
			LocateElem(&books, ISBN, name);
		}
		if (choose == 4)//��
		{
			//�޸�
			ListAlter(&books);
		}
		if (choose == 5)//��ӡ
		{
			//��ӡ
			showbook(&books);
		}
		if (choose == 6)//����
		{
			ListOrder(&books);
			printf("��������Ҫ���±��滹��׷�ӱ���(1.���±��棬2.׷�ӱ���)?\n��ѡ��->");
			int n = 0;
			scanf("%d", &n);
			if (n == 1)
			{
				ove_bookshelf(&books);
			}
			if (n == 2)
			{
				save_bookshelf(&books);
			}
			if (books.size != 0) {
				printf("����ɹ�!!!\n");
			}
		}
		if (choose > 6 || choose < 0)//
		{
			printf("\n�����������������\n");
		}
		menu();
		printf("\n��ѡ��->");
		scanf("%d", &choose);
	}
	retBooks(&books);
	return 0;
}