#include<stdio.h>
int main(void){
	char ch;
	scanf_s("%c", &ch);
	printf("%c 문자의 ASCII 코드 : %d (%x)\n", ch, ch, ch);
	return 0;
}