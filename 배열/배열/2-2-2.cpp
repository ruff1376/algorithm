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
			cout << i + 1 << "�� " << j + 1 << "ȣ�� ������ �� ���Դϱ�? : ";
			cin >> array[i][j];
			sum += array[i][j];
		}
	}
	cout << "��������Ʈ �� �ֹμ��� " << sum << "���Դϴ�." << endl;
	return 0;
}