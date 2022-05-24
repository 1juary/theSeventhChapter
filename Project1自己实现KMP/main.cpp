#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char* SString;

//暴力匹配法
int Index(SString S, SString T) {
	int i, j = 1;//0位存了数组长度
	while (i <= S[0] && j <= T[0]) {
		if (S[j] == T[j]) {
			++i; ++j;
		}
		else {
			i = i - j + 2;          // 指针后退的方式，很重要
			j = 1;                 //指针后退，重新匹配
		}
	}
	if (j > T[0]) {
		return i - T[0];//匹配开始的位置
	}
	else
		return 0;
}

//KMP算法，寻找next数组的算法

void Get_Next(char T[], int next[]) {//next[]是指针，传入的是地址，可以改变
	int i = 1;
	int j = 0;
	next[1] = 0;//恒为0
	while (i < T[0]) {
		if (j == 0 || T[i] == T[j]) {
			++i; ++j;
			next[i] = j;//记录出现重复的位置
		}
		else {
			j = next[j];//不相同，找个位置重新比较
		}
	}
}

//KMP算法
int kmp(char S[], char T[], int next[], int pos) {
	int i = pos;
	int j = 1;
	while (i <= S[0] && j <=T[0]) {
		if (j == 0 || S[i] == T[i]) {
			++i;
			++j;
		}else {
			j = next[j];
		}
	}
	if (j > T[0]) { //找到相应的字符串
		return i - T[0];
	}
	else
		return 0;
}
int main() {
	char s[256];
	char T[10];
	int next[10];
	int pos;
	s[0] = strlen("abcabaaabaabcac");
	strcpy(s + 1, "abcabaaabaabcac");
	T[0] = strlen("abaaaba");
	strcpy(T + 1, "abaaaba");
	
}