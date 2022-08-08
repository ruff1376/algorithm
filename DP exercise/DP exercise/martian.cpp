#include<iostream>
#include<algorithm>
using namespace std;

int maxOfThree(int a, int b, int c) {
	int m = a;
	if (m < b) m = b;
	if (m < c) m = c;
	return m;
}

int main() {
	int batt, col, row, pch[12][16], pco[12][16], p[12][16], i, j;
	cin >> batt >> col >> row;

	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++)
			cin >> pch[i][j];
	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++)
			cin >> pco[i][j];

	p[0][0] = batt;

	for (i = 1; i < row; i++) {
		if (p[i - 1][0] - pco[i][0] < 0) break;
		p[i][0] = p[i - 1][0] - pco[i][0] + pch[i][0];
		if (p[i][0] > batt) p[i][0] = batt;
	}

	for (j = 1; j < col; j++) {
		if (p[0][j - 1] - pco[0][j] < 0) break;
		p[0][j] = p[0][j - 1] - pco[0][j] + pch[0][j];
		if (p[0][j] > batt) p[0][j] = batt;
	}

	for (i = 1; i < row; i++) {
		for (j = 1; j < col; j++) {
			p[i][j] = maxOfThree(p[i - 1][j] - pco[i][j] + pch[i][j], p[i][j - 1] - pco[i][j] + pch[i][j], p[i - 1][j - 1] - pco[i][j] * 1.4 + pch[i][j]);
			if (p[i][j] > batt) p[i][j] = batt;
		}
	}

	cout << p[row - 1][col - 1] << endl;

	return 0;
}