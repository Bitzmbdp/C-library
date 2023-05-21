#include "Book.h";

/*=============================================��ʼ��============================================*/
void InitList(bookshelf* L, Book* book1, Book* book2, Book* book3, Book* book4)
{
	if (L == NULL) {
		return;
	}
	L->book[0] = *book1;
	L->book[1] = *book2;
	L->book[2] = *book3;
	L->book[3] = *book4;
	L->length = 999;//�ȶ���3����
	L->size = 4;
}

/*==============================================����=============================================*/
void LocateElem(bookshelf* L, char* ISBN, char* name)
{
	printf("==============================================�����鼮=============================================");
	/*��1����ISBM�����в���
	 ��2������������*/
	printf("\n������Ҫ����ʲô��ʽ����?(��1����ISBM�����в��ҿ�2������������)->");
	int choose = 0;
	int i = 0;
qu:
	scanf("%d", &choose);
	//ISBM
	if (choose == 1)
	{
		while (i < L->size)
		{
			if (strcmp((L->book[i].ISBN), ISBN) == 0)
			{
				printf("============================================================================================================\n");
				printf("����->%s ; ����->%s ; ������->%s ; ISBN->%s ;����ʱ��->%s ; �۸�->%lf ; ���->%s\n", L->book[i].name, L->book[i].author, L->book[i].press, L->book[i].ISBN, L->book[i].time, L->book[i].price, L->book[i].type);
				printf("============================================================================================================");
				return;
			}
			i++;
		}
	}
	//����
	else if (choose == 2)
	{
		for (int i = 0; i < L->size; i++)
		{
			if (strcmp((L->book[i].name), name) == 0)
			{
				printf("============================================================================================================\n");
				printf("����->%s ; ����->%s ; ������->%s ; ISBN->%s ;����ʱ��->%s ; �۸�->%lf ; ���->%s\n", L->book[i].name, L->book[i].author, L->book[i].press, L->book[i].ISBN, L->book[i].time, L->book[i].price, L->book[i].type);
				printf("============================================================================================================");
				return;
			}
		}
	}
	else
	{
		printf("\n�����������������->");
		goto qu;
	}
	printf("\nδ�ҵ����鼮!!!\n");
}

/*==============================================����=============================================*/
void Listinsert(bookshelf* L)
{
	//ʹ��β������
	printf("==============================================�����鼮=============================================");
	char* name = (char*)malloc(100 * sizeof(char));
	printf("\n����������->");
	scanf("%s", name);

	char* author = (char*)malloc(100 * sizeof(char));
	printf("\n����������->");
	scanf("%s", author);

	char* press = (char*)malloc(100 * sizeof(char));
	printf("\n�����������->");
	scanf("%s", press);

	char* ISBN = (char*)malloc(100 * sizeof(char));
	printf("\n������ISBN->");
	scanf("%s", ISBN);

	char* time = (char*)malloc(100 * sizeof(char));
	printf("\n���������ʱ��->");
	scanf("%s", time);

	double price;
	printf("\n������۸�->");
	scanf("%lf", &price);

	char* type = (char*)malloc(100 * sizeof(char));
	printf("\n�������鼮����->");
	scanf("%s", type);
	Book book;
	book.name = name;
	book.author = author;
	book.press = press;
	book.ISBN = ISBN;
	book.time = time;
	book.price = price;
	book.type = type;
	L->book[L->size] = book;
	(L->size)++;
}

/*==============================================ɾ��=============================================*/
void ListDelete(bookshelf* L)
{
	printf("==============================================ɾ���鼮=============================================");
	int i = 0;
	printf("\n��������Ҫɾ���鼮��ISBN->");
	char* ISBN = (char*)malloc(100 * sizeof(char));
	scanf("%s", ISBN);
	while (i < L->size)
	{
		if (strcmp((L->book[i].ISBN), ISBN) == 0)
		{
			for (int j = i; (j + 1) < L->size; j++)
			{
				L->book[j] = L->book[j + 1];
			}
			(L->size)--;
			printf("\nɾ���ɹ�!!!\n");
			return;
		}
		i++;
	}
	printf("\nδ�ҵ��鼮!!!\n");
}

