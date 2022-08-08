#include<iostream>
using namespace std;

int plus(int i, int j);
int minus(int i, int j);
int multiply(int i, int j);
float divide(int i, int j);

int main()
{
	int a, b;
	int result;
	double result2;

	cout << "input two numbers : ";
	cin >> a >> b;
	result = plus(a, b);
	cout << "a + b = " << result << endl;
	result = minus(a, b);
	cout << "a - b = " << result << endl;
	result = multiply(a, b);
	cout << "a * b = " << result << endl;
	result2 = divide(a, b);
	cout << "a / b = " << result2 << endl;

	return 0;
}

int plus(int i, int j)
{
	return i + j;
}

int minus(int i, int j)
{
	return i - j;
}

int multiply(int i, int j)
{
	return i * j;
}

float divide(int i, int j)
{
	return (double)i / j;
}