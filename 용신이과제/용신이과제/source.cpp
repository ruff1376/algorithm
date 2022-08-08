#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//#include<iostream>
//using namespace std;

/*void medianOfThreeQuickSort(int *S, int l, int r) {
	int i, j, m, pivot;
	if (r - l > 1) {
		m = (l + r) / 2;
		if (S[l] > S[m]) swap(S[l], S[m]);
		if (S[l] > S[r]) swap(S[l], S[r]);
		if (S[m] > S[r]) swap(S[m], S[r]);
		swap(S[m], S[r - 1]);
		pivot = S[r - 1]; i = l; j = r - 1;
		for (;;) {
			while (S[++i] < pivot);
			while (S[--j] < pivot);
			if (i >= j) break;
			swap(S[i], S[j]);
		}
		swap(S[i], S[r - 1]);
		medianOfThreeQuickSort(S, l, i - 1);
		medianOfThreeQuickSort(S, i + 1, r);
	}
	else if (S[l] > S[r]) swap(S[l], S[r]);
}*/

/*void sumdiffmult(int x, int y, int *sum, int *diff, int *mult) {
	*sum = x + y;
	*diff = x - y;
	*mult = x * y;
}*/

int main() {
	int x, y, sum, diff, mult, *p, *q;
	printf("숫자 입력: ");
	scanf_s("%d %d", &x, &y);
	p = &x; q = &y;
	sum = *p + *q; diff = *p - *q; mult = *p * *q;
	printf("합: %d 차: %d 곱: %d\n", sum, diff, mult);
	printf("%d의 메모리주소: (%d)\n", x, p);
	printf("%d의 메모리주소: (%d)\n", y, q);

	return 0;
}