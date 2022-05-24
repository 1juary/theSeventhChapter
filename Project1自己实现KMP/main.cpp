#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char* SString;

//����ƥ�䷨
int Index(SString S, SString T) {
	int i, j = 1;//0λ�������鳤��
	while (i <= S[0] && j <= T[0]) {
		if (S[j] == T[j]) {
			++i; ++j;
		}
		else {
			i = i - j + 2;          // ָ����˵ķ�ʽ������Ҫ
			j = 1;                 //ָ����ˣ�����ƥ��
		}
	}
	if (j > T[0]) {
		return i - T[0];//ƥ�俪ʼ��λ��
	}
	else
		return 0;
}

//KMP�㷨��Ѱ��next������㷨

void Get_Next(char T[], int next[]) {//next[]��ָ�룬������ǵ�ַ�����Ըı�
	int i = 1;
	int j = 0;
	next[1] = 0;//��Ϊ0
	while (i < T[0]) {
		if (j == 0 || T[i] == T[j]) {
			++i; ++j;
			next[i] = j;//��¼�����ظ���λ��
		}
		else {
			j = next[j];//����ͬ���Ҹ�λ�����±Ƚ�
		}
	}
}

//KMP�㷨
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
	if (j > T[0]) { //�ҵ���Ӧ���ַ���
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