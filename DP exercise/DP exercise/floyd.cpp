#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int i, j, k, m;
	int W[5][5], D[5][5];

	for (i = 0; i < 5; i++)
		for (j = 0; j < 5; j++) {
			cin >> W[i][j];
			D[i][j] = W[i][j];
		}

	for (k = 0; k < 5; k++)
		for (i = 0; i < 5; i++)
			for (j = 0; j < 5; j++)
				D[i][j] = min(D[i][j], D[i][k] + D[k][j]);

	cout << endl;

	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++)
			cout << D[i][j] << " ";
		cout << endl;
	}
}

