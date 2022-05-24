#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef int ElemType;
typedef struct {
	ElemType *elem;//�������飬���ڴ�����̬����
	int TableLen;//�洢��̬������Ԫ�صĸ���
}SSTable;

//��ʼ������
void ST_Init(SSTable& ST, int len) {//len������ĸ���
	ST.TableLen = len + 1;//������һλ�����ڱ�
	ST.elem = (ElemType*)malloc(sizeof(ElemType) * ST.TableLen);
	int i;
	srand(time(NULL));//���������
	for (i = 0; i < ST.TableLen; i++) {
		ST.elem[i] = rand() % 100;//���������
	}
}
//��������ĳԪ��
int Search_Seq(SSTable ST, ElemType key) {
	ST.elem[0] = key;                           //�����Ԫ����Ϊ�ڱ�
	for (int i = ST.TableLen - 1; ST.elem[i] != key; --i)
	return i;
}
//��ӡ����
void ST_print(SSTable ST) {
	for (int i = 0; i < ST.TableLen; i++) {
		printf("%3d", ST.elem[i]);
	}
	printf("\n");
}
//���ֲ���
int Binary_Search(SSTable L, ElemType key) {            //ÿ���۰�
	int low = 0, high = L.TableLen - 1, mid;
	while (low <= high) {                               //low <= high �ܹ����ҵ����һ��Ԫ��
		mid = (low + high) / 2;
		if (key == L.elem[mid])
			return mid;
		if (key < L.elem[mid]) {
			high = mid - 1;
		}
		if (key > L.elem[mid]) {
			low = mid + 1;
		}
	}
	return -1;//û���ҵ�
}


int compare(const void* left, const void* right)//left��right����������Ԫ�صĵ�ֵַ
{
	return *(ElemType*)left - *(ElemType*)right;
	//return *(ElemType*)right - *(ElemType*)left;//�Ӵ�С
}

int main() {
	SSTable ST;
	ElemType key;
	int pos;//�洢��ѯԪ�ص�λ��
	ST_Init(ST, 10);
	ST_print(ST);
	qsort(ST.elem, ST.TableLen, sizeof(ElemType), compare);//qsortʵ�ֵ��ǿ���
	ST_print(ST);
	printf("���ֲ��ң�������Ҫ������keyֵ:\n");
	scanf("%d", &key);
	pos = Binary_Search(ST, key);//���ֲ��ң�Ҳ���۰���ҡ�      ����Ҫ�����������������ʵ��
	if (pos != -1)
	{
		printf("���ҳɹ� λ��Ϊ %d\n", pos);
	}
	else {
		printf("����ʧ��\n");
	}
}