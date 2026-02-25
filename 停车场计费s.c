#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(void){
	float hours;
	float fee;
	printf("请输入您要停车的时长(hours)：");
	scanf_s("%f", &hours);
	if (hours < 3.0){
		fee = 2.0;
	}
	else if (hours >= 3.0&&hours < 19.0){
		fee = 2.0 + 0.5*(float)ceil(hours - 3.0);//ceil返回double
		
	}
	else{
		fee = 10.0;
	}
	printf("需要支付%f元", fee);
	system("pause");
	return 0;
}