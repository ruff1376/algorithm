#include<iostream>
#include<algorithm>
using namespace std;

int P[1001][10001], p[1001], w[1001];

int main() {
	int i, j, n, W;

	cin >> n >> W;

	for (i = 1; i <= n; i++)
		cin >> p[i] >> w[i];

	for (i = 0; i <= n; i++)
		P[i][0] = 0;

	for (j = 1; j <= W; j++)
		P[0][j] = 0;

	for (i = 1; i <= n; i++)
		for (j = 1; j <= W; j++) {
			if (w[i] <= j)
				P[i][j] = max(P[i - 1][j], p[i] + P[i - 1][j - w[i]]);
			else
				P[i][j] = P[i - 1][j];
		}

	/*for (i = 0; i <= n; i++) {
		for (j = 0; j <= W; j++)
			cout << P[i][j] << " ";
		cout << endl;
	}*/

	cout << P[n][W] << endl;

	return 0;
}