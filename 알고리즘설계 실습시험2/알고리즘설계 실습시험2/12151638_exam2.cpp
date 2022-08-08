#include<iostream>
using namespace std;

int a[500], b[500];

int abs(int n) {
	if (n < 0) return -n;
	else return n;
}

int gcd(int x, int y) {
	while (y != 0) {
		int t = x % y;
		x = y;
		y = t;
	}
	return x;
}

int lcm(int x, int y) {
	return x * y / gcd(x, y);
}

int main() {
	int n, i, j, x[500] = { 0 }, sum = 0, ab[500], LCM, index, count = 0;
	bool isplus[500];
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> a[i] >> b[i];
	for (i = 0; i < n; i++) {
		if (a[i] < b[i] || a[i] > b[i]) count++;
	}
	if (count == n) {
		cout << -1 << endl;
		return 0;
	}
	else {

		for (i = 0; i < n; i++) {
			ab[i] = abs(a[i] - b[i]);
			if (a[i] == b[i]) ab[i] = 1;
			if (a[i] - b[i] > 0) isplus[i] = true;
			else isplus[i] = false;
		}

		LCM = lcm(ab[0], ab[1]);

		if (n >= 3) {
			for (i = 2; i < n; i++)
				LCM = lcm(LCM, ab[i]);
		}

		/*for (i = 0; i < n; i++)
			if (a[i] == b[i]) ab[i] = 0;*/

		for (i = 0; i < n; i++)
			x[i] = LCM / ab[i];
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++) {
				if (a[i] - b[i] == a[j] - b[j] && a[i] != b[i]) {
					if (a[i] < a[j]) {
						index = i;
						x[j] = 0;
					}
				}
			}
		for (i = 0; i < n; i++)
			sum += x[i] * a[i];
		cout << sum << endl;
		return 0;
	}
}