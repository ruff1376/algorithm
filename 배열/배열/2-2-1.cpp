#include<iostream>
using namespace std;

int main()
{
	int i, j;
	int array1[2][4] = { 1,2,3,4,5,6,7,8 };
	int array2[4][2];
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 2; j++)
		{
			array2[i][j] = array1[1 - j][i];
			cout << array2[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}