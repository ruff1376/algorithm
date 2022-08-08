#include<iostream>
using namespace std;

int abs(int x);

int main()
{
	int x;
	cout << "정수를 입력하세요 : ";
	cin >> x;
	cout << "절댓값은 : " << abs(x) << "입니다." << endl;

	return 0;
}

int abs(int x)
{
	if (x < 0)
		return -x;
	else
		return x;
}