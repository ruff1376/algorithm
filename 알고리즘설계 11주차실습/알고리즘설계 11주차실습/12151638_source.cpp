#include<iostream>
using namespace std;

int max(int a, int b, int c) {
	int m = a;
	if (m < b) m = b;
	if (m < c) m = c;
	return m;
}

int maxp(int batt, int **pch, int **pco, int i, int j) {
	if (i == 0 && j == 0) return batt;
	if (i == 0 && j > 0) {
		if (maxp(batt, pch, pco, 0, j - 1) - pco[i][j] < 0) return maxp(batt, pch, pco, 0, j - 1) - pco[i][j];
		else return maxp(batt, pch, pco, 0, j - 1) - pco[i][j] + pch[i][j];
	}
	if (i > 0 && j == 0) {
		if (maxp(batt, pch, pco, i - 1, 0) - pco[i][j] < 0) return maxp(batt, pch, pco, 0, j - 1) - pco[i][j];
		else return maxp(batt, pch, pco, 0, j - 1) - pco[i][j] + pch[i][j];
	}
	if (i > 0 && j > 0) {
		int d = maxp(batt, pch, pco, i - 1, j - 1) - (int)(pco[i][j] * 1.4);
		int c = maxp(batt, pch, pco, i, j - 1) - pco[i][j];
		int l = maxp(batt, pch, pco, i - 1, j) - pco[i][j];
		if (d < 0) d = -1;
		if (c < 0) c = -1;
		if (l < 0) l = -1;
		return max(d, c, l) + pch[i][j];
	}
}

int main() {
	int batt, col, row, pch[12][16], pco[12][16], i, j;
	cin >> batt >> col >> row;
	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++)
			cin >> pch[i][j];
	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++)
			cin >> pco[i][j];
	cout << maxp(batt, pch, pco, row - 1, col - 1) << endl;
}