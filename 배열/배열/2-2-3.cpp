#include<iostream>
using namespace std;

int main()
{
	int i, j;
	int array[9][9];
	for (i = 1; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			array[i][j] = (i+1) * (j+1);
			cout << i+1 << "*" << j+1 << "=" << array[i][j] << endl;
		}
		cout << "----------------" << endl;
	}
	return 0;
}