#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef int ElemType;
typedef struct {
	ElemType *elem;//整型数组，用于创建动态数组
	int TableLen;//存储动态数组中元素的个数
}SSTable;

//初始化数组
void ST_Init(SSTable& ST, int len) {//len是数组的个数
	ST.TableLen = len + 1;//多申请一位，存哨兵
	ST.elem = (ElemType*)malloc(sizeof(ElemType) * ST.TableLen);
	int i;
	srand(time(NULL));//随机数生成
	for (i = 0; i < ST.TableLen; i++) {
		ST.elem[i] = rand() % 100;//填入随机数
	}
}
//暴力搜索某元素
int Search_Seq(SSTable ST, ElemType key) {
	ST.elem[0] = key;                           //让零号元素作为哨兵
	for (int i = ST.TableLen - 1; ST.elem[i] != key; --i)
	return i;
}
//打印数组
void ST_print(SSTable ST) {
	for (int i = 0; i < ST.TableLen; i++) {
		printf("%3d", ST.elem[i]);
	}
	printf("\n");
}
//二分查找
int Binary_Search(SSTable L, ElemType key) {            //每次折半
	int low = 0, high = L.TableLen - 1, mid;
	while (low <= high) {                               //low <= high 能够查找到最后一个元素
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
	return -1;//没有找到
}


int compare(const void* left, const void* right)//left，right是任意两个元素的地址值
{
	return *(ElemType*)left - *(ElemType*)right;
	//return *(ElemType*)right - *(ElemType*)left;//从大到小
}

int main() {
	SSTable ST;
	ElemType key;
	int pos;//存储查询元素的位置
	ST_Init(ST, 10);
	ST_print(ST);
	qsort(ST.elem, ST.TableLen, sizeof(ElemType), compare);//qsort实现的是快排
	ST_print(ST);
	printf("二分查找，请输入要搜索的key值:\n");
	scanf("%d", &key);
	pos = Binary_Search(ST, key);//二分查找，也叫折半查找。      查找要在数组有序的数组中实现
	if (pos != -1)
	{
		printf("查找成功 位置为 %d\n", pos);
	}
	else {
		printf("查找失败\n");
	}
}