#include<stdio.h>
int main(void){
	char ch;
	scanf_s("%c", &ch);
	printf("%c ������ ASCII �ڵ� : %d (%x)\n", ch, ch, ch);
	return 0;
}