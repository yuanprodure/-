#include <stdio.h>
#include <stdlib.h>
int main(void){
	int x, y, z;
	for (x = 1; x <= 16; x++){
		for (y = 1; y < 26 - x; y++){
			z = 25 - x - y;
			if (5 * x + 3 * y + z == 80){
				printf("男人%d人，女人%d人，小孩%d人\n");
			}
		}
	}
	printf("无解！\n");
	system("pause");
	return 0;
}