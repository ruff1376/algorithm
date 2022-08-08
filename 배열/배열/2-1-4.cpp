#include<iostream>
using namespace std;

int main()
{
	int i,j;
	int gugudan[9];
	cout << "2이상 9이하의 자연수를 입력하세요 : ";
	cin >> i;
	for (j = 0; j < 9; j++)
	{
		gugudan[j] = i * (j + 1);
		cout << i << "*" << j + 1 << "=" << gugudan[j] << endl;
	}
	return 0;
}