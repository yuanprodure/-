#include <stdio.h>
#include <stdlib.h>
void input(int n, int m, int xs[], float fs[][20], float ds[]);
void sort(int xs[],float ds[], int n);
void print(int xs[],float ds[], int n);
int main(void){
	int n, m;
	int xs[40];
	float fs[40][20], ds[40];
	printf("请输入选手数：");
	scanf_s("%d", &n);
	printf("请输入评委数：");
	scanf_s("%d", &m);
	//输入数据
	input(n, m, xs, fs, ds);
	//排序
	sort(xs,ds, n);
	//输出名次
	print(xs,ds, n);
	system("pause");
}
void input(int n, int m, int xs[], float fs[][20], float ds[]){
	for (int i = 1; i <= n; i++){
		printf("选手%d的id：",i);
		scanf_s("%d", &xs[i]);
		ds[i] = 0.0;
		int max = 0, min = 1000;
		for (int j = 1; j <= m; j++){
			printf("请评委%d输入分数：",j);
			scanf_s("%f", &fs[i][j]);
			if (max < fs[i][j]){
				max = fs[i][j];
			}
			if (min>fs[i][j]){
				min = fs[i][j];
			}
			ds[i] += fs[i][j];
			printf("\n");
		}
		ds[i] = (ds[i] - max - min) / (m - 2);
	}
}
void sort(int xs[], float ds[], int n){
	for (int i = 1; i < n; i++){
		int flag = 1;
		for (int j = 1; j<=n - i; j++){
			if (ds[j]<ds[j + 1]){
				flag = 0;
				//分数排序
				float temp = ds[j];
				ds[j] = ds[j + 1];
				ds[j + 1] = temp;
				//id变换
				int tem = xs[j];
				xs[j] = xs[j + 1];
				xs[j + 1] = tem;
			}
		}
		if (flag) break;
	}
}
void print(int xs[],float ds[], int n){
	for (int i = 1; i <= n; i++){
		printf("第%d名id：%-6d,得分：%6.2f\n", i, xs[i], ds[i]);
	}
}