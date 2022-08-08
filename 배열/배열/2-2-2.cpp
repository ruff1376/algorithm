#include<iostream>
using namespace std;

int main()
{
	int i, j, sum=0;
	int array[3][3];
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			cout << i + 1 << "층 " << j + 1 << "호의 가족은 몇 명입니까? : ";
			cin >> array[i][j];
			sum += array[i][j];
		}
	}
	cout << "열혈아파트 총 주민수는 " << sum << "명입니다." << endl;
	return 0;
}