/*==============================================�޸�=============================================*/
void ListAlter(bookshelf* L)
{
	printf("==============================================�޸��鼮=============================================");
	printf("\n���Ȳ��Ҵ��鼮(��������鼮��ISBN)->");
	int i = 0;
	int flag = 0;
	char* ISBN = (char*)malloc(100 * sizeof(char));
	scanf("%s", ISBN);
	while (i < L->size)
	{
		if (strcmp((L->book[i].ISBN), ISBN) == 0)
		{
			flag = 1;
			break;
		}
		i++;
	}
	//�����ȥ�ˣ�˵���ҵ���
	if (flag == 1)
	{
		//��ʼ�޸ģ��޸�ʲô���͵����ݣ�switch���
		int choose;
		printf("\n(1��������2�����ߣ�3�������磻4��ISBN��5���۸�6������ʱ�䣻7���鼮����)\n��ѡ����Ҫ�޸ĸ��鼮��ʲô->");
		scanf("%d", &choose);
		if (choose == 1)
		{
			char* name = (char*)malloc(100 * sizeof(char));
			printf("\n�������޸ĺ������->");
			scanf("%s", name);
			L->book[i].name = name;
		}

		if (choose == 2){
			char* author = (char*)malloc(100 * sizeof(char));
			printf("\n�������޸ĺ������->");
			scanf("%s", author);
			L->book[i].author = author;
		}

		if (choose == 3) {
			char* press = (char*)malloc(100 * sizeof(char));
			printf("\n�������޸ĺ�ĳ�����->");
			scanf("%s", press);
			L->book[i].press = press;
		}

		if (choose == 4) {
			char* ISBN = (char*)malloc(100 * sizeof(char));
			printf("\n�������޸ĺ��ISBN->");
			scanf("%s", ISBN);
			L->book->ISBN = ISBN;
		}

		if (choose == 6) {
			char* time = (char*)malloc(100 * sizeof(char));
			printf("\n�������޸ĺ�ĳ���ʱ��->");
			scanf("%s", time);
			L->book[i].time = time;
		}

		if (choose == 5) {
			double price;
			printf("\n�������޸ĺ�ļ۸�->");
			scanf("%lf", &price);
			L->book->price = price;
		}

		if (choose == 7) {
			char* type = (char*)malloc(100 * sizeof(char));
			printf("\n�������޸ĺ���鼮����->");
			scanf("%s", type);
			L->book[i].type = type;
		}
	}
	else
	{
		//˵��δ�ҵ�
		printf("\nδ�ҵ����鼮!!!\n");
	}
}

/*==============================================����=============================================*/
Status compare(const void* a, const void* b) {
	Book* x = (Book*)a;
	Book* y = (Book*)b;

	//�ȸ��ݳ������������
	Status press_cmp = strcmp(x->press, y->press);

	//�������0�Ļ���˵�������粻��ͬ��ֱ���������
	if (press_cmp != 0) {
		return press_cmp;
	}
	//������˵����������ͬ���ٸ���ʱ������
	else {
		return strcmp(x->time, y->time);
	}
}

void ListOrder(bookshelf* L)
{
	// ����ʹ��qsort����
	qsort(L->book, L->size, sizeof(Book), compare);

}

/*=========================================��ӡ�鼮����==========================================*/
void showbook(bookshelf* L)
{
	if (L->size == 0)
	{
		printf("\nһ���鶼û����!!!\n");
		return;
	}
	//ÿ�δ�ӡ֮ǰ���Ÿ���
	ListOrder(L);
	int i = 0;				
	printf("========================================================================================================================\n");
	while (i < L->size)
	{
		printf("\n����->%s ; ����->%s ; ������->%s ; ISBN->%s ;����ʱ��->%s ; �۸�->%lf ; ���->%s\n", L->book[i].name, L->book[i].author, L->book[i].press, L->book[i].ISBN, L->book[i].time, L->book[i].price, L->book[i].type);
		i++;
	}
	printf("========================================================================================================================\n");
}

/*=========================================�����鼮����==========================================*/
//׷��д��
void save_bookshelf(bookshelf* L) {
	if (L->size == 0)
	{
		printf("\nһ���鶼û����!!!\n");
		return;
	}
	FILE* file;
	file = fopen("Books.txt", "a"); // ��׷��ģʽ���ļ�
	if (file == NULL) {
		printf("�޷����ļ�");
		return;
	}

	// ѭ��׷�����ݵ��ļ���
	for (int i = 0; i < L->size; i++) {
		Book* book = &(L->book[i]);
		fprintf(file, "������%s, ���ߣ�%s, �����磺%s, ISBN��%s, �۸�: %f, ����ʱ��: %s, ����: %s\n", book->name, book->author, book->press, book->ISBN, book->price, book->time, book->type);
	}

	fclose(file);
}
//����д��
void ove_bookshelf(bookshelf* L) {
	if (L->size == 0)
	{
		printf("\nһ���鶼û����!!!\n");
		return;
	}
	FILE* file;
	file = fopen("Books.txt", "w"); // ��д��ģʽ���ļ�
	if (file == NULL) {
		printf("�޷����ļ�\n");
		return -1;
	}
	// ��д���µ�����
	fputs("�µ��鼮��Ϣ->\n", file);
	fclose(file);

	// ��׷�����ݵ��ļ���
	file = fopen("Books.txt", "a"); // ��׷��ģʽ���ļ�
	if (file == NULL) {
		printf("�޷����ļ�\n");
		return -1;
	}
	int size = L->size;
	for (int i = 0; i < size; i++) {
		Book* book = &(L->book[i]);
		fprintf(file, "������%s, ���ߣ�%s, �����磺%s, ISBN��%s, �۸�: %f, ����ʱ��: %s, ����: %s\n", book->name, book->author, book->press, book->ISBN, book->price, book->time, book->type);
	}
	fclose(file);
}


/*=========================================�ͷź���==========================================*/
void retBooks(bookshelf* L)
{
	// ��Ϊ L ���ɵ��ú�����������ָ����������ҪС���ͷ��ڴ��ʱ���ͷ�ʽ
	free(L->book);    // �ͷ� book ������ڴ�
	L->size = 0;      // size ��Ϊ 0����ʾ�����Ѿ����ͷ�
	free(L);        // ��� L ���ڵ��ú������涨��ģ�������Կ����Ƿ���Ҫ�� L ���ڴ�Ҳһ���ͷ�
}