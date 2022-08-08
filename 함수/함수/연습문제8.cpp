#include<iostream>
using namespace std;

int sum(int n);

int main()
{
	int n;
	cout << "input your number = ";
	cin >> n;
	cout << "1부터 " << n << "까지의 합 = " << sum(n) << endl;

	return 0;
}

int sum(int n)
{
	if (n == 1)
		return 1;
	else
		return n + sum(n - 1);
}