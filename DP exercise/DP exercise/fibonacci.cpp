#include<iostream>
#include<algorithm>
using namespace std;

int fib(int n) {
	int *f = new int[n];
	f[0] = 0;
	if (n > 0) {
		f[1] = 1;
		for (int i = 2; i <= n; i++)
			f[i] = f[i - 1] + f[i - 2];
	}
	return f[n];
}

int main() {
	cout << fib(5) << endl;

	return 0;
}