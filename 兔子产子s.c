#include <stdio.h>
#include <stdlib.h>
int Fib2(int month){
	if (month == 1 || month == 2){
		return 2;
	}
	else{
		return Fib2(month - 1) + Fib2(month - 2);
	}
}
int main(void){
	int month;
	printf("请输入您要查询的产子数月份：");
	scanf_s("%d", &month);
	printf("%d月的兔子总数为：  %d\n", month, Fib2(month));
	system("pause");
	return 0;
}