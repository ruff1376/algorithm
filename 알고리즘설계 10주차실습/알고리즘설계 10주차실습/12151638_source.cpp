#include<iostream>
using namespace std;

int isCheeseOrTrap(int obstacle[][20], int n, int m) {
	if (obstacle[n][m] == 1) return 1;
	if (obstacle[n][m] == 2) return 2;
}

int main() {
	int n, m, i, j;
	cin >> n >> m;
	int obstacle[20][20] = { 0 };
	for (j = m - 1; j >= 0; j--)
		for (i = 0; i < n; i++)
			cin >> obstacle[i][j];
	i = 0; j = 0;
	//int max[20][20] = { 0 };
	int max = 0;
	for (; i < n; i++) {
		for (; j < m; j++) {
			if (obstacle[i + 1][j] == 1) {

			}
			
			/*if (isCheeseOrTrap(obstacle, i, j) == 1) {
				int i2 = i, j2 = j;
				for (; i2 < n; i2++)
					for (; j2 < m; j2++)
						max[i2][j2]++;
			}
			if (isCheeseOrTrap(obstacle, i, j + 1) == 2) break;
			else if (isCheeseOrTrap(obstacle, i + 1, j) == 1) {
				i++; break;
			}*/
		}
		/*if (isCheeseOrTrap(obstacle, i, j) == 1) {
			int i2 = i, j2 = j;
			for (; i2 < n; i2++)
				for (; j2 < m; j2++)
					max[i2][j2]++;
		}
		if (isCheeseOrTrap(obstacle, i + 1, j) == 2) j++;
		else if (isCheeseOrTrap(obstacle, i, j + 1) == 1) {
			j++;
		}*/
	}
	cout << max << endl;
	return 0;
}