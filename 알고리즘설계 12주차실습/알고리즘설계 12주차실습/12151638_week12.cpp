#include<iostream>
#include<algorithm>
using namespace std;

int W[1001][1001], D[1001][1001], P[1001][1001], start[1000000], en[1000000];

void path(int q, int r) {
	if (P[q][r] != 0) {
		path(q, P[q][r]);
		cout << " " << P[q][r];
		path(P[q][r], r);
	}
}

int main() {
	int i, j, k, n, m, a, b, w, count = 0;
	for (i = 1; i <= 1000; i++) {
		for (j = 1; j <= 1000; j++) {
			W[i][j] = 100000;
			D[i][j] = 100000;
			P[i][j] = 0;
		}
	}

	cin >> n >> m;
	for (i = 1; i <= m; i++) {
		cin >> a >> b >> w;
		W[a][b] = w;
		D[a][b] = W[a][b];
	}

	for (k = 1; k <= n; k++){
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++) {
				if (D[i][k] + D[k][j] < D[i][j]) {
					P[i][j] = k;
					D[i][j] = D[i][k] + D[k][j];
				}
			}
		}
	}

	for (i = 0; ; i++) {
		cin >> start[i];
		if (start[i] == 0) break;
		cin >> en[i];
		count++;
	}

	for (i = 0; i < count; i++) {
		if (D[start[i]][en[i]] == 100000) cout << "0" << endl;
		else {
			cout << D[start[i]][en[i]] << " ";
			cout << start[i];
			path(start[i], en[i]);
			cout << " " << en[i] << endl;
		}
	}

	return 0;
}