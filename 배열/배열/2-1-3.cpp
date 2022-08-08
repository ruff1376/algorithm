#include<iostream>
using namespace std;

int main()
{
	int i,j,sum=0;
	int garosum[3] = { 0 };
	int serosum[5] = { 0 };
	int array[15] = { 90,78,77,98,98,
					  80,45,67,88,57,
					  88,99,65,55,74 };
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
		{
			garosum[i] += array[5 * i + j];
		}
		cout << "가로" << i+1 << " 합 : " << garosum[i] << endl;
	}
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 3; j++)
		{
			serosum[i] += array[i + 5 * j];
		}
		cout << "세로" << i+1 << " 합 : " << serosum[i] << endl;
	}
	for (i = 0; i < 15; i++)
	{
		sum += array[i];
	}
	cout << "총합 : " << sum << endl;
	return 0;
}