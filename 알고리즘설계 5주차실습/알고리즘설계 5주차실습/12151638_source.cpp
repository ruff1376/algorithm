#include<iostream>
#include<algorithm>
using namespace std;

void heapify(int *a, int h, int m) {
	int v = a[h];
	int j = 2 * h;
	for (; j <= m; j=2*j) {
		if (j < m && a[j] > a[j + 1])
			j=j+1;
		if (v <= a[j])
			break;
		else
			a[j / 2] = a[j];
	}
	a[j / 2] = v;
}

void heapsort(int *a, int n) {
	for (int i = n / 2; i >= 1; i--)
		heapify(a, i, n);
	for (int i = n - 1; i >= 1; i--) {
		int temp = a[1];
		a[1] = a[i + 1];
		a[i + 1] = temp;
		heapify(a, 1, i);
	}
}

int main() {
	int tuna[101];
	int length = 0, amount = 0, ed, j=0, k=0, j0;
	for (int i = 1; ; i++) {
		cin >> ed;
		if (ed >= 20200101) {
			tuna[i] = ed;
			length++;
		}
		if (ed >= 1 && ed <= 20) {
			if (j == 0) {
				heapsort(tuna, length);
				for (j = length; j > length - ed; j--) {
					cout << tuna[j] << endl;
					k++;
					j0 = j;
				}
			}
			else {
				heapsort(tuna, length);
				for (j0 = length - k; j0 > length - k - ed; j0--) {
					cout << tuna[j0] << endl;
					k++;
				}
			}
			/*if (j == 1) {
				amount = ed;
				heapsort(tuna, length);
				for (; j <= amount; j--)
					cout << tuna[j] << endl;
			}
			else {
				heapsort(tuna, length);
				for (j = j + 1; j <= j + 1 + ed; j++)
					cout << tuna[j] << endl;
			}*/
		}
		if (ed == 0) {
			amount = ed;
			break;
		}
	}
	if (amount == 0)
		return 0;
}