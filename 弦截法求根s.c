#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// 声明目标函数（待求根的函数）
float f(float x);
// 声明求弦截点的函数
float xpoint(float x1, float x2);
// 声明弦截法求根的核心函数
float root(float x1, float x2);
int main(void){
	float x, x1, x2;
	do{
		printf("输入两个x值，使函数值异号：");
		scanf_s("%f%f", &x1, &x2);
	} while (f(x1)*f(x2) >= 0);
	x=root(x1,x2);
	printf("弦截法求得的根为：%f\n", x);
	system("pause");
	return 0;
}
float f(float x){
	float y = (x*x - 5.0 * x + 16.0)*x - 80.0;
	return y;
}
float xpoint(float x1, float x2){
	float x = (x1*f(x2) - x2*f(x1)) / (f(x2) - f(x1));
	return x;
}
float root(float x1, float x2){
	float x,y,y1;
	
	y1 = f(x1);
	do{
		x = xpoint(x1, x2);
		y = f(x);
		if (y*y1 > 0){//同号
			x1 = x;
			y1 = y;//更新y1,因为在while外
		}
		else{
			x2 = x;//x1没变，所以不用更新y1 !
		}
	} while (fabs(y) > 1e-6);
	return x;
}
