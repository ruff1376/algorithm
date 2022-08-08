#include<iostream>
using namespace std;

int main()
{
	int a, b;
	cout << "두 개의 정수를 입력하세요 : ";
	cin >> a >> b;

	if (a > b)
		cout << "큰 수는 " << a << "입니다." << endl;
	if (a < b)
		cout << "큰 수는 " << b << "입니다." << endl;
	else
		cout << "두 수는 같습니다." << endl;

	return 0;
}