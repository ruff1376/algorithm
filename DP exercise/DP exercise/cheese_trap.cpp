#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n, m, i, j;
	int p[20][20], maxCheese[20][20] = { 0 };

	cin >> n >> m;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			cin >> p[i][j];

	for (i = n - 2; i >= 0; i--) {
		if (p[i][0] == 0)
			maxCheese[i][0] = maxCheese[i + 1][0];
		if (p[i][0] == 1)
			maxCheese[i][0] = maxCheese[i + 1][0] + 1;
		if (p[i][0] == 2)
			break;
	}

	for (j = 1; j < m; j++) {
		if (p[0][j] == 0)
			maxCheese[0][j] = maxCheese[0][j - 1];
		if (p[0][j] == 1)
			maxCheese[0][j] = maxCheese[0][j - 1] + 1;
		if (p[0][j] == 2)
			break;
	}

	for (i = n - 2; i >= 0; i--) {
		for (j = 1; j < m; j++) {
			if (p[i][j] == 0)
				maxCheese[i][j] = max(maxCheese[i + 1][j], maxCheese[i][j - 1]);
			if (p[i][j] == 1)
				maxCheese[i][j] = max(maxCheese[i + 1][j], maxCheese[i][j - 1]) + 1;
			if (p[i][j] == 2)
				maxCheese[i][j] = -100;
		}
	}

	cout << maxCheese[0][m - 1] << endl;

	return 0;
}