#include<iostream>
using namespace std;

int main()
{
	int a, b;
	cout << "�� ���� ������ �Է��ϼ��� : ";
	cin >> a >> b;

	if (a > b)
		cout << "ū ���� " << a << "�Դϴ�." << endl;
	if (a < b)
		cout << "ū ���� " << b << "�Դϴ�." << endl;
	else
		cout << "�� ���� �����ϴ�." << endl;

	return 0;
}