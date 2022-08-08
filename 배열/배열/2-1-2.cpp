#include<iostream>
using namespace std;

int main()
{
	int i,sum=0;
	int student[10];
	for (i = 0; i <= 9; i++)
	{
		cin >> student[i];
	}
	for (i = 0; i <= 9; i++)
		sum += student[i];
	cout << "ÃÑÁ¡ : " << sum << endl << "Æò±Õ : " << (double)sum / 10 << endl;

	return 0;
}