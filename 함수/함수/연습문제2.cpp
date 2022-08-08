#include<iostream>
using namespace std;

int f(int x);

int main()
{
	int i;
	for (i = 1; i <= 12; i++)
	{
		cout << f(i) << " ";
	}
	cout << endl;

	return 0;
}

int f(int x)
{
	if (x == 1)
		return 1;
	if (x == 2)
		return 1;
	else
		return f(x - 1) + f(x - 2);
}