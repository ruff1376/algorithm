#include<iostream>
using namespace std;

int main()
{
	int i,j;
	int gugudan[9];
	cout << "2�̻� 9������ �ڿ����� �Է��ϼ��� : ";
	cin >> i;
	for (j = 0; j < 9; j++)
	{
		gugudan[j] = i * (j + 1);
		cout << i << "*" << j + 1 << "=" << gugudan[j] << endl;
	}
	return 0;
}