#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void exchange(const char* pin, char* pout){
	//拆分单词并将以A开头或以N结尾的的单词放入相应的列表中
	char words[100][100];
	char A_words[100][100];
	char N_words[100][100];
	int wordscount = 0, A_count = 0, N_count = 0;
	const char* start = pin;
	while (*start != '\0'){
		//跳过空格
		while (*start == ' '&& *start != '\0') start++;
		const char* end = start;
		while (*end != '\0'&&*end != ' ') end++;//找到单词末尾
		strncpy_s(words[wordscount++], sizeof(words[0]),start, end - start);
		words[wordscount][end - start] = '\0';// !strncpy不会自动加结束符'\0'
		//分类
		if (*start == 'A'){
			strncpy_s(A_words[A_count++], sizeof(A_words[0]),start, end - start);
		}
		else if (*(end - 1) == 'N'){
			strncpy_s(N_words[N_count++], sizeof(N_words[0]),start, end - start);
		}
		start = end;//寻找下一个单词  ！并且地址可以改，但start以及end指向的内容不可以修改，因为const规定只读（地址可以变，内容不能变）
	}
	//替换单词
	int a_idx = 0, n_idx = 0;
	for (int i = 0; i < wordscount; i++){
		int len = strlen(words[i]);
		if (*words[i] == 'A'&&n_idx < N_count){
			strcpy_s(words[i],sizeof(N_words[0]), N_words[n_idx++]);
		}
		else if (*(words[i] + len - 1) == 'N'&&a_idx < A_count){
			strcpy_s(words[i], sizeof(A_words[0]), A_words[a_idx++]);
		}
	}
	//重新拼接
	pout[0] = '\0'; //strcat()从 pout 末尾的 \0 开始拼接字符串，如果 pout 没有 \0，strcat 会一直找内存，直到找到 \0（内存越界，程序崩溃 / 乱码）。
	for (int i = 0; i < wordscount; i++){
		strcat_s(pout, strlen(pout) + strlen(words[i]) + 2, words[i]); //strcat() 执行后，pout 指针本身的地址不会变，但它指向的缓冲区内容末尾会自动新增 \0，下次 strcat 会从这个新的 \0 位置继续拼接。
		if (i != wordscount - 1){
			strcat_s(pout, strlen(pout) + 2, " ");// strcat() 要求第二个参数是以 \0 结尾的字符串，传单个字符会触发未定义行为。
		}
	}
}
int main(void){
	const char* pin = "AM I OLDER THAN YOU";
	char output[100];
	exchange(pin, output);
	printf("输出：%s", output);
	system("pause");
	return 0;
}