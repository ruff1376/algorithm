#include<iostream>
using namespace std;

int abs(int x);

int main()
{
	int x;
	cout << "������ �Է��ϼ��� : ";
	cin >> x;
	cout << "������ : " << abs(x) << "�Դϴ�." << endl;

	return 0;
}

int abs(int x)
{
	if (x < 0)
		return -x;
	else
		return x;
}