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
	ST.elem[0] = key;
	for (int i = ST.TableLen - 1; ST.elem[i] != key; --i)
	return i;
}

//���ֲ���
int Binary_Search(SSTable L, ElemType key) {
	int low = 0, high = L.TableLen - 1, mid;
	while (low < high) {
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

int main() {
	SSTable ST;
	ElemType key;
	int pos;//�洢��ѯԪ�ص�λ��
	
}