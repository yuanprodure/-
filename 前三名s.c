#include <stdio.h>
#include <stdlib.h>
typedef struct sportman{
	int num;
	float score;
}sm;
void input(sm member[], int n);
void sort(sm member[], int n);
void print(sm member[], int n);
int main(void){
	int n;
	printf("请输入运动员人数(n>3)：");
	scanf_s("%d", &n);
	sm member[15];
	input(member, n);
	sort(member, n);
	print(member, n);
	system("pause");
	return 0;
}
void input(sm member[], int n){
	for (int i = 0; i < n; i++){
		printf("请输入运动员%d的号码：", i + 1);
		scanf_s("%d", &member[i].num);
		printf("请输入运动员%d的成绩：", i + 1);
		scanf_s("%f", &member[i].score);
	}
}
void sort(sm member[], int n){
	for (int i = 0; i < n - 1; i++){
		int flag = 1;
		for (int j = 0; j < n - i - 1; j++){
			if (member[j].score < member[j + 1].score){
				sm tem = member[j];
				member[j] = member[j + 1];
				member[j + 1] = tem;
				flag = 0;
			}
		}
		if (flag) break;
	}
}
void print(sm member[], int n){
	for (int i = 0; i < 3; i++){
		printf("第%d名号码是：%-6d，成绩是：%-6f\n",i+1,member[i].num, member[i].score);
	}
}

