#include<iostream>
using namespace std;

int main()
{
	int i, j;
	int array1[4][3] = { 23,75,85,12,77,51,25,66,30,19,90,88 };
	int array2[4][3] = { 11,15,47,74,85,69,57,86,28,90,22,33 };
	int sum[4][3];
	int rem[4][3];
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 3; j++)
		{
			sum[i][j] = array1[i][j] + array2[i][j];
			rem[i][j] = array1[i][j] - array2[i][j];
		}
	}
	cout << "ÇÕ" << endl;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 3; j++)
		{
			cout << sum[i][j] << " ";
		}
		cout << endl;
	}
	cout << "Â÷" << endl;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 3; j++)
		{
			cout << rem[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}