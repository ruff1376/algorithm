#include<iostream>
using namespace std;

int main()
{
	int n,a,b,c;
	cout << "3�ڸ� �������� �Է��ϼ��� : ";
	cin >> n;
	a = n / 100;
	b = (n - 100 * a) / 10;
	c = n - 100 * a - 10 * b;
	if (a % 2 == 0)
		cout << a << " : ¦�� ";
	else
		cout << a << " : Ȧ�� ";
	if (b % 2 == 0)
		cout << b << " : ¦�� ";
	else
		cout << b << " : Ȧ�� ";
	if (c % 2 == 0)
		cout << c << " : ¦�� ";
	else
		cout << c << " : Ȧ�� ";
	cout << endl;
	
	return 0;
}