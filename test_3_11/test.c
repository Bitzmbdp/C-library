#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>//qsortͷ�ļ�
#include<string.h>
int bijiaofangfa(const void* q1, const void* q2);
void mofang_qsort(void* dizhi, int sz, int kuandu, int (*bijiao)(const void* el1, const void* el2));
//struct bq
//{
//	char* name;
//	int age;
//};
//
////////������
//////int bi_name(const void* el1, const void* el2)
//////{
//////	return strcmp((((struct bq*)el1)->name), (((struct bq*)el2)->name));
//////}
////
////������
//int bi_age(const void* el1, const void* el2)
//{
//	return ((struct bq*)el1)->age - ((struct bq*)el2)->age;
//}
//
//int main()
//{
//	struct bq B[] = { {"����",29}, {"����",26},{"����",17},{"����",28 } };
//	struct bq* q = &B;
//	int sz = sizeof(B) / sizeof(B[0]);
//
//	////������������
//	//qsort(B, sz, sizeof(B[0]), bi_name);
//	//for (int i = 0;i < sz;i++)
//	//{
//	//	printf("����������Ϊ��%s %d\n", (*q).name, (*q).age);
//	//	q++;
//	//}
//
//	//������������
//	qsort(B, sz, sizeof(B[0]), bi_age);
//	for (int i = 0;i < sz;i++)
//	{
//		printf("����������Ϊ��%s %d\n", (*q).name, (*q).age);
//		q++;
//	}
//	return 0;
//}



////ģ��qsortʵ�������ͨ���㷨
//
//////�Ƚ�������ĸ
////int bijiaofangfa(const void* q1, const void* q2)
////{
////	return strcmp(q1, q2);
////}
//
////�Ƚ�������
//int bijiaofangfa(const void* q1, const void* q2)
//{
//	return *(int*)q1 - *(int*)q2;
//}
//
////����������
//void jiaohuan(char* e1, char* e2,int kd)
//{
//	int i = 0;
//	for (i = 0;i < kd;i++)
//	{
//		char tmp = (*e1);
//		(*e1) = (*e2);
//		(*e2) = tmp;
//		e1++;
//		e2++;
//	}
//}
//
////����qsort�������岿��
//void mofang_qsort(void*dizhi,int sz,int kuandu,int (*bijiao)(const void*el1,const void*el2))
//{
//	//ȷ������
//	int i = 0;
//	for (i = 0;i < sz - 1;i++)
//	{
//		//��������
//		int j = 0;
//		for (j = 0;j < sz - i - 1;j++)
//		{
//			//����Ԫ�رȽ�
//			if (bijiao((char*)dizhi + (kuandu * j), (char*)dizhi + (kuandu * (j + 1))) > 0)//�����Ƚϵ�
//			{
//				//���н���
//				jiaohuan((char*)dizhi + (kuandu * j), (char*)dizhi + (kuandu * (j + 1)),kuandu);//����������
//			}
//		}
//	}
//}
//
////��ӡ����
//void print(int arr[], int sz)
//{
//	for (int i = 0;i < sz;i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}
//
//void shuzi()
//{
//	int arr[] = { 1,4,2,7,19,25,91,63,55,81,1,5 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	mofang_qsort(arr, sz, sizeof(arr[0]), bijiaofangfa);//һ����ס���Ǵ������Ƚϵ��Ǹ�������ȥ
//	print(arr, sz);
//}
//
//void zimu()
//{
//	char arr[] = { 'q','e','s','g','j','q','o','w','x','g' };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	mofang_qsort(arr, sz, sizeof(arr[0]), bijiaofangfa);//һ����ס���Ǵ������Ƚϵ��Ǹ�������ȥ
//	print(arr, sz);
//}
//int main()
//{
//	shuzi();
//	return 0;
//}


