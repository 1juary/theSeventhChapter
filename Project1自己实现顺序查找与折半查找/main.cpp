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
	ST.elem[0] = key;
	for (int i = ST.TableLen - 1; ST.elem[i] != key; --i)
	return i;
}

//二分查找
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
	return -1;//没有找到
}

int main() {
	SSTable ST;
	ElemType key;
	int pos;//存储查询元素的位置
	
}