#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(void){
	int i = 100;
	for (; i <= 999; i++){
		int a = i / 100;
		int b = (i - a * 100) / 10;
		int c = i % 10;
		if (pow(a, 3) + pow(b, 3) + pow(c, 3) == i){
			printf("%d是水仙花数\n", i);
		}
	}
	system("pause");
}