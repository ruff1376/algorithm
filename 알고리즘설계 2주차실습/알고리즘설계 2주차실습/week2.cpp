#include<iostream>
#include<cmath>
using namespace std;

int fact(int n)
{
	if (n == 0)
		return 1;
	else
		return fact(n - 1)*n;
}
int numOfMax(int x, int y)
{
	
}

int numOfTeam(int x, int y)
{

}

int main()
{
	int a, b, c, d=0, com, max;
	cin >> a;
	cin >> b;
	int arr1[500];
	int arr2[10][50];
	com = fact(a) / fact(b) / fact(a - b);
	for (int i = 0; i < a; i++)
		cin >> arr1[i];
	for (int j = 0; j < com; j++)
	{

	}
	/*for (int j = 0; j < a-1; j++)
	{
		for (int k = j + 1; k < a; k++)
		{
			c=arr1[j] + arr1[k];
			while (c != 0)
			{
				if (c % 10 != 0)
					d++;
			}
			arr2[j][k] = d;
			d = 0;
		}
	}
	for (int j = 0; j < a - 1; j++)
	{
		for (int k = j + 1; k < a; k++)
		{

			while (b != 0)
			{
				if (arr2[j][k] == b)
					break;
				else
					b--;
			}
		}
	}*/


	cout

	return 0;
}