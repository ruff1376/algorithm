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
	int n[8][9] = { {3,4,9,-2,2,51,-23,2,-1},
	{223,7,8,-11,5,-99,2,3,-4},
	{2,51,-23,-23,6,3,2,4,5},
	{5,-99,2,-1,32,2,5,-99,2},
	{6,3,3,-4,2,-1,6,3,3},
	{32,2,4,5,3,-4,2,-1,4},
	{4,4,23,6,2,-1,3,-4,34},
	{78,32,1,7,3,-4,-23,-23,6} }, sum[8][9], i, j;

	/*for (i = 0; i < 8; i++)
		for (j = 0; j < 9; j++) {
			cin >> n[i][j];
			if (i == 0)
				sum[i][j] = n[i][j];
		}*/

	for (i = 1; i < 8; i++) {
		for (j = 0; j < 9; j++) {
			if (j == 0)
				sum[i][0] = n[i][0] + max(sum[i - 1][0], sum[i - 1][1]);
			if (j == 8)
				sum[i][8] = n[i][8] + max(sum[i - 1][7], sum[i - 1][8]);
			sum[i][j] = n[i][j] + maxOfThree(sum[i - 1][j - 1], sum[i - 1][j], sum[i - 1][j + 1]);
		}
	}

	int maximum = sum[7][0];
	for (j = 1; j < 9; j++)
		if (maximum < sum[7][j]) maximum = sum[7][j];

	cout << maximum << endl;

	return 0;
}